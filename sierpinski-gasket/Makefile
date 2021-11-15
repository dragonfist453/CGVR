all:
	g++ volume-subdiv.cpp -o volume-subdiv.o -lGL -lGLU -lglut
	g++ 2d-gasket.cpp -o 2d-gasket.o -lGL -lGLU -lglut
	g++ surface-subdiv.cpp -o surface-subdiv.o -lGL -lGLU -lglut

volume-subdiv: volume-subdiv.cpp
	g++ volume-subdiv.cpp -o volume-subdiv.o -lGL -lGLU -lglut

2d-gasket:
	g++ 2d-gasket.cpp -o 2d-gasket.o -lGL -lGLU -lglut

surface-subdiv:
	g++ surface-subdiv.cpp -o surface-subdiv.o -lGL -lGLU -lglut

clean:
	rm *.o