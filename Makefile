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
CFLAGS = -O3 -std=c++0x -Wall -g
OUT_DIR = release_build
LIBS = -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio

# first target entry is the target invoked when typing 'make'
default: Epic-Quest

Epic-Quest: $(OUT_DIR)/Box.cpp.o $(OUT_DIR)/Bullet.cpp.o $(OUT_DIR)/Character.cpp.o $(OUT_DIR)/Enemy.cpp.o $(OUT_DIR)/Engine.cpp.o $(OUT_DIR)/Level.cpp.o $(OUT_DIR)/main.cpp.o $(OUT_DIR)/Player.cpp.o $(OUT_DIR)/Point.cpp.o $(OUT_DIR)/Util.cpp.o
	@echo -n 'Linking Epic-Quest... '
	@$(CC) $(CFLAGS) -o Epic-Quest $(OUT_DIR)/Box.cpp.o $(OUT_DIR)/Bullet.cpp.o $(OUT_DIR)/Character.cpp.o $(OUT_DIR)/Enemy.cpp.o $(OUT_DIR)/Engine.cpp.o $(OUT_DIR)/Level.cpp.o $(OUT_DIR)/main.cpp.o $(OUT_DIR)/Player.cpp.o $(OUT_DIR)/Point.cpp.o $(OUT_DIR)/Util.cpp.o $(LIBS)
	@echo Done.

$(OUT_DIR)/Box.cpp.o: Box.cpp Box.hpp Point.hpp
	@echo -n 'Compiling Box.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Box.cpp.o -c Box.cpp
	@echo Done.

$(OUT_DIR)/Bullet.cpp.o: Bullet.cpp Bullet.hpp Box.hpp Point.hpp Util.hpp \
 Util.tcc Engine.hpp
	@echo -n 'Compiling Bullet.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Bullet.cpp.o -c Bullet.cpp
	@echo Done.

$(OUT_DIR)/Character.cpp.o: Character.cpp Character.hpp Util.hpp Box.hpp \
 Point.hpp Util.tcc Engine.hpp Bullet.hpp
	@echo -n 'Compiling Character.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Character.cpp.o -c Character.cpp
	@echo Done.

$(OUT_DIR)/Enemy.cpp.o: Enemy.cpp Enemy.hpp Util.hpp Box.hpp Point.hpp \
 Util.tcc Engine.hpp Character.hpp Bullet.hpp
	@echo -n 'Compiling Enemy.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Enemy.cpp.o -c Enemy.cpp
	@echo Done.

$(OUT_DIR)/Engine.cpp.o: Engine.cpp Engine.hpp Util.hpp Box.hpp Point.hpp \
 Util.tcc
	@echo -n 'Compiling Engine.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Engine.cpp.o -c Engine.cpp
	@echo Done.

$(OUT_DIR)/Level.cpp.o: Level.cpp Level.hpp Util.hpp Box.hpp Point.hpp \
 Util.tcc Bullet.hpp Engine.hpp Enemy.hpp Character.hpp Player.hpp
	@echo -n 'Compiling Level.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Level.cpp.o -c Level.cpp
	@echo Done.

$(OUT_DIR)/main.cpp.o: main.cpp Level.hpp Util.hpp Box.hpp Point.hpp \
 Util.tcc Bullet.hpp Engine.hpp Enemy.hpp Character.hpp Player.hpp
	@echo -n 'Compiling main.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/main.cpp.o -c main.cpp
	@echo Done.

$(OUT_DIR)/Player.cpp.o: Player.cpp Player.hpp Engine.hpp Util.hpp \
 Box.hpp Point.hpp Util.tcc Bullet.hpp Character.hpp
	@echo -n 'Compiling Player.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Player.cpp.o -c Player.cpp
	@echo Done.

$(OUT_DIR)/Point.cpp.o: Point.cpp Point.hpp
	@echo -n 'Compiling Point.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Point.cpp.o -c Point.cpp
	@echo Done.

$(OUT_DIR)/Util.cpp.o: Util.cpp Util.hpp Box.hpp Point.hpp Util.tcc
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

