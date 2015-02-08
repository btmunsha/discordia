#include "popen2.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

pid_t
popen2(const char* command, char** argv, int* infp, int* outfp)
{
    int p_stdin[2], p_stdout[2];
    pid_t pid;

    if (pipe(p_stdin) != 0 || pipe(p_stdout) != 0)
        return -1;

    pid = fork();
    if (pid < 0)
        return pid;
    else if (pid == 0)
    {
        
        if(dup2(p_stdin[READ], READ) < 0)
        {
        	fprintf(stderr, "popen2.c popen2 READ FAIL");
            exit(1);
        }
        if(dup2(p_stdout[WRITE], WRITE) < 0)
        {
        	fprintf(stderr, "popen2.c popen2 WRITE FAIL");
            exit(1);
        }

        close(p_stdin[READ]);
        close(p_stdout[WRITE]);

        execv(command, argv);
        perror("popen2.c popen2 child process failed to execv");
        exit(1);
    }

    close(p_stdin[READ]);
    close(p_stdout[WRITE]);

    if (infp == NULL)
        close(p_stdin[WRITE]);
    else
        *infp = p_stdin[WRITE];
    if (outfp == NULL)
        close(p_stdout[READ]);
    else
        *outfp = p_stdout[READ];
    return pid;
}
