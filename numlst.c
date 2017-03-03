#ifndef NUMLST_C
#define NUMLST_C

#include"numlst.h"

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

bool toup(numlst**ptr) {
	if(istop(ptr))return 0;
	*ptr = (*ptr)->stptr;
	return 1;
}

bool todown(numlst**ptr) {
	if(isbottom(ptr))return 0;
	*ptr = (*ptr)->nxptr;
	return 1;
}

void totop(numlst**ptr) {
	while (toup(ptr));
}

void tobottom(numlst**ptr) {
	while (todown(ptr));
}

void delup(numlst**ptr) {
	if (istop(ptr) && isbottom(ptr)) {
		free(*ptr);
		return;
	}
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
	if (istop(ptr) && isbottom(ptr)) {
		free(*ptr);
		return;
	}
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

void delst(numlst**ptr) {
	totop(ptr);
	while (todown(ptr))free((*ptr)->stptr);
	free(*ptr);
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

void flip(numlst**ptr) {
	numlst**nptr = newlst();
	tobottom(ptr);
	do {
		setnum(nptr, getnum(ptr));
		adddown(nptr);
		todown(nptr);
	}
	while (toup(ptr));
	delst(ptr);
	*ptr = *nptr;
}

void cutzero(numlst**ptr) {
	totop(ptr);
	while (!getnum(ptr)) {
		if (todown(ptr))delup(ptr);
		else break;
	}
}

#endif /* NUMLST_C */

#ifdef __cplusplus

#error This program is written in C.

#endif /* __cplusplus */

