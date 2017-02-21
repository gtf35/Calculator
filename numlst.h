#pragma once

typedef struct {
	void*stptr;
	char num;
	void*nxptr;
} numlst;

inline void toup(numlst*ptr) {
	ptr = ptr->stptr;
}

inline void todown(numlst*ptr) {
	ptr = ptr->nxptr;
}

inline void totop(numlst*ptr) {
	while (ptr->stptr != ptr)ptr = ptr->stptr;
}

inline void tobottom(numlst*ptr) {
	while (ptr->nxptr != ptr)ptr = ptr->nxptr;
}

inline void delup(numlst*ptr) {
	numlst*dptr = ptr->stptr;
	if (((numlst*)(ptr->stptr))->nxptr != ptr->nxptr)ptr->nxptr = ((numlst*)(ptr->nxptr))->nxptr;
	else ptr->nxptr = ptr;
	((numlst*)(ptr->nxptr))->nxptr = ptr;
	free(dptr);
}

inline void deldown(numlst*ptr) {
	numlst*dptr = ptr->nxptr;
	if (((numlst*)(ptr->nxptr))->stptr != ptr->stptr)ptr->stptr = ((numlst*)(ptr->stptr))->stptr;
	else ptr->stptr = ptr;
	((numlst*)(ptr->stptr))->stptr = ptr;
	free(dptr);
}

inline void delst(numlst*ptr) {
	totop(ptr);
	while (ptr != ptr->nxptr) {
		todown(ptr);
		delup(ptr);
	}
	free(ptr);
}

inline void adddown(numlst*ptr) {
	numlst*nptr = malloc(sizeof(numlst));
	nptr->stptr = ptr;
	if (ptr->nxptr != ptr) {
		nptr->nxptr = ptr->nxptr;
		((numlst*)ptr->nxptr)->stptr = nptr;
	}
	else nptr->nxptr = nptr;
	ptr->nxptr = nptr;
}

inline void addup(numlst*ptr) {
	numlst*nptr = malloc(sizeof(numlst));
	nptr->nxptr = ptr;
	if (ptr->stptr != ptr) {
		nptr->stptr = ptr->stptr;
		((numlst*)ptr->stptr)->nxptr = nptr;
	}
	else nptr->stptr = nptr;
	ptr->stptr = nptr;
}

inline void cut0(numlst*ptr) {
	totop(ptr);
	if (!(ptr->num) && ptr != ptr->nxptr) {
		todown(ptr);
		delup(ptr);
	}
}
