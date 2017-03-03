objects = test.o numlst.o io.o

test: numlst.o test.o io.o
numlst.o: numlst.c numlst.h
test.o: test.c
io.o: io.c io.h

.PHONY : clean cleanall
clean :
	-rm $(objects)

cleanall:
	make clean
	-rm test


