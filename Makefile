CC = mpicxx
CFLAGS = #-Wall -Wextra -g
LFLAGS =
EXE_NAME = exe
SRC_DIR = src
BUILD_DIR = build

SRCS := $(wildcard $(SRC_DIR)//*.cpp)
OBJS := $(patsubst $(SRC_DIR)//%.cpp, $(BUILD_DIR)//%.o, $(SRCS))

.PHONY: all $(EXE_NAME) clean

all: MAKE_DIR $(EXE_NAME)

MAKE_DIR:
	@mkdir -p $(BUILD_DIR)
	@echo "Done : creating the directory '"$(BUILD_DIR)"'."

$(EXE_NAME): $(OBJS)
	@$(CC) $(LFLAGS) $(OBJS) -o $@
	@echo "Done : the executable '"$(EXE_NAME)"' was created."

$(OBJS): $(BUILD_DIR)//%.o : $(SRC_DIR)//%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Done : the object file '"$(notdir $@)"' was created."

clean:
	@cd $(BUILD_DIR) && rm -f *.*
	@echo "Done : delete object files."
	@rm -f $(EXE_NAME)
	@echo "Done : delete the executable '"$(EXE_NAME)"'."


depend:
	makedepend -- $(CFLAGS) -- $(SRCS)
# DO NOT DELETE

src//mesh.o: src/mesh.h src/data.h
src//matrix.o: src/matrix.h src/mesh.h src/data.h
src//main.o: src/mesh.h src/data.h src/matrix.h src/solver.h
src//solver.o: src/solver.h
