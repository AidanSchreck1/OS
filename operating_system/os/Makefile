BUILD_DIR=../build
OS=$(BUILD_DIR)/os

CFLAGS+=-ffreestanding -nostdlib -gdwarf-4 -m32 -ggdb3

OS_SRCS := $(wildcard *.c)
OS_OBJS := $(patsubst %.c, $(OS)/%.o, $(OS_SRCS))


all: $(OS)

$(OS)/%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(OS)/%.o: $(OS_OBJS)
	ld -m elf_i386 -T os.lds $(OS_OBJS) -o $@.elf





clean: 
	rm $(OS)/o*
