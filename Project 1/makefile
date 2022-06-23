OBJS	= car.o driver.o drivers.o main.o passenger.o ride.o
SOURCE	= car.cpp driver.cpp drivers.cpp main.cpp passenger.cpp ride.cpp
HEADER	= car.h driver.h drivers.h passenger.h ride.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

car.o: car.cpp
	$(CC) $(FLAGS) car.cpp 

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp 

drivers.o: drivers.cpp
	$(CC) $(FLAGS) drivers.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

passenger.o: passenger.cpp
	$(CC) $(FLAGS) passenger.cpp 

ride.o: ride.cpp
	$(CC) $(FLAGS) ride.cpp 


clean:
	rm -f $(OBJS) $(OUT)