INCLUDE_DIRS := .
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := bst.o mainbst.o
DEPS 		 := ${INCLUDE_DIRS}/bst.h

.PHONY: clean all

all: bst.o mainbst.o bst.out

clean:
	rm $(OBJS) bst.out

bst.o: bst.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainbst.o: mainbst.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

bst.out: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)