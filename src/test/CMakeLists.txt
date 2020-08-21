# 指示在哪里找头文件
include_directories(${CMAKE_SOURCE_DIR}/graph)
include_directories(${CMAKE_SOURCE_DIR}/string)
include_directories(${CMAKE_SOURCE_DIR}/fileHelper)

# 指定在哪里找链接库
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable (countSortTest  catch_cache.cpp "countSortTest.cpp")
add_executable (LSDTest  catch_cache.cpp  "LSDTest.cpp")
add_executable (GraphTest  catch_cache.cpp  "GraphTest.cpp")
add_executable (GraphSearchTest catch_cache.cpp "GraphSearchTest.cpp")
add_executable (GraphCCTest catch_cache.cpp "GraphCCTest.cpp")
add_executable (GraphPathTest catch_cache.cpp "GraphPathTest.cpp")
add_executable (TwoColorTest catch_cache.cpp "TwoColorTest.cpp")
add_executable (CircleTest catch_cache.cpp "CircleTest.cpp")
add_executable (SortTest  catch_cache.cpp  "SortTest.cpp")
add_executable (MSDTest  catch_cache.cpp  "MSDTest.cpp")

add_executable (SkipListTest catch_cache.cpp "SkipListTest.cpp")
add_executable (TrieSTTest catch_cache.cpp "TrieSTTest.cpp")
add_executable (SubStringSearchTest catch_cache.cpp "SubStringSearchTest.cpp")

# 指定countSortTest需要链接哪些库
target_link_libraries(countSortTest "graph")
target_link_libraries(countSortTest "string")
target_link_libraries(countSortTest "fileHelper")


# 指定LSDTest需要链接哪些库
target_link_libraries(LSDTest "string")
target_link_libraries(LSDTest "fileHelper")

target_link_libraries(GraphTest "fileHelper" "graph")

# 指定MSDTest需要链接哪些库
target_link_libraries(MSDTest "string")
target_link_libraries(MSDTest "fileHelper")

#指定GraphSearchTest需要链接哪些库
target_link_libraries(GraphSearchTest "fileHelper" "graph")

#指定GraphPathTest需要链接哪些库
target_link_libraries(GraphPathTest "fileHelper" "graph")

#指定GraphCCTest需要链接哪些库
target_link_libraries(GraphCCTest "fileHelper" "graph")

#指定TwoColorTest需要链接哪些库
target_link_libraries(TwoColorTest "fileHelper" "graph")

#指定CircleTest需要链接哪些库
target_link_libraries(CircleTest "fileHelper" "graph")
