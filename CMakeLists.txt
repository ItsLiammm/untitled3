cmake_minimum_required(VERSION 3.24)
project(untitled3)

set(CMAKE_CXX_STANDARD 17)

add_library(my_lib
        main.cpp
        Oggetto.cpp
        Lista.cpp
        ListaObserver.cpp
        Utente.cpp
        )

target_include_directories(my_lib PUBLIC src)

include(FetchContent)
FETCHCONTENT_DECLARE(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
FETCHCONTENT_MAKEAVAILABLE(googletest)

enable_testing()


add_executable(Progetto
        main.cpp
        ListaObserver.cpp
        Lista.cpp
        Oggetto.cpp
        Utente.cpp
        )

add_executable(runTests
        OggettoTest.cpp
        ListaTest.cpp
        ListaObserverTest.cpp
        UtenteTest.cpp
        )

target_link_libraries(runTests
        my_lib
        gtest
        gmock
        gtest_main
    )

#add_test(NAME AllTests COMMAND runTests)

include(GoogleTest)
gtest_discover_tests(runTests)
