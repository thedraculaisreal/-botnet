cmake_minimum_required(VERSION 3.31.1)
set(PROJECT_NAME client)
set(SOURCE_FILES source/main.c)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#linking GTK4
#######################################################
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} ${GTK4_LIBRARIES})
#######################################################
