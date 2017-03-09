# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 22:18:00 by tberthie          #+#    #+#              #
#    Updated: 2017/03/09 15:57:26 by tberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(addsuffix .o, $(addprefix objs/filler/, main parse piece fill tools))
OVIS = $(addsuffix .o, $(addprefix objs/visu/, main parse display score tools))

NAME = filler
VISU = visual

all: objs $(VISU) $(NAME)

test: all
	./resources/filler_vm -p1 ./filler \
	-p2 ./resources/players/abanlin.filler \
	-f resources/maps/map01 | ./$(VISU) ; echo "\x1b[32m" ; \
	cat filler.trace ; echo "\x1b[0m" ; rm -f filler.trace

objs:
	mkdir objs
	mkdir objs/filler
	mkdir objs/visu

$(NAME): $(OBJS)
	make -C libft
	gcc -o $(NAME) $(OBJS) libft/libft.a

$(VISU): $(OVIS)
	make -C libft
	gcc -o $(VISU) $(OVIS) libft/libft.a SDL/libSDL2-2.0.0.dylib \
	SDL/libSDL2_ttf-2.0.0.dylib

objs/filler/%.o: srcs/%.c
	gcc -o $@ -c $< -I includes/filler -I libft -Weverything

objs/visu/%.o: visu/%.c
	gcc -o $@ -c $< -I includes/visu -I libft -I SDL -Wall -Wextra -O3

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)
	rm -f $(VISU)

re: fclean all
