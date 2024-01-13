#include "maym.h"

int exit_command(const char *command);
/**
 * main - a simple shell
 * Return: always 0.
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS];
	int i;

	signal(SIGINT, handle_signal);

	while (1)
	{
		int background;
		char *token;

		printf("#MAYM$ ");
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = 0;

		if (exit_command(input))
		{
			break;
		}
		token = strtok(input, " ");

		for (i = 0; token != NULL && i < MAX_ARGS - 1; i++)
		{
			args[i] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		background = 0;

		if  (i > 0 && strcmp(args[i - 1], "&") == 0)
		{
			args[i - 1] = NULL;
			background = 1;
		}

		execute_com(args, background);
	}
	return (0);
}

/**
 * exit_command - exit program.
 * @command: the command.
 * Return: always 0.
 */
int exit_command(const char *command)
{
	return (strcmp(command, "exit") == 0);
}
