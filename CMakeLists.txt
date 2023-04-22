cmake_minimum_required(VERSION 3.10)
project(Sort)

set(CMAKE_CXX_STANDAR 17)

set(M main)
set(S sort_unite_testing)
set(T test1)


#include(FetchContent)
#FetchContent_Declare(
#  googletest
#  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

set(FLAGS -c -g -Iinc -Wall -pedantic -iquote headers)

add_executable(${M} sources/main.cpp)
target_include_directories(${M} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

add_executable(${T} sources/test.cpp)
target_include_directories(${T} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

enable_testing()

#add_executable(${S} tests/unite_tests.cpp)
#target_link_libraries(${S} GTest::gtest_main)
#target_link_libraries(${S} PUBLIC $)


#target_complie_options(${S} PRIVATE ${FLAGS})
target_compile_options(${M} PRIVATE ${FLAGS})
target_compile_options(${T} PRIVATE ${FLAGS})