# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\CyberpunkBP_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CyberpunkBP_autogen.dir\\ParseCache.txt"
  "CyberpunkBP_autogen"
  )
endif()
