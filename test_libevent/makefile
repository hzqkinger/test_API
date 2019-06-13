INCLUDE=/usr/lib/libevent/include
LIB_LIBRARY=/usr/lib/libevent/lib

src1 = libevent.c
src2 = timer.c

event:$(src1)
	g++ -o $@ $^ -I$(INCLUDE) -L$(LIB_LIBRARY) -levent

.PHONY:clean
clean:
	rm -rf event
