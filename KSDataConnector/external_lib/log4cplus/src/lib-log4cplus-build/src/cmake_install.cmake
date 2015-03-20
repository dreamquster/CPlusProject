# Install script for directory: /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so.1.2.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/src/liblog4cplus.so.1.2.0"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/src/liblog4cplus.so.0"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/src/liblog4cplus.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so.1.2.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus" TYPE FILE FILES
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/appender.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/asyncappender.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/clogger.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/config.hxx"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/configurator.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/consoleappender.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/fileappender.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/fstreams.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/hierarchy.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/hierarchylocker.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/layout.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/log4judpappender.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/logger.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/loggingmacros.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/loglevel.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/mdc.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/ndc.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/nteventlogappender.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/nullappender.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/socketappender.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/streams.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/syslogappender.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/tchar.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/tracelogger.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/tstring.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/version.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/win32debugappender.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/win32consoleappender.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/boost" TYPE FILE FILES "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/boost/deviceappender.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/helpers" TYPE FILE FILES
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/appenderattachableimpl.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/connectorthread.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/fileinfo.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/lockfile.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/loglog.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/logloguser.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/pointer.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/property.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/queue.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/sleep.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/snprintf.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/socket.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/socketbuffer.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/stringhelper.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/thread-config.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/helpers/timehelper.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/internal" TYPE FILE FILES
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/internal/env.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/internal/internal.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/internal/socket.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/spi" TYPE FILE FILES
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/spi/appenderattachable.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/spi/factory.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/spi/filter.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/spi/loggerfactory.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/spi/loggerimpl.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/spi/loggingevent.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/spi/objectregistry.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/spi/rootlogger.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/thread/impl" TYPE FILE FILES
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/thread/impl/syncprims-cxx11.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/thread/impl/syncprims-impl.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/thread/impl/syncprims-pthreads.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/thread/impl/syncprims-win32.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/thread/impl/threads-impl.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/thread/impl/tls.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/thread" TYPE FILE FILES
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/thread/syncprims-pub-impl.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/thread/syncprims.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/thread/threads.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/config" TYPE FILE FILES
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/config/macosx.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/config/win32.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/src/../include/log4cplus/config/windowsh-inc.h"
    "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/include/log4cplus/config/defines.hxx"
    )
endif()

