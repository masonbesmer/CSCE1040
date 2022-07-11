OBJS	= car.o carmain.o
SOURCE	= car.cpp carmain.cpp
HEADER	= car.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

car.o: car.cpp
	$(CC) $(FLAGS) car.cpp 

carmain.o: carmain.cpp
	$(CC) $(FLAGS) carmain.cpp 


clean:
	rm -f $(OBJS) $(OUT)