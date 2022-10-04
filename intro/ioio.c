#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int file_descriptor = open("test", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(file_descriptor > -1);
    int rc = write(file_descriptor, "HELLO, WORLD!\n", 13);
    assert(rc == 13);
    close(file_descriptor);
    return 0;
}
