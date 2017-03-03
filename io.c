#ifndef IO_C
#define IO_C

#include<stdio.h>

#include"io.h"

numlst**input(void) {
	numlst**ptr = newlst();
	char input;
	while (input = getchar() != '\n') {
		input -= '0';
		setnum(ptr, input);
		adddown(ptr);
		todown(ptr);
	}
	toup(ptr);
	deldown(ptr);
	totop(ptr);
	return ptr;
}

void printlst(numlst**ptr) {
	totop(ptr);
	do printf("%d", getnum(ptr));
	while (todown(ptr));
}

#endif /* IO_C */

#ifdef __cplusplus

#error This program is written in C.

#endif /* __cplusplus */

