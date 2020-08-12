# ��Ҫ�����Դ�ļ�
aux_source_directory(. DIR_LIB_SRCS)

# ָʾ��������ͷ�ļ�
include_directories(${CMAKE_SOURCE_DIR}/graph)
include_directories(${CMAKE_SOURCE_DIR}/string)
include_directories(${CMAKE_SOURCE_DIR}/fileHelper)

# ָ�������������ӿ�
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable (Algorithms  ${DIR_LIB_SRCS})

# ָ����Ҫ������Щ��
target_link_libraries(Algorithms "graph")
target_link_libraries(Algorithms "string")
target_link_libraries(Algorithms "fileHelper")

