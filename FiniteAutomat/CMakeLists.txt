cmake_minimum_required(VERSION 3.8)

project(main LANGUAGES CXX)

file(GLOB SOURCES
    header/*.h
    src/*.cpp)

add_executable(main ${SOURCES})