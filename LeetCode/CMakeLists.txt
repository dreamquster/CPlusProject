project(LeetCode)
cmake_minimum_required(VERSION 3.2)
include(ExternalProject)
set(CMAKE_BUILD_TYPE DEBUG)
#SET(CMAKE_CXX_FLAGS "-std=c++11") # Add c++11 functionality
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/lib
${PROJECT_SOURCE_DIR}/deps/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#add dependency
message("Find boost library..\n
If not found, please install libboost-dev and libboost-locale-dev!:)")
find_package(Boost REQUIRED locale)
include_directories("${PROJECT_SOURCE_DIR}/src/include/" ${Boost_INCLUDE_DIRS})
set(LeetCode_SRC_DIR ${PROJECT_SOURCE_DIR}/src/main)
set(LeetCode_SRC ${LeetCode_SRC_DIR}/reverseWord.cc
${LeetCode_SRC_DIR}/maxProduct.cc)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/deps)
add_library(leetcode STATIC ${LeetCode_SRC})
set(liblog4cplus "${PROJECT_SOURCE_DIR}/deps/liblog4cplus-1.2.so.5")
#generate common lib for auxilary test to link
target_link_libraries(leetcode ${liblog4cplus}
${Boost_LIBRARIES})
add_executable(main src/main/main.cc)
target_link_libraries(main leetcode)
#test project
enable_testing()
set(GTEST_SRC_DIR ${PROJECT_SOURCE_DIR}/deps/gtest/)
add_subdirectory(${GTEST_SRC_DIR})
include_directories(${GTEST_SRC_DIR}/include ${GTEST_SRC_DIR}
${LeetCode_SRC_DIR})
#Unit Tests
add_executable(unittest src/test/unittest.cc
src/test/methodTest.cc)
#add dependency libraries
target_link_libraries(unittest gtest gtest_main leetcode)# ${lksmarketdataapi} ${lkslkc64r})
add_test(NAME unittest COMMAND unittest)