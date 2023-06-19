DIR_IND = inc
DIR_SRC = src
DIR_OBJ = obj
DIR_BUILD = bin

SRC = $(wildcard $(DIR_SRC)/*.cpp)
INC = $(wildcard $(DIR_IND)/*.h)
OBJ = $(patsubst $(DIR_SRC)%.cpp,$(DIR_OBJ)%.o,$(SRC))

Del = del

Target = $(DIR_BUILD)/main


all: createDir $(Target)

$(Target):$(OBJ) 
	g++  $^ -o $@
	
$(DIR_OBJ)/%.o : $(DIR_SRC)/%.cpp 
	g++ $< -c -o $@ -I$(DIR_IND) 

clean:
	$(Del)  $(DIR_OBJ)\*.o
	$(Del)  $(DIR_BUILD)\*.exe
	

run:all
	$(DIR_BUILD)/./main
 
createDir:
	$(shell if not exist $(DIR_BUILD) mkdir $(DIR_BUILD))
	$(shell if not exist $(DIR_OBJ) mkdir $(DIR_OBJ))
