CC = g++
CFLAGS = -Wall -g -c
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system
MESSAGE = "Updates"
SRC = $(shell find *.cpp)
OBJS = $(SRC:.cpp=.o)
BIN = Epic-Quest

all: $(BIN) $(SRC)

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJS) $(BIN)

github:
	git add *.cpp
	git add *.hpp
	git add Makefile
	git commit -m "$MESSAGE"
	git push origin master
