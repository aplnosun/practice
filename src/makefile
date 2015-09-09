#!/bin/bash

CC=gcc

CFLAGS  = -c -g -W -Wall -I$(PROJ_INC) 
LFLAGS  = -g -W -Wall -I$(PROJ_INC) 

LDFLAGS = -L$(PROJ_LIB)

EXEPROJ = testMain
LIBOBJ  = stack.o test.o

.SUFFIXES : .c .o

.c.o :
		$(CC) $(CFLAGS) $<

all:$(EXEPROJ) 

$(EXEPROJ): $(LIBOBJ)
		$(CC) $(LFLAGS) -o $@ $(LIBOBJ) $(LDFLAGS)

install:
		mv $(EXEPROJ) $(PROJ_BIN)

clean :
		rm -f  $(EXEPROJ) *.o core

