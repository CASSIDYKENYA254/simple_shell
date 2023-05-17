#include "shell.h"
/**
 * Introduction
 * set up initial variables and data structures.
 * parse command line arguments and open script file if provided
 * populate environment variables list
 * read history file, if it exists
 * enter main shell loop, which will run till an error or exir
 * command is written
 * cleanup and free memory, including writing history to file
 * exit program with success or failure cmd_status code.
 */

/**
 * main - entry
 * @ac: argument count.
 * @av: argument vector.
 * Return:0 (success), 1 (error)
 */

int main(int ac, char **av)
{
	info_t info [] = {INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				ecit(126);
			if (errno == ENOENT)
			{
				error_puts(av[0]);
				error_puts(": 0: Can't open ");
				error_puts(av[1]);
				error_putchar('\n');
				error_putchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	run_command(info, av);
	return (EXIT_SUCCESS);
}
