#ifndef STRING_H
#define STRING_H

#include "../common.h"

u32 string_len(char* str);

//
// IMPLEMENTATION
//

u32 string_len(char* str) {
	u32 len;
	while (str[len] != '\0')
		len++;
	return len;
}

#endif // STRING_H