##########################################################################
# Copyright (c) 2023, King Abdullah University of Science and Technology
# All rights reserved.
# Template project is an R  Template package provided by the STSDS group at KAUST
##########################################################################

# Set minimum cmake version
cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0048 NEW)

# Project Name and Version
project(Template VERSION 1.0.0)


# Set C++ standard to C++11.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


message(${CMAKE_INSTALL_PREFIX})

# definitions
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(${CMAKE_INSTALL_PREFIX})
    set(CMAKE_INSTALL_PREFIX "/usr")
endif ()

# Set cmake path module.
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)


# Find R and Rcpp using FindR Module
FIND_PACKAGE(R REQUIRED)
if (${R_FOUND})
    message(STATUS "Using R technology")
    list(APPEND LIBS "R")
    set(USE_R ON)
    add_definitions(-DUSING_R)
endif ()


# Defining a macro to differentiate R from C++ calls.
# Ex: printing can be std::cout if you're running C++ or Rcpp::Rcout if you're running the package in R.
if (${RUNNING_CPP})
    add_definitions(-DRUNNING_CPP)
endif ()


# Add Include DIRS
include_directories(${CMAKE_SOURCE_DIR}/inst/include)

# Add src Directory to expose added libraries


# Options
option(TEMPLATE_BUILD_TESTS "Option to enable building tests" OFF)

add_subdirectory(src)

message("Installation path : ${CMAKE_INSTALL_PREFIX}")
message("Building Template tests : ${TEMPLATE_BUILD_TESTS}")


if (TEMPLATE_BUILD_TESTS)
    include_directories(${CMAKE_SOURCE_DIR}/prerequisites)
    add_subdirectory(tests/cpp-tests)
    # Add the system test.
    include(CTest)
    add_test(NAME System-Tests
            COMMAND system-tests
            )
endif ()



