all: $(BUILD_DIR)/lib/libc.a

$(BUILD_DIR)/lib/libc.a: FORCE
	zig build -p $(BUILD_DIR)

FORCE: ;