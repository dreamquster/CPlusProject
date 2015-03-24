project(testKSMarketApi)
cmake_minimum_required(VERSION 3.2)
include(ExternalProject)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/lib 
    ${PROJECT_SOURCE_DIR}/external_lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#add dependency
message("Find boost library..\n
If not found, please install libboost-dev and libboost-locale-dev!:)")
find_package(Boost REQUIRED locale)
include_directories("${PROJECT_SOURCE_DIR}/src/include/" ${Boost_INCLUDE_DIRS})

set(KSMD_SRC_DIR ${PROJECT_SOURCE_DIR}/src/main)
set(KSMD_SRC src/main/event.cpp src/main/IDGenerator.cc src/main/KSMarketDataOp.cc 
        src/main/KSMarketDataApi.cc src/main/KSMarketDataConf.cc 
        src/main/KSMarketDataSpi.cc src/main/gobal.cc)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/external_lib)
add_library(ksmd  STATIC ${KSMD_SRC})
find_library(lksmarketdataapi NAMES ksmarketdataapi PATHS "external_lib/KSMarketDataAPI/linux64/")
find_library(lkslkc64r NAMES kslkc64r PATHS "external_lib/KSMarketDataAPI/linux64/")
set(liblog4cplus "${PROJECT_SOURCE_DIR}/external_lib/liblog4cplus-1.2.so.5")
set(libmysqlcppconn "${PROJECT_SOURCE_DIR}/external_lib/libmysqlcppconn.so.7")
#generate common lib for auxilary test to link
target_link_libraries(ksmd ${liblog4cplus} ${libmysqlcppconn}
    ${Boost_LIBRARIES} 
    ${lksmarketdataapi} ${lkslkc64r})
add_executable(KSMD src/main/KSMD.cc)
target_link_libraries(KSMD ksmd)


file(COPY res/KSInterB2C.lkc res/ksmd.properties res/log4cplus.properties res/run.sh 
    DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
#file(COPY ${liblog4cplus} ${libmysqlcppconn}
#    ${lksmarketdataapi} ${lkslkc64r}
#    DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib)

if (test)
    enable_testing()
    set(GTEST_SRC_DIR ${PROJECT_SOURCE_DIR}/external_lib/gtest/)
    add_subdirectory(${GTEST_SRC_DIR})
    include_directories(${GTEST_SRC_DIR}/include ${GTEST_SRC_DIR} 
        ${KSMD_SRC_DIR})
    #Unit Tests
    add_executable(unittest src/test/unittest.cc
            src/test/KSMySQLOpTest.cc)
    #add dependency libraries 
    target_link_libraries(unittest gtest gtest_main ksmd)# ${lksmarketdataapi} ${lkslkc64r})
    
    add_test(NAME unittest COMMAND unittest)
endif()

