cmake_minimum_required(VERSION 3.5)
project(all_any_none_program VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Application target
# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.h"
include_directories( include )

### [2] Test engine
# includes do test manager

# Cria um executável com nome "program" com base no main.cpp
set( APP_NAME "program" )
add_executable( ${APP_NAME}
                src/main.cpp
                src/Forca.cpp )

# define C++11 standard
set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 11)

#add_custom_target(
#    verify
#    COMMAND python3 ${CMAKE_SOURCE_DIR}/../scripts/verify-inputs.py ./${APP_NAME}
#    DEPENDS ${APP_NAME}
#)

# The end
