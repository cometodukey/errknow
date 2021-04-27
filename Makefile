CFLAGS += -fPIC -std=c99
CFLAGS += -Wall -Wextra -Wpedantic

# CFLAGS += -g -fsanitize=address,undefined -pg

ifeq ($(NOWERROR), 1)
CFLAGS +=
else
CFLAGS += -Werror
endif

PREFIX ?= /usr/local/bin

SRCS = errknow.c
OBJS = $(SRCS:.c=.o)

BINNAME = errknow

$(BINNAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: install
install: $(BINNAME)
	cp -f $(BINNAME) $(PREFIX)/$(BINNAME)

.PHONY: uninstall
uninstall:
	rm -f $(BINNAME) $(PREFIX)/$(BINNAME)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINNAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
