#pragma once

#ifndef __cplusplus

#ifndef NUMLST_H
#define NUMLST_H

#ifndef _STDBOOL

typedef _Bool bool;

#endif // _STDBOOL

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
void toup(numlst**ptr);
void todown(numlst**ptr);
void totop(numlst**ptr);
void delup(numlst**ptr);
void deldown(numlst**ptr);
void addup(numlst**ptr);
void adddown(numlst**ptr);

#endif // NUMLST_H

#else // __cplusplus

#error This is a C program.

#endif // __cplusplus

