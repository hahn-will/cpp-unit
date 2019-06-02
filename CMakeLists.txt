cmake_minimum_required(VERSION 3.13)
project(simple-cpp-unit VERSION 1.0.0
  LANGUAGES CXX
  DESCRIPTION "A simple cpp unit test library")
include(GNUInstallDirs)

add_library(simple-cpp-unit SHARED src/TestSuite.cpp src/TestMethod.cpp)
set_target_properties(simple-cpp-unit PROPERTIES
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER "api/simple-cpp-unit.hpp;api/TestSuite.hpp;api/TestMethod.hpp")
configure_file(simple-cpp-unit.pc.in simple-cpp-unit.pc @ONLY)
target_include_directories(simple-cpp-unit PRIVATE .)
target_include_directories(simple-cpp-unit PUBLIC api)
install(TARGETS simple-cpp-unit
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/simple-cpp-unit.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

add_executable(simple-cpp-unit-tests tests/Main.cpp)
target_link_libraries(simple-cpp-unit-tests simple-cpp-unit)
