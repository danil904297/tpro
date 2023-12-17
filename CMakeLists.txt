cmake_minimum_required(VERSION 3.26)
project(sf)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS graphics window system REQUIRED)


add_executable(sf
        Menu.h
        main.cpp
        nastr.h
        exitConfirmation.h

        player.h
        options.h
        player.cpp
        settings.h
        escape.h


)

target_link_libraries(sf sfml-graphics sfml-audio sfml-window sfml-system)


