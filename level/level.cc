#include "level.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

Level getLevel(int level) {
    switch (level) {
        case 0: return new Level0();
        case 1: return new Level1();
        case 2: return new Level2();
        case 3: return new Level3();
        case 4: return new Level4();
        case default: return nullptr;
    }
}

Level::Level(){}
Level::~Level(){}
