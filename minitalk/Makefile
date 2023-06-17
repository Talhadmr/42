NAME = minitalk
SRCSERVER = server.c
SRCCLIENT = client.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)

all :$(NAME)


$(NAME) : $(OBJSERVER) $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o client 
	$(CC) $(OBJSERVER) -o server 


clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT)

fclean: clean
	rm -rf server client

re:fclean all

.PHONY : re fclean clean all