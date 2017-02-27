#include<stdio.h>
#include<stdlib.h>

#include"numlst.h"

int main(void) {
	numlst**ptr = newlst();
	printf("address:0x%p\n", *ptr);
	printf("istop():%d isbottom():%d isend():%d\n", istop(ptr), isbottom(ptr), isend(ptr));
	setnum(ptr, 1);
	printf("set num to 1.\nnum is now %d.\n", getnum(ptr));
	setnum(ptr, 2);
	printf("set num to 2.\nnum is now %d.\n", getnum(ptr));
	addup(ptr);
	printf("addup()\n");
	printf("istop():%d isbottom():%d isend():%d\n", istop(ptr), isbottom(ptr), isend(ptr));
	getchar();
}

