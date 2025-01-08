NAME = philosophers

CC = cc

CFLAGS =	-Wall -Wextra -Werror -g \
			-Iinclude

FILES = main utils utils_bis arg_handler error_handler io
FILES_BONUS =

OBJ_DIR = obj/
SRC_DIR = src/
BONUS_DIR = bonus/
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
SRCS_BONUS = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(FILES_BONUS)))
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_BONUS))) $(filter-out $(OBJ_DIR)main.o, $(OBJS))

all: $(NAME)

bonus: $(NAME_BONUS)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	make clean

re: fclean all

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) -o $@ $(OBJS) $(LFLAGS)

$(NAME_BONUS): $(OBJ_DIR) $(OBJS_BONUS)
	$(CC) -o $@ $(OBJS_BONUS) $(LFLAGS)

$(OBJ_DIR):
	mkdir $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus