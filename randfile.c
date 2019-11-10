#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "rand.h"

int randnum(){
  int fd = open("/dev/random", O_RDONLY);
  int buff;
  read(fd, &buff, sizeof(int));

  if(errno){ //see if any error
    printf("Error number: %d\n", errno);
  }
  close(fd);
  return buff;
}
