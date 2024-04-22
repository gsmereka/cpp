NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FILES = $(wildcard *.cpp)
OBJ = obj
OBJ_FILES = $(SRC_FILES:sources/%.cpp=$(OBJ)/%.o)

# Color codes for terminal output
PURPLE = \033[1;35m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	c++ $(FLAGS) -I./ $(OBJ_FILES) -o $(NAME)

${OBJ}/%.o : sources/%.cpp
	mkdir -p ${OBJ}
	c++ $(FLAGS) -c $< -o $@


run: $(NAME)
	clear && ./$(NAME) teste teste

git:
	@git add .
	@read -p "Digite a mensagem do commit: " MESSAGE; \
	git commit -m "$$MESSAGE" && git push

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all