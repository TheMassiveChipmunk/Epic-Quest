CC = g++
CFLAGS = -Wall -g -c
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system
SRC = $(shell find *.cpp)
OBJS = $(SRC:.cpp=.o)
BIN = Epic-Quest

all: $(BIN) $(SRC)

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@
	git add *.cpp
	git add *.hpp
	git add Makefile
	git commit -m "Updates"
	git push origin master

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJS) $(BIN)
