# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Proj_Final_pronto_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Proj_Final_pronto_autogen.dir\\ParseCache.txt"
  "Proj_Final_pronto_autogen"
  )
endif()
