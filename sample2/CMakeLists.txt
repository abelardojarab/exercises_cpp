project(chapterFirstExample)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig)
pkg_check_modules(GTEST REQUIRED gtest>=1.7.0)
pkg_check_modules(GMOCK REQUIRED gmock>=1.7.0)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(sources
   main.cpp
   ATweet.cpp)
set(testSources
   RetweetCollectionTest.cpp)

add_executable(sample2 ${sources} ${testSources})
target_link_libraries(sample2 Threads::Threads)
target_link_libraries(sample2 gmock)
target_link_libraries(sample2 gtest)
