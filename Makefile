EXE = life
OBJS = main.c board.c sim.c
LIBS = -lcse30life
CFLAGS := -g -Og --std=gnu17 -L/home/linux/ieng6/cs30fa23/public/lib

.PHONY: clean

$(EXE): $(OBJS) 
	gcc -Wall -Wextra -o $@ $(CFLAGS) $(OBJS) $(LIBS)

clean :
	rm -f $(EXE)
