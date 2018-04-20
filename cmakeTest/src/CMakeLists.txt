cmake_minimum_required(VERSION 3.7)
project(myFirstCppClass VERSION 1.0 LANGUAGES CXX)
#
# configure project to use OpenCV
set (OpenCV_STATIC off)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
#include_directories(${OpenCV_INCLUDE_DIRS} ${Eigen_INCLUDE_DIRS})

# set compiler options for Visual Studio
if (MSVC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /NODEFAULTLIB:MSVCRT;%(IgnoreSpecificDefaultLibraries)")
endif ()

# set variables with source files
set(DIR .)
set(HDR ${DIR}/Quadrat.hpp )
set(SRC ${DIR}/main.cpp ${DIR}/Quadrat.cpp)

# set up file tree in IDE
source_group("Source Files" FILES ${SRC})
source_group("Header Files" FILES ${HDR})

# create executable
add_executable(myFirstCppClass ${SRC} ${HDR})
target_link_libraries(myFirstCppClass ${OpenCV_LIBS})