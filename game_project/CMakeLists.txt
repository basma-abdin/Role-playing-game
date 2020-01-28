cmake_minimum_required(VERSION 3.10)
project(game_project)

set(CMAKE_CXX_STANDARD 11)

include_directories(headers)
include_directories(media)

set ( PROJECT_LINK_LIBS libsfml-graphics.so libsfml-system.so libsfml-window.so )
link_directories( /${CMAKE_CURRENT_SOURCE_DIR}/../sfml/SFML-2.5.1/lib )

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/map.txt  ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)



include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../sfml/SFML-2.5.1/include)

add_executable(game_project
        controller/GameManagerState.cpp
        controller/IntroState.cpp
        controller/PauseState.cpp
        controller/Random.cpp
        controller/StateManager.cpp
        controller/WinState.cpp
        model/Balle.cpp
        model/Carte.cpp
        model/Element.cpp
        model/Guerrier.cpp
        model/GuerrierPrincipal.cpp
        model/ObjetRamassable.cpp
        model/Obstacle.cpp
        model/Position.cpp
        model/Worker.cpp
        view/Drawer.cpp
        view/Menu.cpp
        main.cpp)

target_link_libraries(game_project ${PROJECT_LINK_LIBS} )
