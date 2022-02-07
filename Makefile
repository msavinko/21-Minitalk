# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlean <marlean@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 19:05:08 by marlean           #+#    #+#              #
#    Updated: 2022/01/27 12:27:58 by marlean          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER				=	server
CLIENT				=	client
SERVER_BONUS		=	server_bonus
CLIENT_BONUS		=	client_bonus

HEADER				=	minitalk.h
HEADER_BONUS		=	bonus/minitalk_bonus.h

PRINTF				=	ft_printf/libftprintf.a

#sources
SERVER_SRC			=	server.c
CLIENT_SRC			=	client.c
SERVER_SRC_BONUS	=	bonus/server_bonus.c
CLIENT_SRC_BONUS	=	bonus/client_bonus.c

#create object files, change .c files to .o files
SERVER_OBJS			=	$(patsubst %.c,%.o, $(SERVER_SRC))
SERVER_OBJS_BONUS	=	$(patsubst %.c,%.o, $(SERVER_SRC_BONUS))
CLIENT_OBJS			=	$(patsubst %.c,%.o, $(CLIENT_SRC))
CLIENT_OBJS_BONUS	=	$(patsubst %.c,%.o, $(CLIENT_SRC_BONUS))

OBJS				=	$(CLIENT_OBJS) $(SERVER_OBJS)
OBJS_BONUS			=	$(CLIENT_OBJS_BONUS) $(SERVER_OBJS_BONUS)

D_FILES				=	$(patsubst %.c,%.d,$(SERVER_SRC) $(CLIENT_SRC) $(SERVER_SRC_BONUS) $(CLIENT_SRC_BONUS))
CC					=	cc
FLAGS				=	-Wall -Wextra -Werror

#type all rule names
.PHONY: all clean fclean re bonus

#main rule for all
all:  $(PRINTF) $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(PRINTF)	:
	make -C ft_printf

#цель: пререквезит - зависимости (если зависимости новее - обновляем цель)
#команды для сборки цели. собираем командой сс в -о цель из объектников
$(SERVER): $(SERVER_OBJS)
	$(CC) -o $@ $(SERVER_OBJS) $(PRINTF)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) -o $@ $(CLIENT_OBJS) $(PRINTF)

$(SERVER_BONUS): $(SERVER_OBJS_BONUS) $(HEADER_BONUS)
	$(CC) -o $@ $(SERVER_OBJS_BONUS) $(PRINTF)

$(CLIENT_BONUS): $(CLIENT_OBJS_BONUS) $(HEADER_BONUS)
	$(CC) -o $@ $(CLIENT_OBJS_BONUS) $(PRINTF)

#каждому файлу .о нужно прописать зависимость от .с
#компиляция с флагами 
%.o		: %.c 
	@$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@ -MD
	@make -C ft_printf
# $< автоматическая переменная. на которую подставляется .с файл.
# $@ имя цели, то есть имя .о файла.
# MD генерирует .д файлы - зависимости файлов от хедера

include $(wildcard $(D_FILES))

clean:
	rm -rf $(OBJS) $(OBJS_BONUS) $(D_FILES)
	cd ft_printf && make clean
	
fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	cd ft_printf && make fclean

re:	fclean all
