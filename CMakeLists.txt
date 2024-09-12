cmake_minimum_required(VERSION 3.16)

project(LinkedList LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR true)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LinkedList
  main.cpp
  linkedlist.h

)
include(GNUInstallDirs)
install(TARGETS LinkedList
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
