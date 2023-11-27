
##########################################################################
# Copyright (c) 2023, King Abdullah University of Science and Technology
# All rights reserved.
# Template project is an R  Template package provided by the STSDS group at KAUST
##########################################################################

set(TESTFILES test_main.cpp)


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/data-units)



enable_testing()
add_executable(system-tests ${TESTFILES})
target_link_libraries(system-tests template)

target_compile_definitions(system-tests PUBLIC TEST_FILES_DIR="${CMAKE_TEST_PREFIX}")
