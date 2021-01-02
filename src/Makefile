#author : 정성구
#처음에 gcc -c main.cpp
#g++ main.o -o tetris -lsfml-graphics -lsfml-window -lsfml-system로 실행파일 생성
#ieeeee

TARGET = tetris

$(TARGET) : main.o map.o block.o
	g++ main.o map.o block.o -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp
	g++ -c main.cpp

map.o : map.cpp
	g++ -c map.cpp 

block.o : block.cpp
	g++ -c block.cpp

clean :
	rm *.o tetris
