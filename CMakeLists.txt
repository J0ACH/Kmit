cmake_minimum_required (VERSION 3.8)
cmake_policy(SET CMP0048 NEW)
project (Kmit VERSION 0.0.1)

message(STATUS "")
message(STATUS "Kmit [${PROJECT_VERSION}] config init...")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

message(STATUS "CMAKE_GENERATOR : " ${CMAKE_GENERATOR})
message(STATUS "CMAKE_BUILD_TYPE : " ${CMAKE_BUILD_TYPE})
message(STATUS "CMAKE_CONFIGURATION_TYPES : " ${CMAKE_CONFIGURATION_TYPES})

add_subdirectory (source)





