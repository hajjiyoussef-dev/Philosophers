NAME = philo

SRC = ft_atoi.c ft_error.c main.c philo.c philos_routine.c \
		printf_status.c  routing_monitor.c

OBJC = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf 

$(NAME): $(OBJC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJC)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJC)

fclean: clean
	$(RM) $(NAME)

re: fclean all