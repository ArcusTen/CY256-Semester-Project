#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    int file_descriptor;
    file_descriptor = open("/etc/shadow", 0);

    setuid(getuid()); // drop privileges

    char *argv[] = {"/bin/sh", NULL};
    char *envp[] = {NULL};
    execve("/bin/sh", argv, envp);
}