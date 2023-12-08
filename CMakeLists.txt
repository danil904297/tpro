cmake_minimum_required(VERSION 3.26)
project(tpro)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS graphics window system REQUIRED)


add_executable(tpro
        Menu.h


        main.cpp

)

target_link_libraries(tpro sfml-graphics sfml-audio sfml-window sfml-system)


