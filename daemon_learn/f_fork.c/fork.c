#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	pid_t pid;
	printf("Process creation study:");

	pid=fork();
	switch(pid)
	{
		case 0 :	printf("child process is running,Curpid is %d,Parents pid is %d\n",pid,getppid());
			break;
		case -1 :	printf("Creat fail");
			break;
		default :	printf("Parents process is running,pid is %d,child process is %d\n",pid,getpid());
			break;	
		
	}

	exit(0);
}
