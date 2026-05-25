vcpkg_from_path(
    OUT_SOURCE_PATH SOURCE_PATH
    PATH "${CMAKE_CURRENT_LIST_DIR}/../../.."
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_install()

vcpkg_cmake_config_fixup(
    PACKAGE_NAME NeuralFramework
    CONFIG_PATH lib/cmake/NeuralFramework
)

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

file(INSTALL
    "${SOURCE_PATH}/LICENSE"
    DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}"
    RENAME copyright
)
