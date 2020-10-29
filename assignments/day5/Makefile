CXX = g++
NAME = Shapy
all: main.o libshape.so
	$(CXX) main.o -L. -lshape -o $(NAME)

main.o: main.cpp
	$(CXX) -c main.cpp 

libshape.so: shape.cpp
	$(CXX) --shared -fPIC shape.cpp -o libshape.so

unittests.o: libshape.so
	$(CXX) tests.cpp -L. -lshape -o unittest_$(NAME)