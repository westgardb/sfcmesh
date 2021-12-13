# Generic makefile for C/C++ projects with automatic dependencies

TARGET = sfcmesh

CC = gcc
CCFLAGS = -Wall -Wextra -MMD -MP

LDFLAGS = -lassimp

BUILDDIR = build
SRCDIR = src

SRCS = main.c reorder.c morton.c

OBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

default: debug

release: CCFLAGS += -O3
release: $(TARGET)

debug: CCFLAGS += -g
debug: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@ 

clean: 
	rm -f $(BUILDDIR)/*
	rm -f $(TARGET)

.PHONY: clean release debug 

-include $(DEPS)

