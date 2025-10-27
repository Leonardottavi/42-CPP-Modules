# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 10:10:24 by lottavi           #+#    #+#              #
#    Updated: 2025/10/27 10:10:27 by lottavi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= easyfind

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

all: build_dir $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

build/bin/%.o: %.cpp | build_dir
	$(CXX) $(CXXFLAGS) -c $< -o $@

build_dir:
	mkdir -p build/bin

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re build_dir
