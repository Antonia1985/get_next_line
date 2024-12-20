//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    char *line;
    int fd;

    if (argc == 1) // No file argument, so use standard input (stdin)
    {
        printf("Reading from standard input (Ctrl+D to exit)\n");
        while ((line = get_next_line(STDIN_FILENO)) != NULL)
        {
            printf("Line: %s", line);
            free(line);  // Free the memory allocated for the line
        }
        printf("\n");
    }
    else if (argc == 2) // File argument is provided
    {
        // Open the file for reading
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            perror("Error opening file");
            return 1; // Exit with error code
        }

        printf("Reading from file: %s\n", argv[1]);
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("Line: %s", line);
            free(line);  // Free the memory allocated for the line
        }
        printf("\n");

        // Close the file when done
        close(fd);
    }
    else
    {
        // Invalid number of arguments
        printf("Usage: %s [file]\n", argv[0]);
        return 1;
    }

    return 0;
}
