NAME = philo_bonus

SRC = ft_atoi_bonus.c ft_error_bonus.c ft_kill_process_bonus.c ft_routing_monitor_bonus.c \
		main_bonus.c philo_bouns.c philo_routing_bonus.c print_status_bonus.c 

OBJC = ${SRC:.c=.o}
CC = cc 
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
RM = rm -rf

$(NAME): $(OBJC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJC)


%.o: %.c philo_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJC)

fclean: clean
	$(RM) $(NAME)

re: fclean all 


