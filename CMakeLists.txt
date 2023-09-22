cmake_minimum_required(VERSION 3.23)

project(motorent)

set(CMAKE_CXX_STANDARD 17)

include_directories(System)

add executable (motorent
             sys/main.cpp
             class/admin/admin.cpp
             class/admin/admin.h
             class/customers/customers.cpp
             class/customers/customers.h
             class/motorbike/motorbike.cpp
             class/motorbike/motorbike.h
             class/motorbike/rented.cpp
             class/motorbike/rented.h
             class/rating/rating.cpp
             class/rating/rating.h
             class/rent/rent.cpp
             class/rent/rent.h
             sys/function.h
             sys/function.cpp)