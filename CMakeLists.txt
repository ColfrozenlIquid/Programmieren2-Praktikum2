cmake_minimum_required(VERSION 3.28)
project(Praktikum2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Praktikum2 main.cpp
        AbstractUI.cpp
        AbstractUI.h
        Character.cpp
        Character.h
        defines.h
        DungeonCrawler.cpp
        DungeonCrawler.h
        Floor.cpp
        Floor.h
        InputType.h
        KeyboardInput.cpp
        KeyboardInput.h
        Level.cpp
        Level.h
        Portal.cpp
        Portal.h
        TerminalUI.cpp
        TerminalUI.h
        Tile.cpp
        Tile.h
        Wall.cpp
        Wall.h
)
