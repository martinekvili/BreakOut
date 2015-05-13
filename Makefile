BINARY = breakout
OBJECTS = ball.o ballview.o brick.o brickview.o game.o graphics.o pad.o padview.o vector.o view.o wall.o main.o
HEADERS = ball.h ballview.h brick.h brickview.h game.h graphics.h icollidable.h idrawable.h pad.h padview.h vector.h view.h wall.h


CC = g++
CFLAGS = -std=c++11 -O2 -Wall -Wdeprecated -pedantic
LDFLAGS = -lGL -lGLU -lglut

.PHONY: all clean

all: $(BINARY)

clean:
	rm -f $(BINARY) $(OBJECTS)

$(BINARY): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
