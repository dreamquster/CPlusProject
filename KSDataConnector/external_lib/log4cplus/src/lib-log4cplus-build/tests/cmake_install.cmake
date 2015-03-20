# Install script for directory: /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/tests

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/appender_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/configandwatch_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/customloglevel_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/fileappender_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/filter_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/hierarchy_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/loglog_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/ndc_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/ostream_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/patternlayout_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/performance_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/priority_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/propertyconfig_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/thread_test/cmake_install.cmake")
  include("/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/timeformat_test/cmake_install.cmake")

endif()

