cmake_minimum_required(VERSION 3.19)
project(HanziWriter)

set(CMAKE_CXX_STANDARD 14)

add_executable(HanziWriter sstring.h sstring.cpp file.h file.cpp info.h info.cpp  tools.h tools.cpp utf8.h utf8.cpp main.cpp)



TARGET_LINK_LIBRARIES(${PROJECT_NAME} libiconv.so)

