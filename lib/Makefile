AR = ar
CC = gcc
LT = liberf

CFILES = $(shell find -name '*.c')
OBJS = $(addsuffix .o, $(basename $(CFILES)))

CFLAGS = -Wall -Werror -Wextra -O3

all: $(LT).a

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(LT).a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

clean:
	$(RM) $(LT).a $(OBJS)
