project(testKSMarketApi)
cmake_minimum_required(VERSION 3.2)
include(ExternalProject)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/lib )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


set(MAIN_DIR src/main/)
add_executable(testKSMarketApi 
    ${MAIN_DIR}/event.cpp ${MAIN_DIR}/testKSMarketDataAPI.cpp)

set(MySQL_DIR ${PROJECT_SOURCE_DIR}/cmake_modules/)
find_package(MySQL REQUIRED)
find_package(Boost REQUIRED locale)
include_directories("${PROJECT_SOURCE_DIR}/src/ks_include/" ${Boost_INCLUDE_DIRS}
    ${MySQL_INCLUDE_DIRS})
find_library(lksmarketdataapi NAMES ksmarketdataapi PATHS "external_lib/KSMarketDataAPI/linux64/")
find_library(lkslkc64r NAMES kslkc64r PATHS "external_lib/KSMarketDataAPI/linux64/")
externalproject_add(lib-log4cplus URL http://jaist.dl.sourceforge.net/project/log4cplus/log4cplus-stable/1.2.0/log4cplus-1.2.0-rc3.tar.xz 
    PREFIX ${PROJECT_SOURCE_DIR}/external_lib/log4cplus/ 
    DOWNLOAD_DIR ${PROJECT_SOURCE_DIR}/external_lib/log4cplus
    BUILD_COMMAND make
    INSTALL_COMMAND make install)
#message(${Boost_LIBRARIES})
target_link_libraries(testKSMarketApi -llog4cplus 
    ${Boost_LIBRARIES} ${MySQL_LIBRARIES}
    ${lksmarketdataapi} ${lkslkc64r})


file(COPY external_lib/KSInterB2C.lkc DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

enable_testing()
externalproject_add(GTest SOURCE_DIR ${PROJECT_SOURCE_DIR}/external_lib/gtest/
    PREFIX ${PROJECT_SOURCE_DIR}/external_lib/gtest/
    BUILD_COMMAND make
    INSTALL_COMMAND make install)

