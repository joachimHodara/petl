cmake_minimum_required(VERSION 3.1)
project(Petl VERSION 0.0.1 
             DESCRIPTION "A portable expression template library"
			 LANGUAGES CXX)

# library definition
add_library(Petl INTERFACE)
target_include_directories(Petl 
	INTERFACE 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
add_library(Petl::Petl ALIAS Petl)

target_compile_features(Petl INTERFACE cxx_std_11)

# create an export from the Petl target 
install(TARGETS Petl 
        EXPORT PetlExport
)

# generate CMake file that lets other CMake projects import petl targets
install(EXPORT PetlExport
        NAMESPACE Petl::
        DESTINATION lib/cmake/Petl
)

# copies include folder during install
install(DIRECTORY include/Petl
        DESTINATION include
)

# should deal with library version...
