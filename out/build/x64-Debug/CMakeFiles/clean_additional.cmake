# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Phone_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Phone_autogen.dir\\ParseCache.txt"
  "Phone_autogen"
  )
endif()
