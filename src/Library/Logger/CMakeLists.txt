cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(LIBRARY_LOGGER_SOURCES
        Logger.cpp)

set(LIBRARY_LOGGER_HEADERS
        Logger.h)

add_library(library_logger STATIC ${LIBRARY_LOGGER_SOURCES} ${LIBRARY_LOGGER_HEADERS})
target_link_libraries(library_logger PUBLIC platform utility)
target_check_style(library_logger)
