cmake_minimum_required(VERSION 3.1)
project(PetlTests)

# dependencies
#enable_testing()
#find_package(GTest MODULE REQUIRED)
if(NOT TARGET Petl::Petl)
  find_package(Petl CONFIG REQUIRED)
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# target definition
add_executable(PetlTests tests_source.cpp MyVec.h)
target_link_libraries(PetlTests PRIVATE Petl::Petl CONAN_PKG::Catch2)
#target_link_libraries(PetlTests PRIVATE Petl::Petl GTest::Main)

#add_test(NAME Petl.UnitTests COMMAND PetlTests)

