#include <stdio.h>

typedef void	(*exe)(void);

typedef struct s_test
{
	void	(*teste[5])(void);
}	t_test;

void	init_func_array(void);
void	w_move(void);
void	moves(char var);
exe	   *move_function(void);
void	do_nothing(void);


/*
int	main(void)
{
	int		i;
	init_func_array();
	moves('W');
	i = -1;
	while (++i < 5)
		(move_function()->teste[i])();
	moves('N');
	i = -1;
	while (++i < 5)
		(move_function()->teste[i])();
}
*/

int	main(void)
{
	int		i;

	
	move_function()[0]();
}

void	do_nothing(void)
{
	printf("done\n");
	return ;
}

exe	*move_function(void)
{
	static exe f[5] = {
		do_nothing,
		do_nothing,
		do_nothing,
		do_nothing,
		do_nothing
	};

	return (f);
}

// fun	*move_function(void)
// {
// 	static fun f[5];

// 	return (f);
// }