#
# Makefile for 'Epic-Quest'.
#
# Type 'make' or 'make Epic-Quest' to create the binary.
# Type 'make clean' or 'make clear' to delete all temporaries.
# Type 'make run' to execute the binary.
# Type 'make debug' to debug the binary using gdb(1).
#

# build target specs
CC = g++
CFLAGS = -Wall -g
OUT_DIR = release_build
LIBS = -lsfml-system -lsfml-window -lsfml-graphics

# first target entry is the target invoked when typing 'make'
default: Epic-Quest

Epic-Quest: $(OUT_DIR)/main.cpp.o $(OUT_DIR)/Map.cpp.o $(OUT_DIR)/Structs.cpp.o $(OUT_DIR)/TileSet.cpp.o $(OUT_DIR)/Util.cpp.o
	@echo -n 'Linking Epic-Quest... '
	@$(CC) $(CFLAGS) -o Epic-Quest $(OUT_DIR)/main.cpp.o $(OUT_DIR)/Map.cpp.o $(OUT_DIR)/Structs.cpp.o $(OUT_DIR)/TileSet.cpp.o $(OUT_DIR)/Util.cpp.o $(LIBS)
	@echo Done.

$(OUT_DIR)/main.cpp.o: main.cpp Map.hpp Util.hpp TileSet.hpp Structs.hpp
	@echo -n 'Compiling main.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/main.cpp.o -c main.cpp
	@echo Done.

$(OUT_DIR)/Map.cpp.o: Map.cpp Map.hpp Util.hpp TileSet.hpp Structs.hpp
	@echo -n 'Compiling Map.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Map.cpp.o -c Map.cpp
	@echo Done.

$(OUT_DIR)/Structs.cpp.o: Structs.cpp Structs.hpp
	@echo -n 'Compiling Structs.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Structs.cpp.o -c Structs.cpp
	@echo Done.

$(OUT_DIR)/TileSet.cpp.o: TileSet.cpp TileSet.hpp Util.hpp Structs.hpp
	@echo -n 'Compiling TileSet.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/TileSet.cpp.o -c TileSet.cpp
	@echo Done.

$(OUT_DIR)/Util.cpp.o: Util.cpp Util.hpp
	@echo -n 'Compiling Util.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Util.cpp.o -c Util.cpp
	@echo Done.

run:
	./Epic-Quest 

debug:
	gdb ./Epic-Quest

clean:
	@echo -n 'Removing all temporary binaries... '
	@rm -f Epic-Quest $(OUT_DIR)/*.o
	@echo Done.

clear:
	@echo -n 'Removing all temporary binaries... '
	@rm -f Epic-Quest $(OUT_DIR)/*.o
	@echo Done.

github:
	git add *.cpp *.hpp *.txt
	git commit -m "Updates"
	git push origin master
