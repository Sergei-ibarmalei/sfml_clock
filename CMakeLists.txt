cmake_minimum_required(VERSION 3.16.3)

project(clock_3)
set(SOURCES
        thetime.cpp
        narrow.cpp
        sfml_class.cpp
        table.cpp
        rectangle.cpp
        sfml_engine.cpp
        ciferblat.cpp
        main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        sfml-graphics
        sfml-window
        sfml-system)



