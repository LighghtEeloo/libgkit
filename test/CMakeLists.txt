set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/test)

find_package(SDL3 REQUIRED)

# build core tests
file(GLOB_RECURSE CORE_TEST_SRCS 
    "core/*.cpp"
)

foreach(test_file ${CORE_TEST_SRCS})
    get_filename_component(FILE_BASE_NAME ${test_file} NAME_WE)
    add_executable(${FILE_BASE_NAME} ${test_file} $<TARGET_OBJECTS:gkit_core>)
    add_dependencies(${FILE_BASE_NAME} ${CORE})
    target_link_libraries(${FILE_BASE_NAME} PRIVATE SDL3::SDL3)
endforeach()

# build c-abi tests
if (DEFINED EXPORT_C_ABI AND EXPORT_C_ABI EQUAL true) 
    file(GLOB_RECURSE CABI_TEST_SRCS 
        "c_abi/*.cpp"
    )

    foreach(test_file ${CORE_TEST_SRCS})
        get_filename_component(FILE_BASE_NAME ${test_file} NAME_WE)
        add_executable(${FILE_BASE_NAME} ${test_file} $<TARGET_OBJECTS:gkit_c_abi>)
        add_dependencies(${FILE_BASE_NAME} ${CORE})
        target_link_libraries(${FILE_BASE_NAME} PRIVATE SDL3::SDL3)
    endforeach()
endif()
