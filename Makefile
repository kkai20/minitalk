NAME			=	minitalk
SERVER_NAME		= server
CLIENT_NAME		= client
SRCS			=
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror #-g -fsanitize=address

SERVER_DIR		= server_srcs
CLIENT_DIR		= client_srcs
SERVER_SRCS		= ${SERVER_DIR}/main.c
CLIENT_SRCS		= ${CLIENT_DIR}/main.c


LIBFT_DIR		= libft
LIBFT			= ${LIBFT_DIR}/libft.a
SERVER_OBJS		= ${SERVER_SRCS:.c=.o}
SERVER_BOBJS	= ${SERVER_BSRCS:.c=.o}
CLIENT_OBJS		= ${CLIENT_SRCS:.c=.o}
CLIENT_BOBJS	= ${CLIENT_BSRCS:.c=.o}
INCLUDES_DIR	= includes
INCLUDES		= -I./${INCLUDES_DIR}
RM				= rm -f

.c.o:
		$(CC) $(CFLAGS)  -c $< -o $@

all:	${NAME}

${NAME}: ${SERVER_NAME} ${CLIENT_NAME}

${SERVER_NAME}: ${SERVER_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDES} ${LIBFT} ${SERVER_OBJS} -o ${SERVER_NAME}

${CLIENT_NAME}: ${CLIENT_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDES} ${LIBFT} ${CLIENT_OBJS} -o ${CLIENT_NAME}

${LIBFT}: ${LIBFT_DIR}/*.c
	${MAKE} -C ${LIBFT_DIR}

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
	${RM} ${SERVER_OBJS}
	${RM} ${CLIENT_OBJS}
	${RM} ${SERVER_BOBJS}
	${RM} ${CLIENT_BOBJS}
	${MAKE} -C ${LIBFT_DIR}	clean

fclean: clean
	${RM} ${SERVER_NAME} ${CLIENT_NAME}
	${MAKE} -C ${LIBFT_DIR} fclean

re:	fclean all

.PHONY: all clean fclean re bonus
