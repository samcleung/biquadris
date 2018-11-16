#ifndef __LEVEL4_H__
#define __LEVEL4_H__

class Level4 {
public:
	Vector <Block *> createBlock() override;
	Level4(int seed); 
};

#endif
