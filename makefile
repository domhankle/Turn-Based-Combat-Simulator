INC_DIR_FLAGS:=$(wildcard -Iinclude/*/)
CC=g++
CCFLAGS=-Wall -Wextra -pedantic -fsanitize=leak,address -g $(INC_DIR_FLAGS)

SRCDIR=./src
OBJDIR=./obj

SRCS:=$(wildcard $(SRCDIR)/*/*.cpp)
OBJS:=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))
DEPS:=$(OBJS:.o=.d)

SRC_SUB_DIRS:=$(wildcard $(SRCDIR)/*/)
OBJ_SUB_DIRS:=$(patsubst $(SRCDIR)/%/, $(OBJDIR)/%/, $(SRC_SUB_DIRS))

TARGET = turn_based_combat_simulator

.DEFAULT_GOAL:= $(TARGET)
.PHONY: clean all

all: $(TARGET)
	./$(TARGET)
	
$(TARGET): $(OBJS)	
	$(CC) $(CCFLAGS) $^ -o $@
	@echo "BUILD SUCCESS"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJ_SUB_DIRS)
	$(CC) $(CCFLAGS) -MMD -MP -c $< -o $@ 

$(OBJ_SUB_DIRS): 
	mkdir -p $@
	
-include $(DEPS)

clean:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "CLEAN COMPLETE"



