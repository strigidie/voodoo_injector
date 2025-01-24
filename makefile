TARGET := voodoo_injector

BINARY_DIR := ./bin
BUILD_DIR  := ./build
HEADER_DIR := ./include
SOURCE_DIR := ./src

HEADER_FILES := $(shell find $(HEADER_DIR) -name '*.h')
SOURCE_FILES := $(shell find $(SOURCE_DIR) -name '*.c')
OBJECT_FILES := $(SOURCE_FILES:%=$(BINARY_DIR)/%.o)

CC     := gcc
CFLAGS := -Wall -Wextra $(addprefix -I, $(HEADER_DIR)) 

# ------------------------------------------------------------------------------
# compiler rule
# ------------------------------------------------------------------------------
all : $(BUILD_DIR)/$(TARGET)
$(BUILD_DIR)/$(TARGET) : $(OBJECT_FILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OBJECT_FILES) -o $@

$(BINARY_DIR)/%.c.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ------------------------------------------------------------------------------
# clean rule
# ------------------------------------------------------------------------------
clean :
	@rm -Rf $(BINARY_DIR)

# ------------------------------------------------------------------------------
# clear rule
# ------------------------------------------------------------------------------
clear :
	@rm -Rf $(BUILD_DIR) $(BINARY_DIR)

# ------------------------------------------------------------------------------
# phony rules
# ------------------------------------------------------------------------------
.PHONY: all clean clear 
