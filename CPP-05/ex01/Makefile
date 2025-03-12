# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 19:40:51 by lottavi           #+#    #+#              #
#    Updated: 2025/03/12 19:06:55 by lottavi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = build/form

SRCS = bureaucrat.cpp main.cpp form.cpp
OBJS = $(SRCS:%.cpp=build/bin/%.o)

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
