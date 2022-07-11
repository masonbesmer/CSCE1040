OBJS	= student.o studentmain.o
SOURCE	= student.cpp studentmain.cpp
HEADER	= student.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

student.o: student.cpp
	$(CC) $(FLAGS) student.cpp 

studentmain.o: studentmain.cpp
	$(CC) $(FLAGS) studentmain.cpp 


clean:
	rm -f $(OBJS) $(OUT)