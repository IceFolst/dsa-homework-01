CC=g++
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET1 = main

SRCS1 = Source.cpp Flower.cpp

OBJS1 = $(SRCS1:.cpp=.o)

all: $(TARGET1)

$(TARGET1): $(OBJS1)
	$(CC) -o $(TARGET1) $(OBJS1) ${LDLIBS}

clean:
	rm $(OBJS1) $(TARGET1)
