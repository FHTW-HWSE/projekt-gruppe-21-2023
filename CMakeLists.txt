cmake_minimum_required(VERSION 3.10.0);

project(ROS RESTAURANT);

find_package(CTest);
include(Catch);

add_library(ROS
src/restaurant.c
src/booking.c
src/contact.c
src/contactTracing.c
src/fileHandeling.c
src/parser.c
src/structHandeling
)
target_include_directories(ROS PUBLIC include)
add_executable(ROS_Test

src/main.c
test/restaurantTest.cpp
test/bookingTest.cpp
test/contactTest.cpp
test/filehandelingTest.cpp
)
target_link_libraries(ROS_Test ROS)
catch_discover_tests(ROS_Test)


