cmake_minimum_required(VERSION 3.1)
project(libfw_core)

include("cmake/utilities.cmake")

set(libfw_core_include_dir "include")

# header only library
add_library(fw_core INTERFACE)
target_include_directories(fw_core INTERFACE ${libfw_core_include_dir})