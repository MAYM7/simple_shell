#include "maym.h"
/**
 * handle_signal - handle Ctrl+C.
 * @signo: the signal.
 */
void handle_signal(int signo)
{
	if (signo == SIGINT)
	{
		printf("\nCtrl+C received. Type 'exit' to quit.\nMAYM$ ");
		fflush(stdout);
	}
}
