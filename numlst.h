#pragma once

#ifndef __cplusplus

#ifndef NUMLST
#define NUMLST

#ifndef _STDBOOL

typedef _Bool bool;

#endif // _STDBOOL

typedef struct {
	void*stptr;
	char num;
	void*nxptr;
} numlst;

inline numlst**newlst(void) {
	numlst*ptr = malloc(sizeof(numlst)), **nptr = &ptr;
	(*nptr)->stptr = *nptr;
	(*nptr)->nxptr = *nptr;
	return nptr;
}

inline bool isend(numlst**ptr) {
	if ((*ptr)->stptr == *ptr || (*ptr)->nxptr == *ptr)return 1;
	return 0;
}

inline int getnum(numlst**ptr) {
	return (*ptr)->num;
}

inline void setnum(numlst**ptr, int num) {
	(*ptr)->num = num;
}

inline void toup(numlst**ptr) {
	*ptr = (*ptr)->stptr;
}

inline void todown(numlst**ptr) {
	*ptr = (*ptr)->nxptr;
}

inline void totop(numlst**ptr) {
	do toup(ptr);
	while (!isend(ptr));
}

#endif // NUMLST

#else // __cplusplus

#error This is a C program.

#endif // __cplusplus
