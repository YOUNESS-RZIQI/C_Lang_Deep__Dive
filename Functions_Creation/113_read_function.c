C :


/*
                        Title : read function (system call)


        1) The read is a system call function that deals with files. You give it the file descriptor, the buffer, 
           and how much data to take from that file.

        2) The read, when it copies from a file, remembers where it stopped the last time, so when you call it again 
           it gives you the size you want starting from the last position where it stopped.

        3) Also, read returns an ssize_t value representing how many characters it copied from the file.
*/


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


void get_next_line(int fd)
{
    char c[1];

    while (c[0] != '\n')
    {
        read(fd, c, 1);
        printf("%c", c[0]);
    }
    c[0] = 0;
}


int main(void)
{
    char c[21];
    ssize_t a = read(1, c, 100);

    write(1, c, a);

    return 0;
}