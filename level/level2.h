#ifndef __LEVEL2_H__
#define __LEVEL2_H__

class Level2 {
public:
	Vector <Block *> createBlock() override;
	Level2(int seed); 
};

#endif
