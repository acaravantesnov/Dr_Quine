# Source files
COLLEEN_SRC = Colleen/Colleen.c
GRACE_SRC = Grace/Grace.c
SULLY_SRC = Sully/Sully.c

# Executables
COLLEEN_BIN = Colleen/Colleen
GRACE_BIN = Grace/Grace
SULLY_BIN = Sully/Sully

# All executables
ALL_BINS = $(COLLEEN_BIN) $(GRACE_BIN) $(SULLY_BIN)

# Directory for object files
OBJ_DIR = obj

# Object file paths
COLLEEN_OBJ = $(OBJ_DIR)/Colleen.o
GRACE_OBJ = $(OBJ_DIR)/Grace.o
SULLY_OBJ = $(OBJ_DIR)/Sully.o

# All object files
ALL_OBJS = $(COLLEEN_OBJ) $(GRACE_OBJ) $(SULLY_OBJ)

CC = clang
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re obj_dir

all: obj_dir $(ALL_BINS)

# Rule to ensure that the obj dirctory exists
obj_dir:
	@mkdir -p $(OBJ_DIR)

# Rule to create executables (link).
# Make ensures the object files are built as prerequisites before linking.
# - $@ is the target (Colleen/Colleen, Grace/Grace or Sully/Sully)
# - $< is the first prerequisite (obj/Colleen.o, obj/Grace.o or obj Sully.o)
$(COLLEEN_BIN): $(COLLEEN_OBJ)
	@echo "Linking $@"
	@$(CC) $(CFLAGS) -o $@ $<

$(GRACE_BIN): $(GRACE_OBJ)
	@echo "Linking $@"
	@$(CC) $(CFLAGS) -o $@ $<

$(SULLY_BIN): $(SULLY_OBJ)
	@echo "Linking $@"
	@$(CC) $(CFLAGS) -o $@ $<

# Rules to create object files (compile).
# The output path for the object file now includes the OBJ_DIR.
$(COLLEEN_OBJ): $(COLLEEN_SRC)
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(GRACE_OBJ): $(GRACE_SRC)
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(SULLY_OBJ): $(SULLY_SRC)
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) -c $< -o $@

# Target to clean up object files
clean:
	@echo 'Cleaning object files...'
	@rm -f $(ALL_OBJS)
	@echo 'Removing obj directory...'
	@rm -rf $(OBJ_DIR)

# Target to clean up all generated files (objects, executables, and the obj directory)
fclean: clean
	@echo 'Cleaning executables...'
	@rm -f $(ALL_BINS)

# Target to re-build everything (clean all, then build all)
re: fclean all
