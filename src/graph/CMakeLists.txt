aux_source_directory(. DIR_LIB_SRCS)

add_library("graph" STATIC ${DIR_LIB_SRCS})

target_link_libraries("graph" "fileHelper" "utils")
