#author : 정성구,김찬휘,김영우
#처음에 g++ -c main.cpp
#g++ main.o -o tetris -lsfml-graphics -lsfml-window -lsfml-system로 실행파일 생성

TARGET = tetris
GPP = g++
OBJ_TETRIS = main.o map.o block.o

$(TARGET) : $(OBJ_TETRIS)
	$(GPP) $(OBJ_TETRIS) -o $(TARGET) -g -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp
	$(GPP) -c main.cpp

map.o : map.cpp
	$(GPP) -c map.cpp 

block.o : block.cpp
	$(GPP) -c block.cpp

clean :
	@echo "cleaning Tetris game...."
	rm $(OBJ_TETRIS) tetris
