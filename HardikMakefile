CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD -L/usr/X11R6/lib
EXEC = program
OBJECTS = main.o game/game.o player/player.o grid/grid.o block/block.o block/lblock.o block/starblock.o block/iblock.o block/oblock.o block/tblock.o block/jblock.o block/sblock.o block/zblock.o cell/cell.o level/level.o level/level0.o coord/coord.o command/command.o level/level2.o level/level1.o level/level3.o level/level4.o graphics/window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11


clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
