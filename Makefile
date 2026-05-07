CC        = gcc
CFLAGS    = -Wall -Wextra -g -Iinclude
GTK_FLAGS = $(shell pkg-config --cflags --libs gtk+-3.0)

SRC_DIR   = src
OBJ_DIR   = obj

SRC       = $(SRC_DIR)/analyzer.c $(SRC_DIR)/cli.c $(SRC_DIR)/hashmap.c $(SRC_DIR)/parser.c
OBJ       = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Default: build CLI version
all: log_analyzer

log_analyzer: $(OBJ_DIR)/main.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# GUI version (requires GTK3)
gui: $(OBJ) $(OBJ_DIR)/gui.o
	$(CC) $(CFLAGS) -o log_analyzer_gui $^ $(GTK_FLAGS)

$(OBJ_DIR)/gui.o: $(SRC_DIR)/gui.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< $(GTK_FLAGS) -o $@

# Compile object files into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj/ directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build and run CLI with sample log
run: log_analyzer
	./log_analyzer data/sample.log

# Remove compiled files
clean:
	rm -rf $(OBJ_DIR) log_analyzer log_analyzer_gui

.PHONY: all gui run clean