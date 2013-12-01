CC = gcc
program =  interface
#PATH += /usr/include/gtk2.0
LDLIBS = `pkg-config --libs gtk+-2.0`
CFLAGS = -Wall -g `pkg-config --cflags gtk+-2.0`

$(program):$(program).o
	$(CC) $(LDLIBS) $(program).o -o $(program)

$(promram).o:$(program).c
	$(CC) $(CFLAGS) -c $(program).c

clean :
	-rm -f $(program)
	-rm -f *.o
