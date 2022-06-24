cmake_minimum_required (VERSION 3.8)

project (Casino)

find_package(SFML 2.4 COMPONENTS audio graphics window system REQUIRED)

add_executable (Casino 
main.cpp
Casino.h
Casino.cpp
Phase.h
Phase.cpp
)

target_link_libraries(Casino sfml-audio sfml-graphics sfml-window sfml-system)

set_target_properties(Casino PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})