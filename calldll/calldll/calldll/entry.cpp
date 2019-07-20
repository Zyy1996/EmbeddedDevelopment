#include "../circle/iadd.h"
#include "../circle/imul.h"
#include "../cgrid/csize.h"
#pragma  comment(lib,"circle.lib")
#pragma  comment(lib,"cgrid.lib")

void main()
{   
	int c = add(1,2);
	c *= mul(3,4);
	double cnt = calcnt(10,2);
}