#ifndef __POPEN2_H__
#define __POPEN2_H__

#include <unistd.h>

#define READ 0
#define WRITE 1

/*
 * Opens a two way stream to a child process
 * Input: command is the path to the runable process
 *        infp and outfp are the returned file handle IDs
 * Output: the child process
 */
pid_t popen2(const char* command, char** argv, int* infp, int* outfp);

#endif /*__POPEN2_H__ */