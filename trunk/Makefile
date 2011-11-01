# les repertoires
SRC = ./sources/
OBJ = ./objets/
DEP = ./dependances/
BIN = ./

INC = ./include/

PROG = prog

#Commandes
CPP = g++
FLEX = flex
BISON = bison -d

#Flags
CPPFLAGS = -I$(INC) -g -Wall -pipe
FLAGS = -lfl

#Fichiers
SRCS_CPP = $(wildcard $(SRC)*.cpp)
SRCS_L = $(wildcard $(SRC)*.l)
SRCS_Y = $(wildcard $(SRC)*.y)

#Liste des dépendances .cpp, .c ==> .d
DEPS    = $(SRCS_CPP:$(SRC)%.cpp=$(DEP_DIR)%.d)

#Liste des objets : .cpp, .c, .y, .l ==> .o
OBJS    = $(SRCS_CPP:$(SRC)%.cpp=$(OBJ)%.o) \
          $(SRCS_Y:$(SRC)%.y=$(OBJ)%.o) $(SRCS_L:$(SRC)%.l=$(OBJ)%.o)

#Compilation
all: $(BIN)/$(PROG)

#To executable
$(BIN)/$(PROG): $(OBJS)
	$(CPP) $+ -o $@ $(FLAGS)

#To Objets
$(OBJ)%.o: $(SRC)%.cpp
	$(CPP) -o $@ -c $<

#To SRC
$(SRC)%.cpp : $(SRC)%.l 
	$(FLEX) -o $@ $<
	rm -f $(INC)parser.hpp
	mv -v $(SRC)parser.hpp $(INC)


$(SRC)%.cpp : $(SRC)%.y
	$(BISON) -o $@ $<

#Gestion des dépendances
$(DEP_DIR)%.d: $(SRC)%.cpp
	$(CPP) -o $@ $<

clean:
	rm -f $(OBJ)*.o $(SRC)*~ $(DEP)*.d *~ $(BIN)/$(PROG) $(INC)*.hpp

distclean: clean
	rm -f $(BIN)/$(PROG)

store:
	mkdir -p $(SRC)
	mkdir -p $(OBJ)
	mkdir -p $(DEP)
	mv -v *.cpp $(SRC)
	mv -v lexer.l $(SRC)
	mv -v parser.y $(SRC)
	mv -v *.o $(OBJ)
	mv -v *.d $(DEP)