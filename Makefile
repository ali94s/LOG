CC =gcc
DEBUG=-g
LIBS = -lpthread

file=test
test:ali-log.c ali-test.c
	$(CC) -o $@ $^ $(LIBS) 
debug:ali-log.c ali-test.c
	$(CC) -o $@ $^ $(DEBUG) $(LIBS)
clean:
	rm test debug
