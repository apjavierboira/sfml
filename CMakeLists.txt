cmake_minimum_required(VERSION 3.16)
project(Fubar VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
#find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")

#add_executable(${PROJECT_NAME} ${SOURCES})
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/adrian.cpp
    src/beltran.cpp
    src/fran.cpp
    src/raul.cpp
    src/uriel.cpp
    src/javier.cpp
)

target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -Wpedantic
)
