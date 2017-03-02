objects = test.o numlst.o

test: numlst.o test.o
numlst.o: numlst.c numlst.h
test.o: test.c

.PHONY : clean cleanall
clean :
	-rm $(objects)

cleanall:
	make clean
	-rm test


