all: lib/libc.a

lib/libc.a: FORCE
	zig build -p .

FORCE: ;