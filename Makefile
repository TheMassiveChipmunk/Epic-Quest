CC = g++
CFLAGS = -Wall -g -c
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-network
SRC = $(shell find *.cpp)
OBJS = $(SRC:.cpp=.o)
BIN = GameLib.a

all: $(BIN)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

$(BIN): $(OBJS)
	ar -rs $(BIN) $(OBJS)
	cp $(BIN) *.cpp *.hpp ./Debug/

clean:
	./BackUp.sh
	mv $(BIN) $(OBJS) *~ ./.Trash
