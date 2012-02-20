#
# Makefile for 'Venom'.
#
# Type 'make' or 'make Venom' to create the binary.
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
default: Venom

Venom: $(OUT_DIR)/Engine.cpp.o $(OUT_DIR)/main.cpp.o $(OUT_DIR)/Painter.cpp.o $(OUT_DIR)/Util.cpp.o
	@echo -n 'Linking Venom... '
	@$(CC) $(CFLAGS) -o Venom $(OUT_DIR)/Engine.cpp.o $(OUT_DIR)/main.cpp.o $(OUT_DIR)/Painter.cpp.o $(OUT_DIR)/Util.cpp.o $(LIBS)
	@echo Done.

$(OUT_DIR)/Engine.cpp.o: Engine.cpp Engine.hpp Venom.hpp Util.hpp \
 Util.tcc
	@echo -n 'Compiling Engine.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Engine.cpp.o -c Engine.cpp
	@echo Done.

$(OUT_DIR)/main.cpp.o: main.cpp Venom.hpp Util.hpp Util.tcc Engine.hpp
	@echo -n 'Compiling main.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/main.cpp.o -c main.cpp
	@echo Done.

$(OUT_DIR)/Painter.cpp.o: Painter.cpp Painter.hpp Venom.hpp Util.hpp \
 Util.tcc
	@echo -n 'Compiling Painter.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Painter.cpp.o -c Painter.cpp
	@echo Done.

$(OUT_DIR)/Util.cpp.o: Util.cpp Util.hpp Venom.hpp Util.tcc
	@echo -n 'Compiling Util.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Util.cpp.o -c Util.cpp
	@echo Done.

run:
	./Venom 

debug:
	gdb ./Venom

clean:
	@echo -n 'Removing all temporary binaries... '
	@rm -f Venom $(OUT_DIR)/*.o
	@echo Done.

clear:
	@echo -n 'Removing all temporary binaries... '
	@rm -f Venom $(OUT_DIR)/*.o
	@echo Done.

