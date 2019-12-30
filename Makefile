#!/usr/bin/make 


CC     = gcc 
CFLAGS = -I -Wextra 
LCURL  = -lcurl
EXEC   = t_at
SRC    = $(wildcard *.c)
OBJ    = $(SRC:.c=.o)

all	:$(EXEC) 

$(EXEC) :$(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS) $(LCURL)

w32tat.o : t_at.h
%.o 	:%.c
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY  : clean mproper

clean  	:
	rm *.o

mproper : clean 
	rm  $(EXEC)

