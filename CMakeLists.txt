cmake_minimum_required(VERSION 3.16)

project(notebook)

file(GLOB SRC CONFIGURE_DEPENDS "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC})
