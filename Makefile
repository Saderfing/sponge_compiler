# Directories
SRCDIR   = src
INCDIR   = $(wildcard $(SRCDIR)/*/)
PARDIR   = $(SRCDIR)/parser
OBJDIR   = obj
BINDIR   = bin

# Build modes
CC       = clang
CPPFLAGS = $(INCDIR:%=-I%)
CFLAGS   = -Wall -Wextra
LDFLAGS  = -ll -lm  # (libs includes always at the end)

LEX      = flex
LFLAGS   = -Cf

YACC     = bison
YFLAGS   = --header=$(PARFILE:%.y=%.h) -Wall

ifdef BUILD
CFLAGS   += -O3
else
CPPFLAGS += -g -DDEBUG=1
YFLAGS   += -td -g=automaton.dot -Wcounterexamples
CFLAGS   += -O0
endif

ifdef TEST
PRG      = $(SRCDIR)/test.c
else
PRG      = $(SRCDIR)/sc.c
endif

# Files
LEXFILE  = $(wildcard $(PARDIR)/*.l)
PARFILE  = $(wildcard $(PARDIR)/*.y)

LEXBUILD = $(LEXFILE:%.l=%.c)
PARBUILD = $(PARFILE:%.y=%.c)

SRC      = $(LEXBUILD) $(PARBUILD) $(wildcard $(SRCDIR)/*/*.c) $(PRG)
INC      = $(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/*/*.h)
OBJ      = $(SRC:%.c=%.o)
EXEC     = $(BINDIR)/$(notdir $(PRG:%.c=%))

# $(info $(SRC))
# $(info $(INC))
# $(info $(OBJ))
# $(info $(EXEC))

# Compile
.PHONY: all clean

all: $(EXEC)

%.c:%.l
	$(LEX) $(LFLAGS) -o $@ $<

%.c:%.y
	$(YACC) $(YFLAGS) --defines=$(patsubst %.c,%.h,$@) -o $@ $<

parser:$(LEXBUILD) $(PARBUILD)

$(EXEC):parser $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
	@echo \* Main program compiled successfully ! \*
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"

clean:
	-rm $(BINDIR)/* $(SRCDIR)/*/*.o $(SRCDIR)/*.o $(PARBUILD) $(PARFILE:%.y=%.h) $(LEXBUILD)