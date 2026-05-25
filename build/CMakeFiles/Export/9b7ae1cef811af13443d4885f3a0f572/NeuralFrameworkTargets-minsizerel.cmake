#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "NeuralFramework::neuralframework" for configuration "MinSizeRel"
set_property(TARGET NeuralFramework::neuralframework APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(NeuralFramework::neuralframework PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/neuralframework.lib"
  )

list(APPEND _cmake_import_check_targets NeuralFramework::neuralframework )
list(APPEND _cmake_import_check_files_for_NeuralFramework::neuralframework "${_IMPORT_PREFIX}/lib/neuralframework.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
