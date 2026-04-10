# --- COLORS --- #
GREEN = \033[0;32m
RESET = \033[0m
PRUPLE = \033[1;35m
BLUE        = \033[34m
BUBBLE_BLUE    = \033[1;38;5;153m
CYAN        = \033[0;36m
GRAY        = \033[90m
GREEN        = \033[33;32m
ORANGE        = \033[38;5;214m
RED            = \033[31m
PINK        = \033[38;5;213m
YELLOW        = \033[33m
BOLD        = \033[1m
PINK = \033[38;5;213m


#Arguments

NAME         = minishell

INCS         = -Iincludes -Ilibft/include

CC           = cc
CFLAGS       = -Wall -Werror -Wextra -g3
DEPFLAGS	 = -MMD -MP  #flag # -MMD: génère .d ; -MP: cibles phony pour éviter les erreurs si un .h disparaît
SUPP_FILE    = valgrind_readline_leaks_ignore.supp

#Sources
SRC_DIR = srcs

SRCS = main.c \
		0_readline/readline.c \
		1_lexer/lexer.c 1_lexer/lexer_utils.c 1_lexer/lexer_lst_utils.c 1_lexer/lexer_manage_word.c \
		2_parser/parser.c 2_parser/parser_lst_utils.c 2_parser/parser_lst_redir.c 2_parser/parser_utils.c \
		3_expand/expand.c 3_expand/expand_extract.c 3_expand/expand_handle.c \
		4_builtins/builtins.c 4_builtins/builtin_pwd.c 4_builtins/builtin_echo.c 4_builtins/builtin_unset.c 4_builtins/builtin_export.c 4_builtins/builtins_export_utils.c \
		4_builtins/builtin_env.c 4_builtins/builtin_cd.c 4_builtins/builtin_cd_utils.c 4_builtins/builtin_exit.c 4_builtins/builtin_exit_utils.c \
		5_execution/execution_error.c 5_execution/execution_builtins.c 5_execution/execution_fds.c 5_execution/heredoc.c 5_execution/heredoc_utils.c 5_execution/heredoc_handle.c \
		5_execution/execution.c 5_execution/execution_redir.c 5_execution/execution_path.c 5_execution/execution_path_utils.c 5_execution/execution_status.c 5_execution/execution_utils.c \
		6_signals/signal.c \
		7_utils/utils_init_env.c 7_utils/utils_linked_lst.c 7_utils/utils_clear.c 7_utils/utils_removes_quotes.c 7_utils/utils_function.c 7_utils/utils_expand.c \

SRCS_WITH_SRCDIR = $(addprefix $(SRC_DIR)/,$(SRCS))
#Objects

OBJ_DIR      = obj
#OBJS         = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS 		 = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS_WITH_SRCDIR))

DEPS         = $(OBJS:.o=.d)

#Libft

LIBFT_DIR    = libft
LIBFT_A      = $(LIBFT_DIR)/libft.a


# **************************************************************************** #
#                                   Rules                                      #
# **************************************************************************** #

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $@ -lreadline
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"
	@echo "⣾⣻⣿⣷⣯⣽⡏⣷⣿⣿⣻⣾⣻⢿⣻⣿⣾⣿⢿⣷⣷⣷⢿⣿⡿⣾⣳⣿⣯⣻⢿⣿⣾⣿⡿⣿⣷⣿⣿⣿⣿⣿⣯⣟⣿⣾⡿⣷⡷⣿⣻⣻⣿⣽⣿⣳⣿⢿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣾⣎⣿⣽⣿⣿⣽⣿⣿⢿⣿⡿⣿⣿⡯⣽⣿⣿⣿⢿⢿⣯⡿⣿⣯⡽⣻⣟⣿⣟⣿"
	@echo "⣿⣷⣿⣛⣯⣾⡿⣿⣿⣾⣿⡿⣿⣾⣿⣻⣿⣿⣟⣿⣹⣿⣟⣻⣟⣯⣯⣿⣿⣿⣿⣿⣽⣿⣟⡯⣿⣿⣿⣷⣿⣿⣿⣿⣟⢿⣾⣿⣿⣿⣟⣾⣿⣽⢿⣿⣿⣿⣽⣿⣿⣿⣿⣟⡿⢛⣟⣿⣾⣿⡽⣷⣿⣿⣻⣾⣷⣿⣿⣿⣿⣽⣿⣿⣻⣿⢿⣿⣿⢷⣷⣿⣿⣿⣿⣿⣟⣷⣿⣿⣽⣿⣾⢿"
	@echo "⣾⣿⣟⣺⣯⣮⡿⣿⣿⣿⣷⣿⣿⣻⣽⣷⣿⡷⣿⣯⣷⣿⣟⣫⣿⢿⣵⣿⡇⢀⢠⡈⠉⠻⣽⣿⣿⣿⣷⢯⣿⣿⣗⣻⣿⣿⣿⣿⣷⣿⣿⣿⡾⡿⢿⣿⣷⣷⣿⣿⢿⡳⠛⠁⢀⣀⠁⢻⣿⣾⣿⣿⣿⣿⣾⣿⣿⣿⠾⢿⣟⣻⣟⣿⣿⣿⣾⣷⣿⣽⣿⣾⣾⣾⣟⣿⣷⣿⣿⣿⣻⣯⣿⣿"
	@echo "⡿⣾⣿⣽⢿⣽⣿⢿⣺⢷⡿⣾⣷⣿⡿⡿⣭⣿⣾⣟⢿⣷⣻⣿⣿⣽⣷⣷⡁⠠⢀⢙⠢⠄⡀⠙⢿⣿⣿⢿⣿⣿⢾⢿⣿⣾⣿⣿⣿⣾⢽⣽⣿⣿⠿⣿⢿⣷⣿⡿⠟⠀⠀⡀⡈⡠⠀⢸⣿⣯⣯⣷⢿⣿⣿⣿⢿⡏⢠⡤⣤⡉⠻⣿⣽⣷⠿⣿⣿⣻⡿⣿⣿⣿⣿⢿⣷⢿⣿⣿⣿⣽⣿⣿"
	@echo "⢿⣿⣯⣿⣿⣿⣿⣻⣽⣛⣾⣿⣷⣯⣻⣿⣯⣿⣿⢿⣻⣟⣻⣿⣯⣽⣿⣿⡇⢈⠆⡄⠃⡀⠄⠐⠄⠑⢿⣿⣿⣿⣿⣿⣯⣾⣿⡽⣿⣿⣿⡿⣯⣿⣯⣿⣿⡻⠋⠀⠀⢀⢄⣨⣥⠐⡁⢸⣿⣯⣿⣿⣿⣿⣿⣻⡟⢀⢾⡌⢪⡉⢦⡈⢻⣿⣿⣽⣿⣿⣿⣿⣿⣽⣿⡿⡯⣯⣿⣿⣿⣿⣿⣯"
	@echo "⣿⡻⣟⣿⣯⣿⣿⡿⣿⣯⣿⣿⣿⣷⣿⣿⣻⣿⢿⣿⡿⣟⣿⣾⡾⣿⢾⣳⡅⠀⡃⢤⢗⡡⡎⠠⠀⠀⢄⠈⠻⣿⣿⣷⣿⣿⣿⣿⣻⣿⣟⣿⣿⣿⣿⡿⠃⠀⢀⠉⡈⡾⠤⠄⠏⠐⠀⢸⣾⣿⣽⣿⣿⣿⣾⣿⠀⢨⠬⢁⣀⣵⠀⢻⣄⠹⣿⢿⣿⡿⣿⢻⣿⣿⣟⣿⢿⣿⣿⣻⣿⣿⠿⠟"
	@echo "⣿⣿⣿⣿⣞⣯⢿⣯⣽⣻⣿⡷⣿⣿⣻⣾⣿⣞⢿⣿⣿⣟⣯⣿⣾⢿⣿⣿⣃⠀⡡⡈⠏⢸⠐⡁⠀⠀⠈⢁⠀⠙⠛⠛⠛⠉⠉⠈⠉⠁⠉⠋⠛⠛⠁⠀⢄⠀⠂⠤⣎⣻⢹⣁⡐⠁⠀⣼⣿⣿⣽⣾⣿⣿⣿⣏⠆⢢⠃⢳⠷⠱⠀⡀⢻⢆⠙⠿⠿⣿⣽⣿⣿⣿⣿⡿⣿⣿⡿⠟⣋⣤⣶⣶"
	@echo "⣽⣻⣿⣿⣯⣫⣷⣿⣿⣿⢿⣟⣻⣟⣿⢿⣿⣿⣿⣻⣟⣿⣿⣟⣿⢿⣿⣯⣿⡀⠌⠉⢢⠖⣱⢤⠀⠢⠠⠀⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⠀⠀⠀⠄⠀⠀⠄⠈⠔⣊⠥⢿⠤⠊⠁⢰⣿⣿⣛⣿⣿⣟⣟⣿⣽⡆⢀⢴⣿⢻⣇⣄⣤⣴⣬⣅⣤⡠⠤⡤⣤⢀⠉⠉⠻⠛⢉⣠⣾⠿⡋⡡⡦"
	@echo "⣿⣟⣿⣿⣿⣿⣿⢿⢷⣷⡿⣿⣾⣿⣽⣿⣿⣝⣯⣷⡿⣯⣶⣿⣿⡿⣿⣟⢿⡇⠀⠈⣈⣄⣅⠀⠀⠐⠐⠀⠀⠀⠀⢀⠀⠀⢠⠀⠄⠀⠄⢀⡀⠀⠀⠀⠐⡀⠀⠨⠤⡐⢃⡒⠆⢀⣾⣿⣿⣽⣿⡟⡿⣿⢾⣟⠧⠈⢈⣀⡙⠛⠻⢿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⠮⣴⣶⣾⣿⠁⠠⡶⢧⣗"
	@echo "⣯⣿⣿⣿⢾⣟⣿⡿⣿⣿⣿⣿⡿⣾⣿⣿⡿⣿⣿⣿⣾⣟⣿⣛⣽⣿⣿⣿⣽⣇⠀⢀⢐⠔⡐⢀⢈⠠⠀⠀⠀⡂⠈⠀⠢⠀⣀⠀⠂⠀⡐⢀⠂⣄⠁⣐⠄⠀⠀⣀⠀⠡⠐⡫⠄⠀⣿⣷⣿⣿⣿⣾⣝⣟⠉⣠⠖⠉⠡⠀⡌⠉⠓⢄⠙⡿⣿⣿⣿⣟⣯⣻⡟⢿⡷⡽⣟⣿⣿⣷⣞⡶⣯⢿"
	@echo "⣟⣿⣿⢿⣾⣽⣯⣿⣿⣿⣷⣿⣷⣿⣷⣯⣿⣿⣳⣿⣾⣟⣿⠟⠉⠉⠉⣿⡷⣿⠀⠀⠄⠀⠀⡀⠄⠈⠈⠐⢠⠂⡄⠑⠄⠘⠀⠠⠀⠀⢀⢈⡄⢡⢈⠁⡎⢀⣄⠄⠈⠄⠀⠀⠀⢀⣿⣾⣟⣛⣿⢿⠧⠃⡸⠁⠄⠁⠌⠁⡀⠀⠁⠀⢣⠘⠎⠿⢷⡿⠛⣁⡤⠴⠤⠄⠤⣉⠙⢿⣿⣾⡼⠶"
	@echo "⣿⣯⣿⢿⣿⢿⣫⣿⣿⣾⣟⣿⡿⣷⣿⣿⣯⣿⣮⣿⠛⠉⠠⣂⠎⢳⢣⠘⣿⣿⠆⠀⠩⠀⠂⠍⣠⢎⠟⣂⡀⡹⠍⢠⠾⢉⡀⠀⠀⠀⠀⠚⠀⢥⠀⣼⡚⡵⣣⡕⠥⠀⡂⠀⠂⠈⣯⣿⣿⣟⣿⣿⡎⢀⢇⠃⠀⡀⠈⠂⠀⠐⠀⠄⢸⠀⢶⣷⡐⢀⠞⢁⠀⠀⡀⠀⠀⠀⠑⢄⠹⣿⢿⣷"
	@echo "⡿⡟⣿⣯⡿⢿⣟⣿⣻⣷⠿⠯⠿⠿⠛⠛⠟⠛⢿⠏⢁⢚⠂⡀⢀⡓⠳⡀⢹⡇⠀⠀⠠⠰⠛⠈⠀⠀⠈⣀⣀⣀⡈⠨⣥⠌⠄⠀⠀⠄⠈⠀⠠⠁⣀⢀⣀⠀⠀⠈⠠⡌⠀⠀⠀⠄⢹⣿⣧⡿⠿⡻⠇⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠌⢠⣤⡄⠁⡍⠌⠠⠆⠠⠂⠁⢐⠀⠈⠈⣆⢹⣿⣿"
	@echo "⢖⣲⡀⢅⡛⠻⠿⠛⠋⢀⣠⢀⣠⢠⠭⠔⠂⢐⠠⡦⠺⠁⢀⣁⠇⡕⢚⠂⠸⡇⠀⠀⠀⠀⠀⢀⣐⠀⣼⡉⠁⠰⢽⠆⠘⡄⢁⠄⠀⠀⠃⠀⠃⢸⢿⠅⠀⢻⢆⠀⡤⡀⠀⢀⠀⠀⢸⣷⣿⠯⣿⣻⡇⠀⠳⢄⠀⠀⠂⠀⠀⠀⡠⠈⠰⠿⢿⢿⠀⡧⠀⠀⠄⠐⠀⢐⠀⠀⢁⠀⡿⢈⠛⢺"
	@echo "⡦⡈⠫⢶⣆⢖⢠⢐⢲⣓⣗⠫⡰⣆⣜⣾⣧⢫⠞⠰⣀⡀⠂⠐⡊⢄⠢⡁⢸⡇⠈⡐⠀⠅⡠⠀⠛⣀⠻⣥⣀⣤⣾⠎⠀⠏⠀⠡⡀⠁⠀⣐⠀⢻⣦⣄⣀⣸⠃⡐⠙⢂⠀⠐⠀⠀⢀⣿⣿⣿⣿⣷⡆⠸⡦⡍⠓⠒⠴⠖⠒⣊⣴⣦⠐⠂⠠⢘⣇⠸⡈⠀⠀⠀⠀⠀⠀⠀⠀⣠⢇⣾⣻⡾"
	@echo "⣟⠛⠅⡠⠼⣫⡾⡭⢽⣣⣋⣾⢰⡶⡉⢎⢰⡧⣱⡘⠖⡥⠽⣺⡑⡂⠙⠄⠸⡧⠀⢀⢀⢀⡑⣄⠀⠐⢂⡍⠉⢉⡀⢀⠁⠇⠀⣖⢐⢠⠀⠘⠀⠢⢈⠙⢋⡡⠔⠁⡀⡄⠢⠀⠀⠀⣈⣿⢿⣛⣫⣵⣂⠘⢟⣛⣘⣥⣭⠯⣿⣿⣿⣿⡦⢁⣶⣿⣾⣦⡈⠑⠤⣀⡐⣀⣀⡤⠟⣡⣺⢿⣽⣿"
	@echo "⠲⢈⣱⣉⡶⢄⠲⣹⡖⠭⣳⣠⢾⡷⣦⠸⡖⢹⣴⢦⠘⣏⢧⣉⡴⡓⠄⠀⢸⣧⠀⠀⠐⠄⡠⠀⠦⢈⠂⠠⡘⢡⢐⡀⠀⠀⢀⠓⡂⠀⠃⠄⠀⢅⠂⠁⠀⠠⠂⠀⠡⡀⠁⠀⠀⠈⣼⣳⡿⣿⣿⡿⣾⠀⠹⣫⣭⣶⡿⣿⣿⠿⠟⢛⢤⡈⠟⣿⣻⣿⡷⣦⣄⣀⣀⢀⠤⢖⣶⣿⣿⣿⣻⣭"
	@echo "⣙⣎⣜⣗⡿⣣⡏⣑⠦⡅⣥⠅⣸⢁⣿⣧⡪⠣⢦⠙⠙⠳⠟⣸⢏⣭⢏⣇⠀⢻⣆⡀⠐⠁⠂⠀⠐⠀⠀⠒⢴⢰⠢⣐⢒⠂⣐⠂⠂⡔⠠⠄⢀⢈⠀⢀⠁⠂⢘⠠⢀⠀⠐⠀⠀⣀⡾⣿⣿⣿⡿⠟⣉⡦⠀⢺⣿⣿⣽⣿⣿⣿⣿⣿⣿⣾⣶⡬⣸⣻⣿⣗⢢⣉⣚⠺⡝⣿⣯⣟⣿⣿⣿⠏"
	@echo "⡣⡧⢞⣚⡼⢳⡻⡽⠋⠙⠤⡭⡰⣺⣯⣿⣷⡄⠀⢠⡆⠀⠀⠈⣎⠧⡹⢦⡥⠀⠁⠀⠀⠀⠐⢂⠀⠠⠀⡀⡤⢖⠸⠥⡹⡧⣄⡐⠀⠁⣄⢦⠝⣉⢓⡂⡐⠐⠈⠈⠉⠉⠁⡐⢠⣭⣟⣛⢿⡟⣴⣿⣾⠁⢰⢤⢀⡹⣟⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⢷⣮⡻⣿⣶⣝⡻⣿⢷⡯⠋⣥"
	@echo "⢽⢺⣩⢯⡹⣬⠎⢀⣴⡀⠀⠈⢹⢿⣿⣿⣿⣗⡀⠈⠀⠀⠀⢀⢥⢣⣏⡽⠜⢇⠐⠁⠈⠀⠀⠀⠀⠁⠈⠠⠣⠭⠩⠍⠵⢼⣳⠥⠀⢘⣢⡛⣝⣓⠒⣉⠂⠀⢀⢒⣆⠠⠄⡀⢸⣿⣿⢯⣯⣿⣿⠋⠁⣨⣶⣿⢷⡽⣿⣽⣿⣿⣝⣾⣯⣯⢿⣽⣽⣟⣾⣻⢿⣯⣻⢎⢻⡿⠷⠉⠊⢄⣾⣿"
	@echo "⡟⣵⢩⡯⢷⣽⠀⠈⠁⠀⠀⠠⢰⡲⠛⣉⠛⠉⣗⣄⣁⡠⣀⠱⠋⢚⢰⠭⢢⡏⠀⠰⠀⠠⠄⡒⢉⠰⠁⣀⠆⠀⠅⠀⠐⠈⠁⡁⣄⡀⡀⢀⠉⠀⡠⠂⠀⡁⠌⠀⡄⠀⠠⠀⠸⣿⣺⣿⣿⡞⠃⡠⢾⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣽⣟⣷⣿⢗⡿⣿⣟⡯⣼⣫⣗⢆⡰⣶⡿⣴⢺⣽⣽"
	@echo "⢶⡥⡻⢹⡸⣭⢦⣀⠀⡀⣀⣤⣿⣧⣄⠀⢀⣴⣿⣿⣿⣿⣿⣷⣿⣧⣈⠰⢑⠘⠠⠈⠂⠄⠀⠐⠀⠄⠈⡀⠀⡀⠀⠀⠈⠀⠓⠎⡻⠆⠋⠇⠀⠀⠀⢀⠀⢀⡨⠀⣁⠀⢀⠀⠀⠹⣿⢿⡾⠃⡰⣾⣿⢿⣿⢿⣿⣿⣿⣿⣿⣿⢿⣿⢿⣷⣿⣿⣿⣿⣿⣾⣿⣞⣿⣧⡿⣿⣓⢿⣻⠀⣿⣿"
	@echo "⢮⢓⣧⢿⣿⣣⣶⣷⣿⣿⣿⣿⣿⣿⣾⠅⡈⠻⢿⣿⣿⢿⣿⣿⢿⣿⣻⣯⠆⠀⡁⠐⠀⠀⠀⠠⠃⠀⠆⠔⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⡀⢀⢀⠠⠁⡀⠁⠀⠀⠀⠀⠀⠀⢸⡺⢀⣔⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣷⣿⣝⣿⣿⣽⣿⣟⣿⣯⣿⣽⣞⣾⠁⣿⣿"
	@echo "⢲⠭⣿⣿⣿⣿⣿⣯⣿⣿⣻⣿⡛⠋⣀⣴⠿⣖⡤⣄⣶⣿⣿⣾⡷⣋⠍⢀⠀⡅⠂⠀⠀⠀⠠⠀⡄⢂⠘⠰⢚⠠⡀⠥⠄⠁⡀⠠⠀⡀⠀⠐⡃⡐⢂⣠⡄⠡⢀⠡⠁⢠⠀⠀⠀⠀⡨⠀⣸⣝⡿⣿⣿⣿⢿⣿⣿⣿⣿⡿⣯⡻⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣾⣿⣻⣟⣿⣷⣿⣽⡶⡅⢽⣿"
	@echo "⣤⠁⠐⢾⣿⣛⣿⣾⣿⣯⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣯⣿⢿⡛⡁⡠⣠⠤⠐⠈⠀⠁⠀⠀⠁⢀⠈⠂⡀⠖⡄⠧⢊⢠⡀⠆⠄⢣⢄⠤⣄⢹⡥⠆⡢⠀⠐⠀⠀⠂⢈⠔⠀⠀⠀⠁⠀⠀⣟⣾⣽⣿⣿⣿⢿⣿⣯⣷⣽⣿⣿⣿⣿⣵⣿⢿⣻⣿⣿⣟⣿⣿⢿⣿⣿⣿⣻⣻⣿⣯⣯⠇⢙⣻"
	@echo "⣿⡇⣁⠀⡀⠍⠉⠞⠛⠿⠿⢿⡿⡹⡟⠾⠽⠿⠙⢊⣋⣡⣣⣰⣿⣇⠻⣯⡄⠀⠀⠀⠠⠀⠐⢀⠀⠕⠀⠀⠀⡐⡰⢠⠈⠰⣹⠨⢢⠅⡇⠎⠆⠠⠀⠅⠡⠰⠁⢠⠁⠈⠐⠂⠄⠈⠀⠀⠽⣾⢻⣺⣷⡛⣿⣿⣿⣻⣾⣿⣿⣿⢟⡿⢿⣿⣿⢿⡿⡽⠿⣟⣻⠻⠿⠾⢹⣿⢿⣻⣷⣗⢈⡿"
	@echo "⢿⡇⢁⠴⣟⡓⢿⣿⡷⣷⣿⣯⣿⣽⣣⡶⣷⣾⣮⣾⣿⣿⣿⣿⣷⢿⠶⢨⡉⠀⠄⠈⠀⠀⠀⠀⡈⠌⠄⠂⡄⠢⠀⠔⠁⠪⠱⠕⠃⢟⠄⢁⠀⠁⠀⠨⠐⠈⢄⠠⠁⠐⠀⠀⠀⠀⠀⠀⠞⠿⠿⣲⠗⠋⠉⡃⠋⡈⢉⠉⠉⠁⠠⠀⢂⠠⠙⠝⣯⣷⠌⠉⢀⠠⠂⠂⠀⠘⢫⣯⡿⣷⡁⣻"
	@echo "⠟⠠⠧⣻⠎⢙⡰⢛⣿⣿⣿⣿⣿⣾⣿⣿⣿⣯⣿⣿⣝⢿⣿⡿⠻⣗⡲⢞⡤⠀⠀⠀⠈⢀⠈⠁⠄⠂⢂⢈⠀⠀⠀⠂⠑⠀⠀⢀⠀⠀⠀⠀⠐⠐⠂⠒⠀⠁⠀⡀⢂⠠⠀⠀⠀⢀⠐⠈⠄⠀⠀⠀⠄⠀⣐⣐⣀⣤⣄⡀⠄⠀⣴⣶⣦⡁⠀⠆⠈⠑⠀⡂⠁⣾⣻⣶⠱⠄⠈⣿⣟⡿⡅⣾"
	@echo "⣠⠝⣽⢟⣚⢯⠀⣿⢿⣾⣿⢿⣾⣿⣿⣿⣿⣿⣿⣺⣟⣷⣭⠶⣱⢟⠁⡇⡆⢀⡀⠄⠀⠅⢀⡀⠀⡀⠀⠐⠄⠈⠄⠄⠀⠀⡀⠀⡀⠂⠌⠔⢀⠠⠄⠈⡀⢐⠘⣠⣥⣄⠨⠀⠐⠀⣴⣾⣷⡌⠀⠁⣴⣿⣿⢿⣿⣿⣿⢗⠀⠂⣿⣟⣿⡇⠅⠡⢁⠀⡀⠄⡄⣿⣿⡾⡄⠁⠀⢸⡿⣶⠃⣳"
	@echo "⡬⢝⣗⡾⡮⢋⣾⡫⣮⢛⣿⡿⣿⣟⡿⠋⡓⠻⡛⠟⠻⠛⠁⠈⠀⢉⡈⠉⢀⢀⠀⡀⠠⠂⠈⣀⣀⡂⠀⡀⠀⠁⣤⣶⣦⡌⠌⢘⠀⣴⣻⣿⣆⠢⠀⠄⡀⠂⠀⣿⣽⣿⡀⠊⠀⠀⡿⣿⡯⡇⢀⠀⣿⣳⣯⠟⠛⠉⠉⠀⠄⠀⢹⢻⣿⣧⠐⠈⢂⠀⡀⠄⠂⣿⣿⣿⡇⡈⠀⠈⣿⣻⠀⡾"
	@echo "⣿⠫⣟⡘⠙⠀⠀⠁⠈⠐⠉⢻⣽⠋⠀⠀⠀⠀⠠⠠⠀⠠⢀⣤⣦⣄⠠⠀⠀⣶⣶⣶⡀⠄⢸⣿⣿⣷⣌⠀⠀⠁⣿⣿⣿⣥⠀⠀⠄⢿⣿⣿⣿⠠⠀⢐⠀⡀⠂⢿⣿⡿⡇⢀⠀⠀⢿⣿⣿⡇⠀⠀⣹⢻⡽⠄⠀⠀⠀⠀⠀⠀⢘⣮⣾⡷⠀⠠⠀⠡⠀⡀⠀⣿⢫⣯⡇⠀⢡⠀⣳⣕⢤⣻"
	@echo "⢣⢿⡶⠁⡐⠈⢀⣀⣁⡀⢂⠈⠀⡠⢈⢾⣻⢷⡄⠀⠀⠐⢸⣿⣿⣿⡆⡀⠘⣯⣿⣮⠇⠀⢘⣿⣿⣷⣽⡆⠀⠀⢸⣿⣿⣷⠀⡈⠀⢻⡯⡻⣽⠈⠀⢐⠀⠁⠀⣏⡿⣿⡇⠀⠀⠈⣘⣟⣿⡇⠀⡀⢒⣿⣿⢲⣶⣴⣶⡶⠀⠀⠸⠿⡿⣗⠀⠂⠈⠔⠄⡀⠀⣿⡌⣼⣦⠰⠀⠢⣛⢑⠸⣿"
	@echo "⢷⣚⠁⡢⣠⠂⣾⣿⣿⣽⢆⠂⠀⠀⣭⣿⣿⣿⣿⠀⠀⠀⠀⣿⣟⣶⠇⠀⠀⣿⣿⢻⣿⠀⠄⢻⡟⣿⣾⣯⣇⠘⠘⣿⢵⣿⠀⠀⠐⢸⢽⣟⣾⠀⠰⠀⠂⠀⠀⢫⣿⣿⣿⣿⡵⠶⢿⣟⣭⣧⠀⠠⠸⣟⢿⣷⣙⣿⣿⠿⠀⠠⠀⣯⡻⣯⡃⠄⠀⠆⢐⠀⠀⢻⢺⡸⣗⠀⠒⠁⠤⢠⡠⢀"
	@echo "⣮⡯⠀⠃⡀⢠⡿⣿⣾⣿⣾⡄⠂⠀⣻⢿⣼⡿⣿⣧⠠⠁⠀⢯⣿⣺⢧⠀⢀⢡⣧⢳⡃⠀⠁⣿⣝⣏⠻⡿⣟⣧⣤⣼⣿⣷⡇⠀⠂⠈⣿⣿⣻⡀⠄⠂⠆⢨⠀⢸⣽⣫⣛⡯⠾⠿⠛⡿⣺⡼⡀⠀⠀⣾⣷⣽⡆⠀⠀⠀⢀⠀⠀⣿⣷⣹⣅⠀⠀⠄⠀⠀⠠⢨⣿⣱⣽⣀⣀⣀⣡⣔⠂⣑"
	@echo "⣧⢿⠈⠱⢀⢸⣿⣥⡶⣾⣟⡦⠀⡂⢩⣻⣾⣷⠹⣿⡄⠀⢀⢰⢻⣻⣧⠀⠠⢸⡝⣧⢻⠀⠀⢱⣾⡴⣶⠘⣲⣼⣿⡳⣯⣿⡄⠀⠀⠌⣿⣿⣷⡇⠂⠀⡁⠀⢄⢸⢻⣿⣿⠂⠀⠀⠀⣷⡿⣇⡃⠀⡀⣿⣿⣯⣇⣀⣀⠀⠀⢀⠀⣿⣿⢿⣗⣷⣞⣿⣷⣆⠐⠨⡿⣿⣼⣿⣿⣿⣿⣿⠀⠤"
	@echo "⣽⢊⢢⠁⠐⢸⣿⣯⡇⢋⡿⣭⣷⢲⣟⣾⠀⣿⢸⡸⣇⠀⢀⢸⣟⣽⣿⠀⠀⢘⣯⢫⣧⠀⠈⢨⣿⡜⣆⠃⠈⢟⣯⣟⣶⣿⣳⠀⠁⠀⡟⣟⣻⡅⠀⠂⢀⠀⠅⠘⣿⣟⣿⡆⠀⠀⠀⣟⣿⣿⠃⠀⠀⢻⢷⣿⣿⢿⣿⣽⣿⡆⠀⠙⢧⣳⣷⣿⢿⣿⡿⠏⠐⢀⠙⠛⠛⠛⠛⠚⠛⢡⠔⠀"
	@echo "⣻⠁⡄⢀⡀⣼⣟⣿⠇⠀⢻⣿⣿⣇⣿⠗⢠⢹⣛⡷⢾⡄⠀⠘⣿⣼⣽⡂⠀⠈⣷⣻⣽⡆⠈⠸⠿⣿⡿⡆⡠⠀⠸⣾⣾⣸⣿⡀⠀⠁⢹⣿⣿⣯⠠⠢⠀⡐⠀⠀⣿⣿⣳⠄⠀⠀⡀⠱⠿⠿⠆⠄⡀⠘⠿⠛⠿⠿⠯⠗⡋⠅⠂⢈⠀⡈⠀⡄⠄⠠⠀⠀⠔⠀⠁⠠⠑⠐⠠⠀⡒⠀⠀⢀"
	@echo "⠈⠀⠃⡁⠀⣮⡯⣷⡇⠀⠈⢿⢿⣿⡿⡄⠀⠈⡿⣿⣷⡅⠀⠀⣿⢳⡿⣇⠀⠀⡿⣿⢿⡇⠀⠀⡇⣿⣿⡇⠀⠀⠁⠙⢽⣮⡾⠇⡀⠁⠈⠿⠿⠟⡠⢈⠀⠀⠀⡌⡀⠁⡉⠀⠁⠀⠀⠐⠠⠈⠀⠀⠀⠘⠠⠀⢀⡁⠠⠀⠀⠀⠀⠀⠀⠀⠐⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⢠⠀⠨⢒"
	@echo "⢀⠀⠱⠒⠃⣿⣧⣕⣆⠀⠀⠈⢿⣽⣿⠀⠀⠄⠸⡿⣽⡧⠄⠄⠹⣟⣿⡿⠀⠂⠹⠻⠟⠃⠀⠀⠙⠿⠜⡁⠀⠀⢠⠄⠂⡀⠄⠠⠀⠀⠀⠤⠂⡀⠀⠀⠀⠀⠀⠀⠃⠆⠐⠀⠁⠀⠀⠀⠈⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⢂⠀⠐⠂⡀⢀⠀⢠⡠⢅⠁⡇⠐⡀⠄"
	@echo "⢊⠀⠐⡡⢂⢩⣯⣿⡏⠀⡄⠀⡈⠉⡋⠀⠠⠁⡆⠛⠟⠚⠀⠀⡀⠨⠡⠀⠀⠀⠀⠔⡀⡀⠈⠀⠈⠀⠔⠀⠀⠀⠀⠀⠁⠐⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠄⠀⢀⠀⠀⢀⢀⢀⠠⢀⠠⠀⡀⠠⠀⡀⠨⠀⢂⢀⠑⠄⠉⡀⠔⡡⢂⠊⠈⢰⡊⡅⢀⠢⠀⡤⠠⢀⡈⡕⢆⠠⠃⡴⠆⡯⢑⢪"
	@echo "⠂⡀⠀⠤⢐⠀⠉⠉⠀⠐⠁⠀⠈⠄⠀⠈⠀⠀⠀⠊⠔⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⡀⠀⠐⣂⠠⢠⠀⣀⠄⠠⠀⠐⡌⠄⢈⡄⠄⢂⠄⠰⡐⢐⡪⢁⡀⠠⢆⠄⠧⡑⣙⡀⠆⡆⡔⢡⢐⣮⢘⢨⢸⣸⡙⡘⣕⠨⡥⠣⡢⠁⠄⡣⡥⢐⡉⣏⡋⢰⡓⢼⡰⣅⠫⣨⢁⠯"
	@echo "⢈⡀⠀⡀⠈⠀⠈⠁⠐⠀⠀⠀⠀⠀⡀⡀⠠⠀⡀⠀⠀⠀⢄⠀⡤⠀⠄⠠⠀⡀⣀⠤⡀⢁⣔⠈⠰⠙⣡⡈⡊⠌⠆⠆⢡⢠⢊⠥⡜⢅⣂⡺⠤⢐⠏⢁⠊⢠⢉⠶⡄⢚⡡⢏⣐⡊⠔⡴⢃⡐⢎⡵⡳⠅⡗⠴⡩⡗⠢⠎⢗⡲⣱⠭⡴⣣⢊⠯⡦⢥⢏⡕⣂⣅⣕⡆⡽⡕⣠⠳⠌⢽⠠⣒"
	@echo "⠀⠴⣘⠠⠂⡀⠄⢀⡀⠀⢀⡀⣀⢂⡡⣐⠁⢂⠍⣠⡣⡑⣐⠠⣅⠃⡇⡘⡕⡬⣡⠲⠀⣆⢎⡘⡥⠜⡑⣍⡍⡓⢢⠘⠆⡀⠜⣀⠞⠀⠾⡩⡍⣠⢃⢁⠮⢙⠪⣬⣬⠃⡬⣎⣝⠺⣆⠦⠯⠅⡈⠜⠶⠵⢬⠹⣷⡪⣕⣉⡮⠅⣭⢘⣦⣩⣑⣉⡝⡶⢾⢴⣢⣏⡻⣞⣡⢳⣵⢵⠾⣿⣱⢯"

$(LIBFT_A):
	@echo "Compiling Libft..."
	@make -C libft/ > /dev/null
	@echo "$(GREEN)✓ Libft compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCS) -c $< -o $@

clean :
	@echo "Cleaning objects files..."
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)✓ Cleaned!$(RESET)"

fclean : clean
	@echo "Removing $(NAME)..."
	rm -f $(NAME)
	rm -f $(SUPP_FILE)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✓ Cleaned!$(RESET)"


re : fclean all

# create .supp file that suppresses leaks from teh readline library
$(SUPP_FILE):
	@echo "Creating valgrind suppression file for readline library"
	@echo "{" > $(SUPP_FILE)
	@echo "   ignore_libreadline_leaks" >> $(SUPP_FILE)
	@echo "   Memcheck:Leak" >> $(SUPP_FILE)
	@echo "   ..." >> $(SUPP_FILE)
	@echo "   obj:*/libreadline.so.*" >> $(SUPP_FILE)
	@echo "}" >> $(SUPP_FILE)

# launch ./minishell with valgrind set up with the suppressed file
valgrind: $(NAME) $(SUPP_FILE)
	valgrind --suppressions=$(SUPP_FILE) --leak-check=full --track-fds=yes --show-leak-kinds=all --trace-children=yes ./$(NAME) || true


CHAT = { ignore_readline_leaks Memcheck:Leak ... obj:*/libreadline.so.* } { ignore_bin_functions Memcheck:Leak ... obj:/usr/bin/* } { ncurses_termcap Memcheck:Leak match-leak-kinds:reachable fun:rl_make_bare_keymap fun:rl_generic_bind fun:rl_parse_and_bind obj:/usr/lib/x86_64-linux-gnu/libreadline.so.8.2 fun:rl_initialize fun:readline }

ignore:
	@for i in $(CHAT); do \
   		echo $$i >> ignore.supp; \
    done

val:
	@make
	@if ! [ -f "ignore.supp" ]; then make ignore; fi
	@valgrind --suppressions=./ignore.supp --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes -s ./minishell



.PHONY: all clean fclean re

# inclut les fichiers .d générés par -MMD (dépendances headers)
-include $(DEPS)
