#include "maym.h"
/**
 * execute_com - excute command.
 * @args: the commands.
 * @background: if wirking in background.
 */

void execute_com(char *args[], int background)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (background)
		{
			signal(SIGINT, SIG_IGN);
		}

		execvp(args[0], args);

			exit(EXIT_FAILURE);
	}
	else
	{
		if (!background)
		{
			int status;

			waitpid(pid, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				fprintf(stderr, "Error: Command '%s' not found.\n", args[0]);
			}
		}
		else
		{
			printf("[%d] %s\n", pid, args[0]);
		}
	}
}
