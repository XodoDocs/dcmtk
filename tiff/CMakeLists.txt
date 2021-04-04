cmake_minimum_required(VERSION 3.3)

project(StaticTIFFLib C)

if (PROJECT_SPECIFIC_OPTIMIZATIONS)
    if (WINDOWS)
        set(COMPILE_OPTS "/O1")
    elseif (LINUX)
        set(COMPILE_OPTS "-Os")
    elseif (MACOSX)
        set(COMPILE_OPTS "")
    endif (WINDOWS)
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${COMPILE_OPTS}")
endif (PROJECT_SPECIFIC_OPTIMIZATIONS)

set(ADV_IM_DIR "${CMAKE_SOURCE_DIR}")
set(TIFF_DIR "${ADV_IM_DIR}/tiff")

set(LIBTIFF_SOURCES
    ${TIFF_DIR}/libtiff/tif_aux.c
    ${TIFF_DIR}/libtiff/tif_close.c
    ${TIFF_DIR}/libtiff/tif_codec.c
    ${TIFF_DIR}/libtiff/tif_color.c
    ${TIFF_DIR}/libtiff/tif_compress.c
    ${TIFF_DIR}/libtiff/tif_dir.c
    ${TIFF_DIR}/libtiff/tif_dirinfo.c
    ${TIFF_DIR}/libtiff/tif_dirread.c
    ${TIFF_DIR}/libtiff/tif_dirwrite.c
    ${TIFF_DIR}/libtiff/tif_dumpmode.c
    ${TIFF_DIR}/libtiff/tif_error.c
    ${TIFF_DIR}/libtiff/tif_extension.c
    ${TIFF_DIR}/libtiff/tif_fax3.c
    ${TIFF_DIR}/libtiff/tif_fax3sm.c
    ${TIFF_DIR}/libtiff/tif_flush.c
    ${TIFF_DIR}/libtiff/tif_getimage.c
    ${TIFF_DIR}/libtiff/tif_lzw.c
    ${TIFF_DIR}/libtiff/tif_open.c
    ${TIFF_DIR}/libtiff/tif_packbits.c
    ${TIFF_DIR}/libtiff/tif_predict.c 
    ${TIFF_DIR}/libtiff/tif_print.c
    ${TIFF_DIR}/libtiff/tif_read.c
    ${TIFF_DIR}/libtiff/tif_strip.c
    ${TIFF_DIR}/libtiff/tif_swab.c
    ${TIFF_DIR}/libtiff/tif_tile.c
    ${TIFF_DIR}/libtiff/tif_version.c 
    ${TIFF_DIR}/libtiff/tif_warning.c
    ${TIFF_DIR}/libtiff/tif_write.c 
    ${TIFF_DIR}/libtiff/tif_jpeg.c 
    ${TIFF_DIR}/libtiff/tif_zip.c
    # We use tif_unix on all platfroms
    ${TIFF_DIR}/libtiff/tif_unix.c
    ${TIFF_DIR}/libtiff/tif_ojpeg.c
)

if (NOT WINDOWS) # On Windows, use _lfind										
    set(LIBTIFF_SOURCES ${LIBTIFF_SOURCES} port/lfind.c)
endif (NOT WINDOWS)

if(WINDOWS)
    #ignore warnings in 3rd party lib
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /wd4013 /wd4018 /wd4244 /wd4311 /wd4267 /wd4312")
endif()


ADD_LIBRARY(StaticLibTIFF STATIC ${LIBTIFF_SOURCES})

target_link_libraries(StaticLibTIFF StaticLibPNG StaticLibJPEG)
target_include_directories(StaticLibTIFF PUBLIC ${ADV_IM_DIR} ${ADV_IM_DIR}/jpeg)
target_include_directories(StaticLibTIFF PUBLIC ${ADV_IM_DIR}/zlib)
