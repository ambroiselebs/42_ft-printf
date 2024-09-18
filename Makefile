CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCFOLDER	=
SRCFOLDER	= srcs
LIB			= libftprintf.a

SRCS = ft_printf.c ${SRCFOLDER}/ft_putchar_fd.c ${SRCFOLDER}/ft_putstr_fd.c \
		${SRCFOLDER}/ft_putnbr_fd.c

OBJS = ${SRCS:.c=.o}

all:	${LIB}

${LIB}: ${OBJS}
			ar rcs ${LIB} ${OBJS}

${SRCFOLDER}%.o: ${SRCFOLDER}%.c
			${CC} ${CFLAGS} -I ${INCFOLDER} -c $< -o $@

tester:
			${CC} ${CFLAGS} ${SRCS} $<

clean:
			rm -f ${OBJS}

fclean: clean
			rm -f ${LIB}

re: fclean all

.PHONY:	all clean fclean re
