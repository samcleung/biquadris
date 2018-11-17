CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD
EXEC = main
OBJECTS = main.o game/game.o player/player.o grid/grid.o block/block.o cell/cell.o level/level.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}


clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
