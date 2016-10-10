cmake_minimum_required(VERSION 3.1)
project(libfw_core)

include("cmake/utilities.cmake")

set(libfw_core_include_dir "include")

fw_get_include_files(${libfw_core_include_dir} libfw_core_include_files)
fw_process_include_files(${libfw_core_include_files})

# header only library
add_library(fw_core ${libfw_core_include_files})
fw_process_assembly(fw_core)
set_target_properties(fw_core PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(fw_core PUBLIC ${libfw_core_include_dir})