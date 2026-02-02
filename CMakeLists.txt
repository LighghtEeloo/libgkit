cmake_minimum_required(VERSION 3.40)

project(gkit C CXX)

include(cmake/common.cmake)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/core/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/c_abi/include/)

# build core
set (GKIT_OBJS $<TARGET_OBJECTS:gkit_core>)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/core)

# build c_abi
if (DEFINED EXPORT_C_ABI AND EXPORT_C_ABI EQUAL true)
    list (APPEND GKIT_OBJS $<TARGET_OBJECTS:gkit_c_abi>)
    add_subdirectory(${CMAKE_SOURCE_DIR}/src/c_abi)
endif() # ENABLE_C_ABI

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()

add_library(${PROJECT_NAME} 
    ${GKIT_OBJS}
)

add_library(${PROJECT_NAME}_static STATIC 
    ${GKIT_OBJS}
)
