if (APPLE)
    set(CMAKE_CXX_COMPILER /usr/local/bin/g++-5 CACHE PATH "" FORCE)
    set(CMAKE_C_COMPILER /usr/local/bin/gcc-5 CACHE PATH "" FORCE)
endif ()


cmake_minimum_required(VERSION 3.10)
project(ImageServer)

set(CMAKE_CXX_STANDARD 14)

if (APPLE)
    set(OPENSSL_ROOT_DIR "/usr/local/Cellar/openssl/1.0.2o_2")
endif()

find_package(Tcmalloc)
find_package(Threads)
find_package(OpenSSL)

if(OPENSSL_FOUND)
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()

find_program(CCACHE_FOUND ccache)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++1y -pedantic -Wextra")
find_package( Boost 1.52 COMPONENTS system thread REQUIRED )

include_directories( ${Boost_INCLUDE_DIR} )

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
include_directories($ENV{HOME}/workSpace/oss/crow/include)


add_executable(ImageServer main.cpp)

target_link_libraries(ImageServer ${Boost_LIBRARIES})