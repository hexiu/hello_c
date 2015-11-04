#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

void InputShell(char * shell)
{
    FILE *read_fp = NULL;
    char buffer[MAX_SIZE];
    int chars_read = 0;
    getchar();
    memset(buffer, 0, sizeof(buffer));
    read_fp = popen(shell, "r");

    if (read_fp != NULL)
    {
        chars_read = fread(buffer, sizeof(char), MAX_SIZE, read_fp);
        while (chars_read > 0)//读取多数shell命令，shell命令比较长。
        {
            buffer[chars_read - 1] = 0;
            printf("Reading:\n%s\n", buffer);
            chars_read = fread(buffer, sizeof(char), MAX_SIZE, read_fp);
        }
        pclose(read_fp);

        //return EXIT_SUCCESS;
    }
}

int main()
{
    char shell[MAX_SIZE] = {0} ;//= NULL;
    //while(1)
    //{
           scanf("%s",shell);
    //gets(shell);
        InputShell(shell);
    //}



    return EXIT_FAILURE;
}


