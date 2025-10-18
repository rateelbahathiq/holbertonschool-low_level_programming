#include "main.h"

/**
 * read_textfile - reads a text file and prints it to STDOUT
 * @filename: path to file
 * @letters: number of bytes to read and print
 *
 * Return: number of bytes printed, or 0 on any failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t r, w, written = 0;
	char *buf;

	if (filename == NULL || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	r = read(fd, buf, letters);
	if (r <= 0) /* read error or empty file */
	{
		free(buf);
		close(fd);
		return (0);
	}

	/* write exactly r bytes; if short write occurs, return 0 per spec */
	while (written < r)
	{
		w = write(STDOUT_FILENO, buf + written, r - written);
		if (w <= 0)
		{
			free(buf);
			close(fd);
			return (0);
		}
		written += w;
	}

	free(buf);
	close(fd);
	return (written);
}
