#author : 정성구,김찬휘,김영우
#처음에 g++ -c main.cpp
#g++ main.o -o tetris -lsfml-graphics -lsfml-window -lsfml-system로 실행파일 생성

<<<<<<< HEAD
TARGET = tetris
GPP = g++
OBJ_TETRIS = main.o map.o block.o
=======
TARGET = tetris.out
>>>>>>> d8c7585fe787a893e6ff25e7dab8f345ecc7a68c

$(TARGET) : $(OBJ_TETRIS)
	$(GPP) $(OBJ_TETRIS) -o $(TARGET) -g -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp
	$(GPP) -c main.cpp

map.o : map.cpp
	$(GPP) -c map.cpp 

block.o : block.cpp
	$(GPP) -c block.cpp

clean :
<<<<<<< HEAD
	@echo "cleaning Tetris game...."
	rm $(OBJ_TETRIS) tetris
=======
	rm *.o tetris.out
>>>>>>> d8c7585fe787a893e6ff25e7dab8f345ecc7a68c
