CC = g++
CFLAGS = -Wall -g -c
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
SRC = $(shell ls *.cpp)
OBJS = $(SRC:.cpp=.o)
BIN = Epic_Quest

all: $(BIN) $(SRC) 

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJS) $(BIN)
