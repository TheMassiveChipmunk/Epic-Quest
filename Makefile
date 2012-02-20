CC = g++
CFLAGS = -Wall -g -c -std=c++0x
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system
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
	git add *.cpp *.hpp
	git commit -m "Updates"
	git push origin master
