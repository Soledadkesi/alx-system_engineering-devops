#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * infinite_while - creates an infinite sleep loop
 * Return: always 0
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}
/**
 * main - creates five zombie processes
 * Return: returns infinite_while zombies
 */
int main(void)
{
	pid_t zombiePID;
	unsigned int j;

	for (j = 0; j < 5; j++)
	{
		zombiePID = fork();
		if (zombiePID == 0)
			exit(0);
		else
			printf("Zombie process created, PID: %d\n", zombiePID);
	}
	return (infinite_while());
}
