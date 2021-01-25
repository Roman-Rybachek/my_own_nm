all:
	gcc my_own_nm.c libft/libft.a -o my_own_nm
	./my_own_nm test