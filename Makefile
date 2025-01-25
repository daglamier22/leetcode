CC=clang
CFLAGS=-g -Wall

OBJ_DIR=obj
BIN_DIR=bin
EASY_DIR=easy
EASY_SRCS=$(shell find $(EASY_DIR) -name "*.c")
EASY_OBJS=$(patsubst $(EASY_DIR)/%.c,$(OBJ_DIR)/%.o, $(EASY_SRCS))

MEDIUM_DIR=medium
MEDIUM_SRCS=$(shell find $(MEDIUM_DIR) -name "*.c")
MEDIUM_OBJS=$(patsubst $(MEDIUM_DIR)/%.c,$(OBJ_DIR)/%.o, $(MEDIUM_SRCS))

HARD_DIR=hard
HARD_SRCS=$(shell find $(HARD_DIR) -name "*.c")
HARD_OBJS=$(patsubst $(HARD_DIR)/%.c,$(OBJ_DIR)/%.o, $(HARD_SRCS))

SRCS=$(EASY_SRCS) $(MEDIUM_SRCS) $(HARD_SRCS)
OBJS=$(EASY_OBJS) $(MEDIUM_OBJS) $(HARD_OBJS)
BINS=$(patsubst $(OBJ_DIR)/%.o,$(BIN_DIR)/%, $(OBJS))

all: scaffold $(OBJS) $(BINS)
	echo $(BINS)
	echo $(EASY_SRCS)
	echo $(EASY_OBJS)
	echo $(MEDIUM_SRCS)
	echo $(MEDIUM_OBJS)
	echo $(HARD_SRCS)
	echo $(HARD_OBJS)

scaffold:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

# $(OBJ_DIR)/%.o: $(EASY_DIR)/%.c $(MEDIUM_DIR)/%.c
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $< -c -o $@

$(BINS): $(OBJS)
	$(CC) $(CFLAGS) $< -o $@

run: %
	@ ./$@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
