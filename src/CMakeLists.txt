cmake_minimum_required(VERSION 3.1)
project(Petl VERSION 0.0.1)

# library definition
add_library(Petl include/Petl/vector.h
                 include/Petl/expression.h
)
target_compile_features(Petl PUBLIC cxx_std_17)
target_include_directories(Petl PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                       $<INSTALL_INTERFACE:include>
)
add_library(Petl::Petl ALIAS Petl)

install(TARGETS Petl EXPORT PetlTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)
install(EXPORT PetlTargets
        DESTINATION lib/cmake/Petl
        FILE PetlTargets.cmake
        NAMESPACE Petl::
)
install(DIRECTORY include/Petl
        DESTINATION include
)

# should deal with library version...
