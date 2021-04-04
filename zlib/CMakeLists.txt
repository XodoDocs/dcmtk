cmake_minimum_required(VERSION 3.3)

project (StaticLibZ)

if (WINDOWS)
    add_compile_definitions (ZLIB_DLL)
endif (WINDOWS)


set(ADV_IM_DIR "${CMAKE_SOURCE_DIR}")
set(ZLIB_DIR "${ADV_IM_DIR}/zlib")

file(GLOB ZLIB_SRCS "${ZLIB_DIR}/*")


list(REMOVE_ITEM ZLIB_SRCS "${ZLIB_DIR}/maketree.c"
  "${ZLIB_DIR}/minigzip.c"
  "${ZLIB_DIR}/example.c"
)


ADD_LIBRARY(StaticLibZ ${ZLIB_SRCS})


