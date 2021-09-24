#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

// int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *utimeout);

int main(void)
{
    fd_set rfds;
    struct timeval tv;
    int retval;// holds number of file descriptors still present in the fd sets.

    // clearing the set rfds.
    FD_ZERO(&rfds);
    // adding stdin fd to fd set.
    FD_SET(0, &rfds);


    // waiting for 10 secs and 0 microseconds.
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    // nfds is 1 because it is maximum of all fd's in fdset + 1.
    retval = select(1, &rfds, NULL, NULL, &tv);


   if (retval == -1)
       perror("select()");
   else if (retval)// if data is entered then select retains the fd in fd set.
       printf("Data is available now.\n");
   else // if data is not entered then select removes it from fdset.
       printf("No data since last ten seconds.\n");

   exit(EXIT_SUCCESS);
}
