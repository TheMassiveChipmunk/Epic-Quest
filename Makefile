#
# Makefile for 'Engine'.
#
# Type 'make' or 'make Engine' to create the binary.
# Type 'make clean' or 'make clear' to delete all temporaries.
# Type 'make run' to execute the binary.
# Type 'make debug' to debug the binary using gdb(1).
#

# build target specs
CC = g++
CFLAGS = -O3 -Wall -g -std=c++0x
OUT_DIR = release_build
LIBS = -lsfml-window -lsfml-graphics

# first target entry is the target invoked when typing 'make'
default: Engine

Engine: $(OUT_DIR)/Box.cpp.o $(OUT_DIR)/main.cpp.o $(OUT_DIR)/Point.cpp.o $(OUT_DIR)/Util.cpp.o
	@echo -n 'Linking Engine... '
	@$(CC) $(CFLAGS) -o Engine $(OUT_DIR)/Box.cpp.o $(OUT_DIR)/main.cpp.o $(OUT_DIR)/Point.cpp.o $(OUT_DIR)/Util.cpp.o $(LIBS)
	@echo Done.

$(OUT_DIR)/Box.cpp.o: Box.cpp Box.hpp Venom.hpp Point.hpp
	@echo -n 'Compiling Box.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Box.cpp.o -c Box.cpp
	@echo Done.

$(OUT_DIR)/main.cpp.o: main.cpp Venom.hpp Point.hpp
	@echo -n 'Compiling main.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/main.cpp.o -c main.cpp
	@echo Done.

$(OUT_DIR)/Point.cpp.o: Point.cpp Point.hpp Venom.hpp
	@echo -n 'Compiling Point.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Point.cpp.o -c Point.cpp
	@echo Done.

$(OUT_DIR)/Util.cpp.o: Util.cpp Util.hpp Venom.hpp Util.tcc
	@echo -n 'Compiling Util.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Util.cpp.o -c Util.cpp
	@echo Done.

run:
	./Engine 

debug:
	gdb ./Engine

clean:
	@echo -n 'Removing all temporary binaries... '
	@rm -f Engine $(OUT_DIR)/*.o
	@echo Done.

clear:
	@echo -n 'Removing all temporary binaries... '
	@rm -f Engine $(OUT_DIR)/*.o
	@echo Done.

