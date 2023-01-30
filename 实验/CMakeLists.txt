cmake_minimum_required(VERSION 3.23)
project(Gobang C)

set(CMAKE_C_STANDARD 11)

add_executable(Gobang main.c graphics.c head.h evaluate.c zobrist.c gameplay.c)


set(CMAKE_C_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
find_package(raylib 2.5.0 REQUIRED) # Requires at least version 2.5.0

set(source "${CMAKE_SOURCE_DIR}/resources")
set(destination "${CMAKE_CURRENT_BINARY_DIR}/resources")


add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${source} => ${destination}"
)

target_link_libraries(${PROJECT_NAME} raylib)