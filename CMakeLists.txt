cmake_minimum_required(VERSION 4.1)
project(shortest_path_obstacles)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(shortest_path_obstacles
        .idea/.gitignore
        .idea/modules.xml
        .idea/shortest-path-obstacles.iml
        .idea/vcs.xml
        include/dijkstra.hpp
        include/geometry.hpp
        include/visibility.hpp
        src/dijkstra.cpp
        src/geometry.cpp
        src/main.cpp
        src/visibility.cpp
        input.txt
        path.exe
        path.txt
        src/Geometry.cpp
        src/Geometry.h
        src/Pathfinder.cpp
        src/Pathfinder.h
        main.cpp
)
