cmake_minimum_required(VERSION 3.15)
project(KutuphaneProje LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
        src
        src/entities
        src/repositories
        src/services
        src/utils
        include
        include/entities
        include/repositories
        include/services
)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h" "src/*.hpp" "include/*.h" "include/*.hpp")

add_executable(kutuphane_sistemi ${SOURCES} ${HEADERS})

if(MSVC)
    target_compile_options(kutuphane_sistemi PRIVATE /W4)
else()
    target_compile_options(kutuphane_sistemi PRIVATE -Wall -Wextra -Wpedantic)
endif()