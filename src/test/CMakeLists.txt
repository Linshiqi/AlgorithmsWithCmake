# 指示在哪里找头文件
include_directories(${CMAKE_SOURCE_DIR}/graph)
include_directories(${CMAKE_SOURCE_DIR}/string)
include_directories(${CMAKE_SOURCE_DIR}/fileHelper)

# 指定在哪里找链接库
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable (countSortTest  catch_cache.cpp "countSortTest.cpp")
add_executable (LSDTest  catch_cache.cpp  "LSDTest.cpp")
add_executable (GraphTest  catch_cache.cpp  "GraphTest.cpp")

# 指定countSortTest需要链接哪些库
target_link_libraries(countSortTest "graph")
target_link_libraries(countSortTest "string")
target_link_libraries(countSortTest "fileHelper")

# 指定LSDTest需要链接哪些库
target_link_libraries(LSDTest "string")
target_link_libraries(LSDTest "fileHelper")
target_link_libraries(GraphTest "fileHelper" "graph")

