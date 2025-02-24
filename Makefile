RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m

SRC_DIR = src/
BONUS_DIR = bonus/
OBJ_DIR = obj/

HEADERS = include/minitalk.h

FTPRINTF = ft_printf/lib/libftprintf.a
FTPRINTF_PATH = ft_printf/

CC = cc -Wall -Werror -Wextra
CFLAGS = -I.
LDFLAGS = -Lft_printf/lib -lftprintf

SERVER_SRCS = $(SRC_DIR)server.c
CLIENT_SRCS = $(SRC_DIR)client.c

SERVER_BONUS_SRCS = $(BONUS_DIR)server_bonus.c
CLIENT_BONUS_SRCS = $(BONUS_DIR)client_bonus.c

SERVER_OBJS = $(SERVER_SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
CLIENT_OBJS = $(CLIENT_SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:$(BONUS_DIR)%.c=$(OBJ_DIR)%.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:$(BONUS_DIR)%.c=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: ft_printf server client

bonus: ft_printf server_bonus client_bonus

ft_printf:
	@echo "$(YELLOW)Compiling ft_printf...$(NC)"
	@$(MAKE) -C $(FTPRINTF_PATH)

server: $(SERVER_OBJS)
	@echo "$(YELLOW)Compiling server...$(NC)"
	@$(CC) $(SERVER_OBJS) $(LDFLAGS) -o server
	@echo "$(BLUE)Server created!$(NC)"

client: $(CLIENT_OBJS)
	@echo "$(YELLOW)Compiling client...$(NC)"
	@$(CC) $(CLIENT_OBJS) $(LDFLAGS) -o client
	@echo "$(BLUE)Client created!$(NC)"

server_bonus: $(SERVER_BONUS_OBJS)
	@echo "$(YELLOW)Compiling server bonus...$(NC)"
	@$(CC) $(SERVER_BONUS_OBJS) $(LDFLAGS) -o server_bonus
	@echo "$(BLUE)Server bonus created!$(NC)"

client_bonus: $(CLIENT_BONUS_OBJS)
	@echo "$(YELLOW)Compiling client bonus...$(NC)"
	@$(CC) $(CLIENT_BONUS_OBJS) $(LDFLAGS) -o client_bonus
	@echo "$(BLUE)Client bonus created!$(NC)"

clean:
	@$(MAKE) clean -C $(FTPRINTF_PATH)
	@echo "$(ORANGE)Cleaning objects for Minitalk...$(NC)"
	@rm -rdf $(OBJ_DIR)
	@echo "$(GREEN)Cleaned Minitalk objects!$(NC)"

fclean: clean
	@echo "$(ORANGE)Fully cleaning ft_printf library...$(NC)"
	@$(MAKE) fclean -C $(FTPRINTF_PATH) > /dev/null
	@echo "$(BLUE)Fully cleaned ft_printf!$(NC)"
	@echo "$(ORANGE)Removing executable files...$(NC)"
	@rm -f client server client_bonus server_bonus
	@echo "$(BLUE)Fully cleaned Minitalk project!$(NC)"

re: fclean all

.PHONY: all bonus ft_printf server client server_bonus client_bonus clean fclean re
