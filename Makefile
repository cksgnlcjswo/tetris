TARGET = Tetris
$(TARGET) : main.o
		g++ main.o -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o : main.cpp
		g++ -c main.cpp

clean : 
		rm *.o $(TARGET)

