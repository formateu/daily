cmake_minimum_required(VERSION 3.24)
project(leetcode_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(LC_ENABLE_WERROR "Treat warnings as errors" ON)

function(lc_apply_warnings target)
  target_compile_options(${target} PRIVATE
    -Wall -Wextra -Wpedantic
    -Wconversion -Wsign-conversion
    -Wshadow -Wformat=2
  )
  if(LC_ENABLE_WERROR)
    target_compile_options(${target} PRIVATE -Werror)
  endif()
endfunction()

file(GLOB_RECURSE LC_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/*/src/*.cpp"
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lc_tests ${LC_SOURCES})
target_compile_definitions(lc_tests PRIVATE LC_ENABLE_TESTS=1)
target_link_libraries(lc_tests PRIVATE GTest::gtest_main)
lc_apply_warnings(lc_tests)

include(GoogleTest)
gtest_discover_tests(lc_tests DISCOVERY_TIMEOUT 30)

add_library(lc_solutions STATIC ${LC_SOURCES})
target_compile_definitions(lc_solutions PRIVATE LC_ENABLE_TESTS=0)
lc_apply_warnings(lc_solutions)