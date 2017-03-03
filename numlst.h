#pragma once

#ifndef NUMLST_H
#define NUMLST_H

#include<stdlib.h>

#ifndef _STDBOOL

typedef _Bool bool;

#endif /* _STDBOOL */

typedef struct {
	void*stptr;
	char num;
	void*nxptr;
} numlst;

numlst**newlst(void);

bool isend(numlst**ptr);
bool istop(numlst**ptr);
bool isbottom(numlst**ptr);

int getnum(numlst**ptr);
void setnum(numlst**ptr, int num);

bool toup(numlst**ptr);
bool todown(numlst**ptr);
void totop(numlst**ptr);
void tobottom(numlst**ptr);

void delup(numlst**ptr);
void deldown(numlst**ptr);
void delst(numlst**ptr);

void addup(numlst**ptr);
void adddown(numlst**ptr);

void flip(numlst**ptr);
void cutzero(numlst**ptr);

#endif /* NUMLST_H */

#ifdef __cplusplus

#error This program is written in C.

#endif /* __cplusplus */

