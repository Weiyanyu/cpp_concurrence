cmake_minimum_required(VERSION 3.16.3)
project(ch1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")




set( Boost_USE_STATIC_LIBS OFF )
set( Boost_USE_MULTITHREADED ON )
set( Boost_USE_STATIC_RUNTIME OFF )
find_package( Boost 1.71.0 COMPONENTS thread )




if (Boost_FOUND)

    include_directories(${Boost_INCLUDE_DIR} ../include)

    ADD_DEFINITIONS( "-DHAS_BOOST" )

    file(GLOB SOURCES "../src/*.cpp" "main.cpp")
    
    add_executable(main ${SOURCES})

    target_link_libraries(main ${Boost_LIBRARIES})

else()
    message( FATAL_ERROR "Required Boost packages not found. Perhaps add -DBOOST_ROOT?" )
endif()





 
 



 
