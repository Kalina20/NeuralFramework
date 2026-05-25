cmake_minimum_required(VERSION 3.16)
project(NeuralFramework VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
option(BUILD_EXAMPLES "Build example applications" ON)

add_library(neuralframework STATIC
    Matrix.cpp
    Dense.cpp
    Activation.cpp
    Loss.cpp
    Model.cpp
)

add_library(NeuralFramework::neuralframework ALIAS neuralframework)

target_include_directories(neuralframework
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/NeuralFramework>
)

set_target_properties(neuralframework PROPERTIES
    OUTPUT_NAME neuralframework
)

if(BUILD_EXAMPLES)
    add_executable(neuralframework_example
        examples/main.cpp
    )
    target_link_libraries(neuralframework_example PRIVATE neuralframework)
endif()

install(TARGETS neuralframework
    EXPORT NeuralFrameworkTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES
    Activation.h
    Dense.h
    Layer.h
    Loss.h
    Matrix.h
    Model.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/NeuralFramework
)

install(EXPORT NeuralFrameworkTargets
    NAMESPACE NeuralFramework::
    FILE NeuralFrameworkTargets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/NeuralFramework
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/NeuralFrameworkConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/NeuralFrameworkConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/NeuralFramework
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/NeuralFrameworkConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/NeuralFrameworkConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/NeuralFrameworkConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/NeuralFramework
)

install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/NeuralFramework
)
