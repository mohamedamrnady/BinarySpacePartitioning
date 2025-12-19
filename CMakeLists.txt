cmake_minimum_required(VERSION 3.19)
project(BSPProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools PrintSupport)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall -Wextra -pedantic)
elseif(MSVC)
    add_compile_options(/W4)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -pedantic)
endif()

qt_standard_project_setup()

qt_add_executable(BSPProject
    WIN32 MACOSX_BUNDLE

    main.cpp

    src/mainwindow.cpp
    src/Point.cpp
    src/BSPNode.cpp
    src/bsp_core.cpp
    src/input_parser.cpp
    src/bsp_query.cpp
    src/bsp_visualize.cpp

    include/mainwindow.h
    include/BSPNode.h
    include/bsp_core.h
    include/bsp_query.h
    include/bsp_visualize.h
    include/input_parser.h
    include/Point.h

    src/mainwindow.ui
    src/qcustomplot.cpp
    include/qcustomplot.h
    build/Qt_6_10_1_for_macOS-Debug/BSPProject_autogen/include/ui_mainwindow.h
)

target_include_directories(BSPProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Create executable
#add_executable(bsp_project ${SOURCES})

qt_add_translations(
    TARGETS BSPProject
    TS_FILES BinarySpacePartitioningGUI_en_US.ts
)

target_link_libraries(BSPProject
    PRIVATE
    Qt::Core
    Qt::Widgets
    Qt::PrintSupport
)

include(GNUInstallDirs)

install(TARGETS BSPProject
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET BSPProject
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

# Custom targets for testing
#add_custom_target(test_all
#    COMMAND ${CMAKE_COMMAND} -E echo "=== Test Case 1 ==="
#    COMMAND $<TARGET_FILE:bsp_project> ${CMAKE_BINARY_DIR}/data/test_case_1.txt
#    COMMAND ${CMAKE_COMMAND} -E echo ""
#    COMMAND ${CMAKE_COMMAND} -E echo "=== Test Case 2 ==="
#    COMMAND $<TARGET_FILE:bsp_project> ${CMAKE_BINARY_DIR}/data/test_case_2.txt
#    COMMAND ${CMAKE_COMMAND} -E echo ""
#    COMMAND ${CMAKE_COMMAND} -E echo "=== Test Case 3 ==="
#    COMMAND $<TARGET_FILE:bsp_project> ${CMAKE_BINARY_DIR}/data/test_case_3.txt
#    DEPENDS bsp_project
#    COMMENT "Running all test cases"
#)

install(SCRIPT ${deploy_script})
