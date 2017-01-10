CC = g++
#CFLAGS = -g -O2 -Wfatal-errors -Wshadow -Wall -I/usr/local/include 
CFLAGS = -g -O2 -std=c++11 -pthread -DFHE_THREADS -DFHE_DCRT_THREADS -DFHE_BOOT_THREADS
#CFLAGS = -g -O2 -std=c++11 -pthread
#CFLAGS = -g -O2 -std=c++11 

$(info HElib requires NTL version 9.4.0 or higher, see http://shoup.net/ntl)
$(info If you get compilation errors, try to add/remove -std=c++11 in Makefile)
$(info )

LD = g++
AR = ar
ARFLAGS=rv
GMP=-lgmp 
LDLIBS = -L/usr/local/lib -lntl $(GMP) -lm

HEADER = PAlgebra.h NumbTh.h timing.h 

OBJ = NumbTh.o timing.o PAlgebra.o

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $<

lib.a:$(OBJ)
	$(AR) $(ARFLAGS) lib.a $(OBJ)

Test_x:Test.cpp lib.a
	$(CC) $(CFLAGS) -o Test_x Test.cpp lib.a $(LDLIBS)

clean:
	rm -f *.o *_x *_x.exe *.a core.*
	rm -rf *.dSYM

info:
	: HElib require NTL version 9.4.0 or higher
	: Compilation flags are 'CFLAGS=$(CFLAGS)'
	: If errors occur, try adding/removing '-std=c++11' in Makefile
	:
