# CMakeList.txt : CMake project for Algorithms, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

# 这段代码可以区分操作系统
MESSAGE("Identifying the OS...")
if(WIN32)
	MESSAGE("This is Windows.")
	message(STATUS "Setting MSVC flags")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")
elseif(APPLE)
	MESSAGE("This is MacOS.")
elseif(UNIX)
	MESSAGE("This is Linux.")
	SET(CMAKE_BUILD_TYPE "Debug")  # Debug模式 选项: Release Debug MinSizeRel RelWithDebInf
	SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") # release模式下 gdb相关选项
	SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  # debug模式下 gdb相关选项
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

add_subdirectory("string")
add_subdirectory("fileHelper")
add_subdirectory("graph")
add_subdirectory("app")
add_subdirectory("test")
add_subdirectory("utils")

# 依赖只能在顶层CMakeList.txt中定义
add_dependencies("graph" "fileHelper" "utils")
add_dependencies("Algorithms" "fileHelper" "graph"  "string")

add_dependencies("LSDTest" "fileHelper"  "string")
add_dependencies("GraphTest" "fileHelper"  "graph")

#set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Algorithms)
# TODO: Add tests and install targets if needed.

#enable_testing()

#add_test(
#  NAME countSortTest
#  COMMAND countSortTest
#)
