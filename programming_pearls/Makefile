CC :=gcc 
CFLAGS := -g -Wall 
SOURCES := $(wildcard *.c)
TARGETS := $(patsubst %.c,%,$(SOURCES))

#define a function
define MAKE_EACH_SRC_BIN
$1:$1.c
	$(CC) $(CFLAGS) $< -o $@
endef

all:$(TARGETS)
	$(foreach target,$(TARGETS),$(call MAKE_EACH_SRC_BIN $(target)))

clean:
	rm -rf $(TARGETS)
