cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(MEDIA_SOURCES
        Media.cpp
        MediaLogger.cpp
        MediaPlayer.cpp)

set(MEDIA_HEADERS
        Media.h
        MediaLogger.h
        MediaPlayer.h)

add_library(media STATIC ${MEDIA_SOURCES} ${MEDIA_HEADERS})
target_link_libraries(media PUBLIC media_audio utility application)
target_link_libraries(media PRIVATE ${AVCODEC_LIBRARIES} ${AVFORMAT_LIBRARIES} ${AVUTIL_LIBRARIES} ${SWSCALE_LIBRARIES} ${SWRESAMPLE_LIBRARIES})
target_compile_definitions(media PRIVATE FF_API_NEXT)
target_include_directories(media PRIVATE ${FFMPEG_INCLUDE_DIRS})

target_check_style(media)

add_subdirectory(Audio)
