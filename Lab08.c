#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid[3];
	int status=0;
	for (int i=0;i<3;i++)
	{
		pid[i] = fork();

		if(pid[i]!=0)
		{
			printf("This is the parent process:\n");
			for (int j=0;j<3;j++)
			{
				if (pid[j] >= 0)
					printf("child[%d]=%d\n",j,pid[j]);
			}
			pid[i]=wait(&status);
		}
		else
		{
			printf("This is the child process:\n");
			printf("parent=%d\n",getppid());
			printf("child=%d\n\n",getpid());
			exit(status);
		}
	}	
	return 0;
}
