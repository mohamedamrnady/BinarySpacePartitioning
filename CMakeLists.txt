cmake_minimum_required(VERSION 3.10)
project(BSPProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall -Wextra -pedantic)
elseif(MSVC)
    add_compile_options(/W4)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    src/Point.cpp
    src/BSPNode.cpp
    src/bsp_core.cpp
    src/input_parser.cpp
    src/bsp_query.cpp
    src/bsp_visualize.cpp
    src/main.cpp
)

add_executable(bsp_project ${SOURCES})

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

add_custom_target(test_all
    COMMAND ${CMAKE_COMMAND} -E echo "=== Test Case 1 ==="
    COMMAND $<TARGET_FILE:bsp_project> ${CMAKE_BINARY_DIR}/data/test_case_1.txt
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo "=== Test Case 2 ==="
    COMMAND $<TARGET_FILE:bsp_project> ${CMAKE_BINARY_DIR}/data/test_case_2.txt
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo "=== Test Case 3 ==="
    COMMAND $<TARGET_FILE:bsp_project> ${CMAKE_BINARY_DIR}/data/test_case_3.txt
    DEPENDS bsp_project
    COMMENT "Running all test cases"
)

install(TARGETS bsp_project DESTINATION bin)
install(DIRECTORY data/ DESTINATION share/bsp_project/data)
