#include "main.h"

/**
 * signal_handler - SIGNINT signal handler function
 * @sig: Signal code
 */
void signal_handler(int sig)
{
	switch (sig)
	{
	case SIGQUIT:
		{
			printf("SIGQUIT: %d\n", sig);
			break;
		}
	case SIGINT:
	default:
		{
			_exit(0);
		}
	}
}

/**
 * init_sig_handler - signal handler initilizer function
 */
void init_sig_handler(void)
{
	struct sigaction sint, squit;

	/* Handle SIGINT signal */
	sigemptyset(&sint.sa_mask), sint.sa_handler = signal_handler,
								sint.sa_flags = SA_RESTART,
								sigaction(SIGINT, &sint, NULL);
	/* Handle SIGQUIT signal */
	sigemptyset(&squit.sa_mask),
		squit.sa_handler = signal_handler, squit.sa_flags = SA_RESTART,
		sigaction(SIGQUIT, &squit, NULL);
}
