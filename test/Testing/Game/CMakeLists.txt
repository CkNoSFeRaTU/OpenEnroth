cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

if(ENABLE_TESTS)
    set(TESTING_GAME_SOURCES
            GameTest.cpp
            TestController.cpp)
    set(TESTING_GAME_HEADERS
            GameTest.h
            TestTape.h
            TestController.h
            TestVector.h)

    add_library(testing_game ${TESTING_GAME_SOURCES} ${TESTING_GAME_HEADERS})
    target_link_libraries(testing_game PUBLIC application testing_extensions GTest::gtest)

    target_check_style(testing_game)
endif()
