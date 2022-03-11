CC = cc

CFLAGS =  -Wall -Werror -Wextra

mlxFlags = -lmlx -framework OpenGL -framework AppKit

SRCS = so_long.c \
	get_next_line.c \
	ft_split.c \
	get_next_line_utils.c \
	ft_read_map.c \
	ft_move.c \
	ft_find_player.c \
	print_map.c \
	ft_mapchecker.c \
	appley_assets.c \
	ft_element_count.c \
	ft_render_map.c \
	ft_open_door.c \
	ft_strcmp.c \
	ft_strstr.c \
	ft_win.c \
	ft_linkhex.c \
	ft_printf.c \
	ft_putchar.c \
	ft_puthex.c \
	ft_puthexmem.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putu.c \
	ft_puthexmaj.c

SRCS_BN = ./so_long_bn/so_long_bonus.c \
	./so_long_bn/get_next_line.c \
	./so_long_bn/ft_split.c \
	./so_long_bn/get_next_line_utils.c \
	./so_long_bn/ft_read_map.c \
	./so_long_bn/ft_move.c \
	./so_long_bn/ft_find_player.c \
	./so_long_bn/print_map.c \
	./so_long_bn/ft_mapchecker.c \
	./so_long_bn/appley_assets.c \
	./so_long_bn/ft_element_count.c \
	./so_long_bn/ft_render_map.c \
	./so_long_bn/ft_open_door.c \
	./so_long_bn/ft_strcmp.c \
	./so_long_bn/ft_itoa.c \
	ft_strstr.c \
	./so_long_bn/ft_animation.c \
	./so_long_bn/ft_win.c \
	./so_long_bn/ft_up_band.c \
	./so_long_bn/ft_lose.c \
	./so_long_bn/ft_linkhex.c \
	./so_long_bn/ft_printf.c \
	./so_long_bn/ft_putchar.c \
	./so_long_bn/ft_puthex.c \
	./so_long_bn/ft_puthexmem.c \
	./so_long_bn/ft_putnbr.c \
	./so_long_bn/ft_putstr.c \
	./so_long_bn/ft_putu.c \
	./so_long_bn/ft_puthexmaj.c \
	./so_long_bn/ft_move_enemy.c \
	./so_long_bn/ft_loops.c


NAME = so_long


NAME_BN = so_long_bonus

OBJS = ${SRCS:.c=.o}

OBJS_BN = ${SRCS_BN:.c=.o}


REM = rm -rf

%.o : %.c
	@${CC} -c ${CFLAGS} $< -o $@

all : $(NAME)
$(NAME) : $(OBJS)
	@${CC} ${CFLAGS} ${mlxFlags} ${OBJS} -o $(NAME)
	@echo "     "
	@echo "\033[1;33m  _____  _____   _      _____  _   _  _____ "   
	@echo "\033[1;33m /  ___||  _  | | |    |  _  || \ | ||  __ \ "
	@echo "\033[1;33m \ '--. | | | | | |    | | | ||  \| || |  \/ "
	@echo "\033[1;33m  '--. \| | | | | |    | | | || . ' || | __  "
	@echo "\033[1;33m /\__/ /\ \_/ / | |____\ \_/ /| |\  || |_\ \ "
	@echo "\033[1;33m \____/  \___/  \_____/ \___/ \_| \_/ \____/ "
	@echo "     "

bonus : $(NAME_BN)
$(NAME_BN) : $(OBJS_BN)
	@${CC} ${CFLAGS} ${mlxFlags} ${OBJS_BN} -o $(NAME_BN)
	@echo "     "
	@echo "\033[1;33m  _____  _____   _      _____  _   _  _____ "   
	@echo "\033[1;33m /  ___||  _  | | |    |  _  || \ | ||  __ \ "
	@echo "\033[1;33m \ '--. | | | | | |    | | | ||  \| || |  \/ "
	@echo "\033[1;33m  '--. \| | | | | |    | | | || . ' || | __  "
	@echo "\033[1;33m /\__/ /\ \_/ / | |____\ \_/ /| |\  || |_\ \ "
	@echo "\033[1;33m \____/  \___/  \_____/ \___/ \_| \_/ \____/ "
	@echo "\033[1;31m                                               _   _            __ "
	@echo "\033[1;31m                                              |_) / \ |\ | | | (_ "
	@echo "\033[1;31m                                              |_) \_/ | \| |_| __)"
#./so_long_bonus map.ber
clean :
	@$(REM) ${OBJS} ${OBJS_BN}
	@echo "\033[1;31mALL object files are deleted"

fclean : clean
	@$(REM) ${NAME} ${NAME_BN}
	@echo "\033[1;31mALL Excecutable deleted"

re : fclean all

.PHONY : all clean fclean re bonus 
                      
