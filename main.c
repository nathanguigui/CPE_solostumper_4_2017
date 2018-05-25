/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** 
*/

int pdetect_the(char *str, int i)
{
	my_putchar(' ');
	my_putchar('"');
	my_putstr("the ");
	i = i + 4;

	while (str[i] != ' ') {
		if (str[i - 1] == 32 || str[i - 1] == '-' && i != 4) {
			if (str[i] >= 97 && str[i] <= 122)
				my_putchar(str[i] - 32);
		} else
			my_putchar(str[i - 1]);
		i = i + 1;
	}
	my_putchar(str[i - 1]);
	my_putchar('"');
	my_putchar(' ');
	return (i);
}

int is_the(char *str, int i)
{
	if (str[i] == 't' && str[i + 1] == 'h' && str[i + 2] == 'e')
		return (1);
	return (0);
}

int my_print_name(char *str)
{
	int i = 0;

	while (str[i]) {
		if (is_the(str, i) != 1 && i == 0 || str[i - 1] == 32) {
			if (str[i] >= 97 && str[i] <= 122)
				my_putchar(str[i] - 32);
		} else if (is_the(str, i+1) == 1)
			i = pdetect_the(str, i + 1);
		else
			my_putchar(str[i]);
		i = i + 1;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (84);
	my_print_name(av[1]);
	my_putchar('\n');
	return (0);
}