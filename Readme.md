# GAME PROJECT: Role-playing game

Content :

  - game_project: src code
  - sfml : library used (version for linux)

Game_project content (folders):
  - controller: the controller classes
 - headers
 - media: images and font file
 - view: view classes (Drawer, Menu)
 - model: Game entity
game_project content (files):
 - main.cpp
 - map.txt: the game map
 - description.txt: notes for the game
 - CMakeLists.txt

# Prerequisite
 - Being on LINUX
 - Have cmake_gui to build. a link explains how to install it (https://cgold.readthedocs.io/en/latest/first-step/installation.html)
# Launch:
## On cmake_gui
  - for the source code: move to / game_project
  - for the build: / game_project / build
  - then click on Generate (Unix Makefiles)

After build, you COPY the folder (media which in the game_project folder) in the build folder
```sh
$ cp -r media build
```
Move to the / build folder
```sh
$  cd build
```
Launch the command
```sh
$  make
```
5- After step 4 you will have the executable (game_project). run the command:
```sh
$  ./game_project
```
it's your turn , enjoy palying ;)
