# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 17:34:17 by lottavi           #+#    #+#              #
#    Updated: 2024/11/15 15:54:37 by lottavi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98 -Iinclude
TARGET = build/violance
SRC = src/main.cpp src/Weapon.cpp src/HumanA.cpp src/HumanB.cpp
OBJ = $(SRC:%.cpp=build/bin/%.o)

all: $(TARGET)

build/bin/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

clean:
	rm -rf build/bin

fclean: clean
	rm -f $(TARGET)

re: fclean all
