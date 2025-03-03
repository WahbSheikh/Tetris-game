CC = g++
SOURCE = main.cpp
EXEC = main.exe
COMP = block.cpp blocks.cpp game.cpp colors.cpp grid.cpp position.cpp GameStateMachine.cpp MenuState.cpp PlayState.cpp PauseState.cpp HighScoreState.cpp LinkedList.cpp

#Include Path for the Headers (No need to use if the headers are on the root folder)
INCLUDE_PATH = -I "C:\raylib\raylib\src"

#Library Path for Library (No need to use i guess if the folder in which the libraries are set global)
LIB_PATH = -L "C:\raylib\raylib\src"

#LIB FLAGS
LIB_FLAGS = -lraylib -lgdi32 -lwinmm -static 

all:
	$(CC) $(SOURCE) $(COMP) -o $(EXEC) $(INCLUDE_PATH) $(LIB_PATH) $(LIB_FLAGS)

run:
	./main.exe

clear:
	rm main.exe



