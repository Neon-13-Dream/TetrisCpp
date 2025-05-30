cmake_minimum_required( VERSION 4.0 )
project( tetriscpp LANGUAGES CXX )

set( CMAKE_CXX_STANDART 21 )
set( CMAKE_CXX_STANDART_REQUIRED ON )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

find_package( raylib REQUIRED )

file( GLOB ALL_CPP cppFiles/*.cpp )

include_directories( hFiles )
add_executable( ${PROJECT_NAME} ${ALL_CPP} main.cpp )
target_link_libraries( ${PROJECT_NAME} raylib )
