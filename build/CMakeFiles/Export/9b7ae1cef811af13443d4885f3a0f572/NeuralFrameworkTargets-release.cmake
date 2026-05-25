#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "NeuralFramework::neuralframework" for configuration "Release"
set_property(TARGET NeuralFramework::neuralframework APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(NeuralFramework::neuralframework PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/neuralframework.lib"
  )

list(APPEND _cmake_import_check_targets NeuralFramework::neuralframework )
list(APPEND _cmake_import_check_files_for_NeuralFramework::neuralframework "${_IMPORT_PREFIX}/lib/neuralframework.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
