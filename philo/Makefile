NAME = philo

SRC = ft_atoi.c ft_error.c main.c philo.c philos_routine.c \
		printf_status.c  routing_observer.c

OBJC = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
RM = rm -rf 

$(NAME): $(OBJC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJC)

fclean: clean
	$(RM) $(NAME)

re: fclean all