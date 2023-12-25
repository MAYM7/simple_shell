#include "maym.h"

#define MAX_INPUT_SIZE 100
void execute_com(char *command);
/**
 * main - a simple shell
 * Return: always 0.
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		printf("MAYM$ ");
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			printf("\nExiting shell.\n");
			break;
		}
		input[strcspn(input, "\n")] = 0;

		execute_com(input);
	}
	return (0);
}
/**
 * execute_com - excute command.
 * @command: the command.
 */

void execute_com(char *command)
{
	int status = system(command);

	if (status == -1)
	{
		perror("Error executing command");
	}
	else if (status != 0)
	{
		fprintf(stderr, "Error: Command '%s' not found.\n", command);
	}
}
