NAME = claptrap
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FILES = $(wildcard ./sources/*.cpp)
OBJ = obj
OBJ_FILES = $(SRC_FILES:sources/%.cpp=$(OBJ)/%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	c++ $(FLAGS) -I./ $(OBJ_FILES) -o $(NAME)

${OBJ}/%.o : sources/%.cpp
	mkdir -p ${OBJ}
	c++ $(FLAGS) -c $< -o $@

newc:
	@read -p "Digite o nome da Nova Classe:" MESSAGE; \
	../../script/template.sh . "$$MESSAGE"

run: $(NAME)
	make re
	clear && ./$(NAME)

valgrind: $(NAME)
	make re
	clear && valgrind ./$(NAME)

git:
	git add .
	git status
	@read -p "Digite a mensagem do commit: " MESSAGE; \
	git commit -m "$$MESSAGE" && git push

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all