CXX:=g++
BIN:=cpplox


SRC_DIR:=./src
OBJ_DIR:=./obj
BIN_DIR:=./bin


SRC_LIST:=$(shell find $(SRC_DIR) -name '*.cpp')
OBJ_LIST:=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_LIST))

CXX_FLAGS:=-I$(INC_DIR)

TARGET=$(BIN_DIR)/$(BIN)

all: $(TARGET)

$(TARGET): $(OBJ_LIST)
	@mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) $(OBJ_LIST) main.cpp -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -Rf $(OBJ_DIR)
	rm -Rf $(BIN_DIR)
	./grammer.py --clean