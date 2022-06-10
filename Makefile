# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfermey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 11:45:15 by wfermey           #+#    #+#              #
#    Updated: 2022/06/09 12:04:33 by wfermey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		philo

FLAGS =		-Wall -Wextra -Werror

FILES = 	main.c action.c death.c destroy.c init.c time.c utils.c check.c

${NAME}:
			gcc -pthread ${FLAGS} ${FILES} -o ${NAME}

all:		${NAME}

clean:		
			rm ${NAME}	

fclean:		
			rm ${NAME}	

re:			fclean all	
