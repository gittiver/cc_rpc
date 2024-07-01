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

add_subdirectory(doc)

# add the executables
add_library(rpc_client src/rpc_client/cc_rpc_client.cpp src/rpc_client/cc_rpc_client.hpp src/rpc_client/rpc_client_tranport.cpp src/rpc_client/rpc_client_tranport.hpp)
#add_library(example_server src/example_interface.hpp)

add_executable(client src/client_main.cpp
        src/example_rpc_client.cpp)
target_link_libraries(client PRIVATE rpc_client)

add_executable(server src/server_main.cpp)
#target_link_libraries(server PRIVATE example_server)

#add_library(cc_rpc_common src/interfaces.hpp)

#add_subdirectory(src)

