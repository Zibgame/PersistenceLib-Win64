NAME = persistence

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -Iinclude

SRC = \
	src/core/persistence.cpp \
	src\registry\registry_detect.cpp \
	src\registry\registry_install.cpp \
	src\registry\registry_remove.cpp \
	src\wmi\wmi_detect.cpp \
	src\wmi\wmi_install.cpp \
	src\wmi\wmi_remove.cpp \
	src\task\task_detect.cpp \
	src\task\task_install.cpp \
	src\task\task_remove.cpp \
	src\startup\startup_detect.cpp \
	src\startup\startup_install.cpp \
	src\startup\startup_remove.cpp \
	src\utils\path.cpp 

OBJ = $(SRC:.cpp=.o)

BUILD_DIR = build
LIB = $(BUILD_DIR)/lib$(NAME).a

EXAMPLES_DIR = src/examples
EXAMPLES = $(wildcard $(EXAMPLES_DIR)/*.cpp)

EXE = $(patsubst $(EXAMPLES_DIR)/%.cpp,$(BUILD_DIR)/%.exe,$(EXAMPLES))

all: $(BUILD_DIR) $(LIB) $(EXE)
	@$(MAKE) clean

$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.exe: $(EXAMPLES_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -L$(BUILD_DIR) -l$(NAME) -o $@

clean:
	del /f /q src\core\*.o 2>nul || exit 0
	del /f /q src\registry\*.o 2>nul || exit 0
	del /f /q src\wmi\*.o 2>nul || exit 0
	del /f /q src\task\*.o 2>nul || exit 0
	del /f /q src\startup\*.o 2>nul || exit 0
	del /f /q src\utils\*.o 2>nul || exit 0

fclean: clean
	rmdir /s /q $(BUILD_DIR) 2>nul || exit 0

re: fclean all