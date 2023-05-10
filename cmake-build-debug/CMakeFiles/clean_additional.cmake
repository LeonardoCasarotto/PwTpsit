# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/PwTpsit_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/PwTpsit_autogen.dir/ParseCache.txt"
  "PwTpsit_autogen"
  )
endif()
