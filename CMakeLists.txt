cmake_minimum_required(VERSION 3.5)

enable_language(C)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)

if(POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
endif()

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

project(cc_rpc VERSION 0.0.1 LANGUAGES CXX)

#add doxygen documentation
find_package(Doxygen
             REQUIRED dot)
find_program(EPSTOPDF NAMES epstopdf )
find_program(PDFLATEX NAMES pdflatex )
find_program(MAKEINDEX NAMES makeindex )

set(DOXYGEN_HAVE_DOT YES)
set(DOXYGEN_GENERATE_LATEX YES)
set(DOXYGEN_PLANTUML_JAR_PATH /opt/local/share/java/plantuml/plantuml.jar)
#${CMAKE_CURRENT_SOURCE_DIR}/tools/plantuml-lgpl-1.2024.5.jar)
#set(DOXYGEN_PLANTUML_JAR_PATH {CMAKE_CURRENT_SOURCE_DIR}/tools/plantuml-1.2023.2.jar)

add_subdirectory(doc)

# add the executables
add_library(example_client src/interfaces.hpp src/example_client.hpp src/example_client.cpp)
add_library(example_server src/interfaces.hpp src/example_server.cpp)

add_executable(client src/client_main.cpp)
target_link_libraries(client PRIVATE example_client)

add_executable(server src/server_main.cpp)
target_link_libraries(server PRIVATE example_server)

#add_library(cc_rpc_common src/interfaces.hpp)

#add_subdirectory(src)

