CFLAGS += -fPIC
WARNINGS = -Wall -Wextra -Wpedantic

PREFIX ?= /usr/local/bin

SRCS = errknow.c
OBJS = $(SRCS:.c=.o)
BINNAME = errknow

CFLAGS += $(WARNINGS)

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
