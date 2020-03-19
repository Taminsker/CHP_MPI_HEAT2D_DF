## SEQUENTIEL & PARALLELE
CFLAGS = -std=c++11 -Wall -Wextra -g
LFLAGS =

## SEQUENTIEL
CC_SEQ = g++
EXE_NAME_SEQ = exe_seq
SRC_DIR_SEQ = src_seq
BUILD_DIR_SEQ = build_seq

SRCS_SEQ := $(wildcard $(SRC_DIR_SEQ)//*.cpp)
OBJS_SEQ := $(patsubst $(SRC_DIR_SEQ)//%.cpp, $(BUILD_DIR_SEQ)//%.o, $(SRCS_SEQ))

## PARALLELE
CC_PAR = mpicxx
EXE_NAME_PAR = exe_par
SRC_DIR_PAR = src_par
BUILD_DIR_PAR = build_par

SRCS_PAR := $(wildcard $(SRC_DIR_PAR)//*.cpp)
OBJS_PAR := $(patsubst $(SRC_DIR_PAR)//%.cpp, $(BUILD_DIR_PAR)//%.o, $(SRCS_PAR))

## SEQUENTIEL & PARALLELE
.PHONY: all $(EXE_NAME_SEQ) $(EXE_NAME_PAR) clean_seq clean_par clean
all: MAKE_DIR_SEQ $(EXE_NAME_SEQ) MAKE_DIR_PAR $(EXE_NAME_PAR)

## SEQUENTIEL

MAKE_DIR_SEQ:
	@mkdir -p $(BUILD_DIR_SEQ)
	@echo "[SEQ] Done : creating the directory '"$(BUILD_DIR_SEQ)"'."

$(EXE_NAME_SEQ): $(OBJS_SEQ)
	@$(CC_SEQ) $(LFLAGS) $(OBJS_SEQ) -o $@
	@echo "[SEQ] Done : the executable '"$(EXE_NAME_SEQ)"' was created."

$(OBJS_SEQ): $(BUILD_DIR_SEQ)//%.o : $(SRC_DIR_SEQ)//%.cpp
	@$(CC_SEQ) $(CFLAGS) -c $< -o $@
	@echo "[SEQ] Done : the object file '"$(notdir $@)"' was created."

clean_seq:
	@cd $(BUILD_DIR_SEQ) && rm -f *.*
	@echo "[SEQ] Done : delete object files."
	@rm -f $(EXE_NAME_SEQ)
	@echo "[SEQ] Done : delete the executable '"$(EXE_NAME_SEQ)"'."


## PARALLELE
MAKE_DIR_PAR:
	@mkdir -p $(BUILD_DIR_PAR)
	@echo "[PAR] Done : creating the directory '"$(BUILD_DIR_PAR)"'."

$(EXE_NAME_PAR): $(OBJS_PAR)
	@$(CC_PAR) $(LFLAGS) $(OBJS_PAR) -o $@
	@echo "[PAR] Done : the executable '"$(EXE_NAME_PAR)"' was created."

$(OBJS_PAR): $(BUILD_DIR_PAR)//%.o : $(SRC_DIR_PAR)//%.cpp
	@$(CC_PAR) $(CFLAGS) -c $< -o $@
	@echo "[PAR] Done : the object file '"$(notdir $@)"' was created."

clean_par:
	@cd $(BUILD_DIR_PAR) && rm -f *.*
	@echo "[PAR] Done : delete object files."
	@rm -f $(EXE_NAME_PAR)
	@echo "[PAR] Done : delete the executable '"$(EXE_NAME_PAR)"'."

## SEQUENTIEL & PARALLELE

clean: clean_seq clean_par

depend:
	makedepend -- $(CFLAGS) -- $(SRCS_SEQ)
	makedepend -- $(CFLAGS) -- $(SRCS_PAR)
# DO NOT DELETE

src_par//listfunctions.o: src_par/listfunctions.h
src_par//operators.o: src_par/operators.h /usr/include/stdio.h
src_par//matrix.o: src_par/matrix.h src_par/operators.h /usr/include/stdio.h
src_par//matrix.o: src_par/outputinput.h /usr/include/stdlib.h
src_par//outputinput.o: src_par/outputinput.h /usr/include/stdlib.h
src_par//main.o: /usr/include/stdio.h src_par/outputinput.h
src_par//main.o: /usr/include/stdlib.h src_par/operators.h src_par/solver.h
src_par//solver.o: src_par/solver.h
