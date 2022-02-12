CC = gcc

all:
	@$(MAKE) -C lib/
	@$(CC) -o erf erf.c -Llib/ -lerf

clean:
	@$(RM) erf
	@$(MAKE) -C lib/ clean
