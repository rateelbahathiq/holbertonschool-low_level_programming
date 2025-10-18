#include "main.h"

/* Print error to stderr and exit with code */
static void die(int code, const char *fmt, const char *arg)
{
	dprintf(STDERR_FILENO, fmt, arg);
	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, exits with codes per spec otherwise
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r, w, off;
	char buf[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		die(98, "Error: Can't read from file %s\n", av[1]);

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		if (close(fd_from) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);
		die(99, "Error: Can't write to %s\n", av[2]);
	}

	for (;;)
	{
		r = read(fd_from, buf, sizeof(buf));
		if (r == 0) /* EOF */
			break;
		if (r == -1) /* READ ERROR -> 98 */
		{
			if (close(fd_from) == -1)
				dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);
			if (close(fd_to) == -1)
				dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);
			die(98, "Error: Can't read from file %s\n", av[1]);
		}

		off = 0;
		while (off < r) /* ensure full write, else -> 99 */
		{
			w = write(fd_to, buf + off, r - off);
			if (w == -1)
			{
				if (close(fd_from) == -1)
					dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);
				if (close(fd_to) == -1)
					dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);
				die(99, "Error: Can't write to %s\n", av[2]);
			}
			off += w;
		}
	}

	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);
	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);

	return (0);
}
