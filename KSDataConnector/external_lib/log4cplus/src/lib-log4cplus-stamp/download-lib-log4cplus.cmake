message(STATUS "downloading...
     src='http://jaist.dl.sourceforge.net/project/log4cplus/log4cplus-stable/1.2.0/log4cplus-1.2.0-rc3.tar.xz'
     dst='/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/log4cplus-1.2.0-rc3.tar.xz'
     timeout='none'")




file(DOWNLOAD
  "http://jaist.dl.sourceforge.net/project/log4cplus/log4cplus-stable/1.2.0/log4cplus-1.2.0-rc3.tar.xz"
  "/root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/log4cplus-1.2.0-rc3.tar.xz"
  SHOW_PROGRESS
  # no TIMEOUT
  STATUS status
  LOG log)

list(GET status 0 status_code)
list(GET status 1 status_string)

if(NOT status_code EQUAL 0)
  message(FATAL_ERROR "error: downloading 'http://jaist.dl.sourceforge.net/project/log4cplus/log4cplus-stable/1.2.0/log4cplus-1.2.0-rc3.tar.xz' failed
  status_code: ${status_code}
  status_string: ${status_string}
  log: ${log}
")
endif()

message(STATUS "downloading... done")
