#ifndef MATH_H
#define MATH_H

#include "../common.h"

int pow(u32 base, u32 x);

//
//	IMPLEMENTATION
//

int pow(u32 base, u32 x) {
	u32 res = 1;
	for (int i = 0; i < x; i++)
		res *= base;
	return res;
}

#endif // MATH_H