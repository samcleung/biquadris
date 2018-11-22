#ifndef __LEVEL0_H__
#define __LEVEL0_H__

class Level0 {
public:
	Vector <Block *> createBlock() override;
	Level0(int seed); 
};

#endif
