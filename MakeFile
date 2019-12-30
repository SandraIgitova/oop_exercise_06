cmake_minimum_required(VERSION 3.10)
project(oop4)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp TAllocationBlock.cpp TList.cpp TListItem.cpp TStack.cpp TStackItem.cpp triangle.cpp)
