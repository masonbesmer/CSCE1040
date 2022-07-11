OBJS	= driver.o drivers.o main.o passenger.o ride.o rides.o
SOURCE	= driver.cpp drivers.cpp main.cpp passenger.cpp ride.cpp rides.cpp
HEADER	= driver.h drivers.h passenger.h ride.h rides.h
#DAT    = drivers.dat passengers.dat rides.dat
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