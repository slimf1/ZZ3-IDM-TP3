project ( tp3idm )

cmake_minimum_required ( VERSION 2.8.9 )

find_package ( Threads )

if ( CMAKE_COMPILER_IS_GNUCXX )
 set ( CMAKE_CXX_FLAGS "-Wall -pedantic -O2 ${CMAKE_CXX_FLAGS}" )
endif()

include ( CheckCXXCompilerFlag )

check_cxx_compiler_flag ( "-std=gnu++17" COMPILER_SUPPORTS_CPP17 )

if ( COMPILER_SUPPORTS_CPP17 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++17 ${CMAKE_CXX_FLAGS}" )
else ()
 message ( STATUS "Compiler ${CMAKE_CXX_COMPILER} has no C++17 support." )
endif ()

message ( STATUS "Compiler flags: ${CMAKE_CXX_FLAGS}" )

# Directories #-------------------------------------------------------------------------------------

include_directories( include/ )
link_directories( lib/ )

# Executables #-------------------------------------------------------------------------------------

add_executable ( ${CMAKE_PROJECT_NAME}_q2_q3
                src/testRandom.cpp
                )

add_executable ( ${CMAKE_PROJECT_NAME}_q4
                src/monteCarloPi.cpp
                include/monteCarloPi.hpp
                src/monteCarloMain.cpp
                )

target_link_libraries(${CMAKE_PROJECT_NAME}_q2_q3 CLHEP-Random-2.1.0.0)
target_link_libraries(${CMAKE_PROJECT_NAME}_q4 CLHEP-Random-2.1.0.0)

# Build #-------------------------------------------------------------------------------------------

set_target_properties ( ${CMAKE_PROJECT_NAME}_q2_q3 PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( ${CMAKE_PROJECT_NAME}_q2_q3 ${CMAKE_THREAD_LIBS_INIT} )

set_target_properties ( ${CMAKE_PROJECT_NAME}_q4 PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( ${CMAKE_PROJECT_NAME}_q4 ${CMAKE_THREAD_LIBS_INIT} )
