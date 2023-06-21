NAME		:=	.update

NULL		:=
SPACE		:=	$(NULL) #

SRC_ROOT	:=	src/
INC_ROOT	:=	inc/
OBJ_ROOT	:=	.obj/
DEP_ROOT	:=	.dep/

SRC_DIRS	:=	./:uno/:dos/
SRC_DIRS	:=	$(subst :,$(SPACE),$(SRC_DIRS))
SRC_DIRS	:=	$(addprefix $(SRC_ROOT),$(SRC_DIRS))
SRC_DIRS	:=	$(subst $(SPACE),:,$(SRC_DIRS))

SRC			:=	understand_memove return_pointer_to_static
SRC			:=	$(addsuffix .c,$(SRC))

OBJ			:=	$(addprefix $(OBJ_ROOT),$(subst .c,.o,$(SRC)))
DEP			:=	$(addprefix $(DEP_ROOT),$(subst .c,.d,$(SRC)))

INCLUDE		:=	-I $(INC_ROOT)

CFLAGS		:=	-Wall -Wextra -Werror# -fsanitize=address

MUTE		:=	&> /dev/null

vpath %.c $(SRC_DIRS)

# $(OBJ_ROOT)%.o	: %.c -lm

all :
	$(MAKE) $(NAME)

$(NAME) :	$(OBJ) $(DEP)
	touch $@

$(DEP_ROOT)%.d : %.c
	mkdir -p $(@D)
	echo "\033[1;93m[DEPS]:\033[1;92m $<\033[1;97m"
	$(CC) -MMD -MF $@ $(INCLUDE) $(CFLAGS) -c $< && rm -rf $(addsuffix .o,$*)
	sed -i.tmp '1 s|:| $@ :|' $@ && rm -rf $(addsuffix .tmp,$@)
	sed -i.tmp '1 s|^$*|$(OBJ_ROOT)$*|' $@ && rm -rf $(addsuffix .tmp,$@)

$(OBJ_ROOT)%.o : %.c
	mkdir -p $(@D)
	echo "\033[1;95m[OBJS]:\033[1;92m $<\033[1;97m"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJ_ROOT) $(DEP_ROOT) $(NAME)

fclean :	clean
	rm -rf $(NAME)

re : fclean all

.SILENT:

.LIBPATTERNS: lib%.a lib%.so lib%.dylib

.PHONY: all clean fclean re


ifeq (,$(findstring clean,$(MAKECMDGOALS)))
ifeq (,$(findstring re,$(MAKECMDGOALS)))
-include $(DEP)
endif
endif