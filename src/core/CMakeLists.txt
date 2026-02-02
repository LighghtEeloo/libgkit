set (CORE "gkit_core")

# Third party libraries
find_package(SDL3 REQUIRED)

## Core Sources file ##
file(GLOB_RECURSE CORE_SRC
  "./application/*.cpp"
  "./graphic/*.cpp"
  "./input/*.cpp"
)

add_library(${CORE} OBJECT ${CORE_SRC})

target_include_directories(${CORE} PRIVATE "include/")
target_link_libraries(${CORE} PRIVATE SDL3::SDL3)