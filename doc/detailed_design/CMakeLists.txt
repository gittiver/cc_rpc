set(DOXYGEN_PROJECT_NAME "Detailed Design - cc_rpc")
#set(DOXYGEN_USE_MDFILE_AS_MAINPAGE mainpage.md)
set(DOXYGEN_PLANTUML_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

set(DOC_TARGET_NAME detailed_design)

doxygen_add_docs( ${DOC_TARGET_NAME}
  .
  ${CMAKE_CURRENT_SOURCE_DIR}/../../src
                  ALL
                  COMMENT "Generate ${DOXYGEN_PROJECT_NAME}"
)

add_custom_target( ${DOC_TARGET_NAME}_pdf
                   ALL
                   COMMENT "Generating ${DOXYGEN_PROJECT_NAME} pdf"
                   COMMAND ${PDFLATEX}  -shell-escape refman.tex
                   COMMAND ${MAKEINDEX} refman.idx
                   COMMAND ${PDFLATEX}  -jobname ${DOC_TARGET_NAME} 
                                        -shell-escape refman.tex
                   DEPENDS ${DOC_TARGET_NAME}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/latex
)
