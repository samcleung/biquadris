#ifndef __LEVEL3_H__
#define __LEVEL3_H__

class Level3 {
public:
	Vector <Block *> createBlock() override;
	Level3(int seed); 
};

#endif
