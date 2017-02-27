#include<stdlib.h>

#ifndef __cplusplus

#ifndef NUMLST_C
#define NUMLST_C

#ifndef _STDBOOL

typedef _Bool bool;

#endif // _STDBOOL

typedef struct {
	void*stptr;
	char num;
	void*nxptr;
} numlst;

numlst**newlst(void) {
	numlst**nptr = malloc(sizeof(numlst*));
	*nptr = malloc(sizeof(numlst));
	(*nptr)->stptr = *nptr;
	(*nptr)->nxptr = *nptr;
	return nptr;
}

bool isend(numlst**ptr) {
	if ((*ptr)->stptr == *ptr || (*ptr)->nxptr == *ptr)return 1;
	return 0;
}

bool istop(numlst**ptr) {
	if ((*ptr)->stptr == *ptr)return 1;
	return 0;
}

bool isbottom(numlst**ptr) {
	if ((*ptr)->nxptr == *ptr)return 1;
	return 0;
}

int getnum(numlst**ptr) {
	return (*ptr)->num;
}

void setnum(numlst**ptr, int num) {
	(*ptr)->num = num;
}

void toup(numlst**ptr) {
	*ptr = (*ptr)->stptr;
}

void todown(numlst**ptr) {
	*ptr = (*ptr)->nxptr;
}

void totop(numlst**ptr) {
	do toup(ptr);
	while (!isend(ptr));
}

void delup(numlst**ptr) {
	toup(ptr);
	if (isend(ptr)) {
		todown(ptr);
		free((*ptr)->stptr);
		(*ptr)->stptr = *ptr;
	}
	else {
		todown(ptr);
		numlst*ststptr = ((numlst*)(*ptr)->stptr)->stptr;
		ststptr->nxptr = *ptr;
		(*ptr)->stptr = ststptr;
	}
}

void deldown(numlst**ptr) {
	todown(ptr);
	if (isend(ptr)) {
		toup(ptr);
		free((*ptr)->nxptr);
		(*ptr)->nxptr = *ptr;
	}
	else {
		toup(ptr);
		numlst*nxnxptr = ((numlst*)(*ptr)->nxptr)->nxptr;
		nxnxptr->stptr = *ptr;
		(*ptr)->nxptr = nxnxptr;
	}
}

void addup(numlst**ptr) {
	numlst*nptr = malloc(sizeof(numlst));
	nptr->nxptr = *ptr;
	if (istop(ptr)) {
		nptr->stptr = nptr;
	}
	else {
		((numlst*)((*ptr)->stptr))->nxptr = nptr;
		nptr->stptr = (numlst*)((*ptr)->stptr);
	}
	(*ptr)->stptr = nptr;
}

void adddown(numlst**ptr) {
	numlst*nptr = malloc(sizeof(numlst));
	nptr->stptr = *ptr;
	if (isbottom(ptr)) {
		nptr->nxptr = nptr;
	}
	else {
		((numlst*)((*ptr)->nxptr))->stptr = nptr;
		nptr->nxptr = (numlst*)((*ptr)->nxptr);
	}
	(*ptr)->nxptr = nptr;
}

#endif // NUMLST_C

#else // __cplusplus

#error This is a C program.

#endif // __cplusplus

