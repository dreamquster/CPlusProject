project(testKSMarketApi)
cmake_minimum_required(VERSION 3.2)
include(ExternalProject)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories("${PROJECT_SOURCE_DIR}/ks_include/")

add_executable(testKSMarketApi event.cpp testKSMarketDataAPI.cpp)

find_library(lksmarketdataapi NAMES ksmarketdataapi PATHS "../KSMarketDataAPI/linux64/")
find_library(lkslkc64r NAMES kslkc64r PATHS "../KSMarketDataAPI/linux64/")
externalproject_add(lib-log4cplus URL http://jaist.dl.sourceforge.net/project/log4cplus/log4cplus-stable/1.2.0/log4cplus-1.2.0-rc3.tar.xz 
    PREFIX ${CMAE_CURRENT_BINARY_DIR}/external_lib/log4cplus 
    DOWNLOAD_DIR ${CMAE_CURRENT_BINARY_DIR}/external_lib/log4cplus
    BUILD_COMMAND make
    INSTALL_COMMAND make install)

target_link_libraries(testKSMarketApi -llog4cplus ${lksmarketdataapi} ${lkslkc64r})
