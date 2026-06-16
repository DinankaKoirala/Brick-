cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

find_package(SFML 3 COMPONENTS Graphics REQUIRED)

add_executable(main
    src/main.cpp
    src/paddle.cpp
    src/ball.cpp
    src/brick.cpp
)
target_include_directories(main PRIVATE headers)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)