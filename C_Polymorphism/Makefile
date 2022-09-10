BINARY = output
CODEDIRS = . lib
INCDIRS = . .\include

CC = gcc
OPT = -O0
DEPFLAGS = -MP -MD
CFLAGS = -Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

CFILES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
OBJFILES = $(patsubst %.c,%.o,$(CFILES))
DEPFILES = $(patsubst %.c,%.d,$(CFILES))


all: $(BINARY)

$(BINARY): $(OBJFILES)
			$(CC) -o $@ $^

%.o: %.c
			$(CC) $(CFLAGS) -c -o $@ $<

clean:
			del /f /s *.exe *.o *.d