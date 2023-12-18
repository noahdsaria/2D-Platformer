output: main.o
	g++ main.o -lraylib -o output

main.o: main.cpp player.h
	g++ -c -lraylib main.cpp

clean:
	rm *.o output