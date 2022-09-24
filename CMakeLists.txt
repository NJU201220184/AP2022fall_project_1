cmake_minimum_required(VERSION 3.22)
project(AP_project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP_project_1 main.cpp User.cpp User.h Admin.cpp Admin.h menu.h Commodity.cpp Commodity.h Order.cpp Order.h seller.h File.h)
