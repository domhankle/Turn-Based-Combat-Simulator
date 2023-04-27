CC=g++
CCFLAGS=-Wall -Wextra -pedantic -fsanitize=leak,address -g

SRCDIR=./src
OBJDIR=./obj
INCDIR=./include

SRCS:=$(wildcard $(SRCDIR)/*.cpp)
OBJS:=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))
INCS:=$(wildcard $(INCDIR)/*.h)

TARGET = turn_based_combat_simulator

.DEFAULT_GOAL:= $(TARGET)
.PHONY: clean all

all: $(TARGET)
	./$(TARGET)
	
$(TARGET): $(INCS) $(OBJS)	
	$(CC) $(CCFLAGS) $^ -o $@
	@echo "BUILD SUCCESS"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CCFLAGS) -c $< -o $@ 

$(OBJDIR): 
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "CLEAN COMPLETE"



