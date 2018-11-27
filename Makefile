CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD
EXEC = program
<<<<<<< HEAD
OBJECTS = main.o game/game.o player/player.o grid/grid.o block/block.o block/lblock.o block/starblock.o block/iblock.o block/oblock.o block/tblock.o block/jblock.o block/sblock.o block/zblock.o cell/cell.o level/level.o coord/coord.o
=======
OBJECTS = main.o game/game.o player/player.o grid/grid.o block/block.o cell/cell.o level/level0.o level/level.o
>>>>>>> master
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}


clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
