##########################################################################
# Copyright (c) 2023, King Abdullah University of Science and Technology
# All rights reserved.
# Template project is an R  Template package provided by the STSDS group at KAUST
##########################################################################

add_subdirectory(data-units)

# Add Template library for Testing CPP using all C/C++ Code

set(
        NEW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/DataTypeModule.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/RcppExports.cpp
        ${SOURCES}
        ${NEW_SOURCES}

)

add_library(template
        SHARED
        ${NEW_SOURCES}
        )


target_link_libraries(template ${LIBS})


install(TARGETS mpcr DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
target_compile_definitions(mpcr PUBLIC CONFIG_FILES_DIR="${CMAKE_CONFIG_PREFIX}")

