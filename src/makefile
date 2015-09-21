#!/bin/bash

CC=gcc

CFLAGS  = -c -g -W -Wall -I$(PROJ_INC) 
LFLAGS  = -g -W -Wall -I$(PROJ_INC) 

LDFLAGS = -L$(PROJ_LIB)

EXEPROJ = testMain
LIBOBJ  = test.o stack.o tail.o

.SUFFIXES : .c .o

.c.o :
		$(CC) $(CFLAGS) $<

all: $(EXEPROJ) 

$(EXEPROJ): $(LIBOBJ)
		$(CC) $(LFLAGS) -o $@ $(LIBOBJ) $(LDFLAGS)

install: $(EXEPROJ)
		mv $(EXEPROJ).exe $(PROJ_BIN)

clean:
		rm -f  $(EXEPROJ).exe *.o core

