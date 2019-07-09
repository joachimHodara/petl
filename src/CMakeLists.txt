cmake_minimum_required(VERSION 3.1)
project(Petl VERSION 0.0.1)

# library definition
add_library(Petl INTERFACE)
target_include_directories(Petl 
	INTERFACE 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
add_library(Petl::Petl ALIAS Petl)

target_compile_features(Petl INTERFACE cxx_std_11)

install(TARGETS Petl 
        EXPORT petl-export
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} 
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} 
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#        RUNTIME DESTINATION bin
#        INCLUDES DESTINATION include
)
install(EXPORT petl-export
        DESTINATION lib/cmake/Petl
        FILE PetlTargets.cmake
        NAMESPACE Petl::
)
#install(DIRECTORY include/Petl
#        DESTINATION include
#)

# should deal with library version...
