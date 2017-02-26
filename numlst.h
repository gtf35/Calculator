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
	return *nptr;
}

inline bool isend(numlst**ptr) {
	if ((*ptr)->stptr == *ptr || (*ptr)->nxptr == *ptr)return 1;
	return 0;
}

inline bool istop(numlst**ptr) {
	if ((*ptr)->stptr == *ptr)return 1;
	return 0;
}

inline bool isbottom(numlst**ptr) {
	if ((*ptr)->nxptr == *ptr)return 1;
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

inline void delup(numlst**ptr) {
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

inline void deldown(numlst**ptr) {
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

inline void addup(numlst**ptr) {
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

inline void adddown(numlst**ptr) {
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

#endif // NUMLST

#else // __cplusplus

#error This is a C program.

#endif // __cplusplus
