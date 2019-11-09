#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int randnum(){
  int fd = open("/dev/random", O_RDONLY);
  int buff;
  read(fd, &buff, sizeof(int));

  if(errno){ //see if any error
    printf("Error number: %d\n", errno);
  }
  return buff;
}
int main() {
  int fd = open("randnum.c", O_RDWR | O_CREAT, 644);
  int buff[11];
  printf("Generating random numbers:\n");
  for(int i = 0; i < 10; i++){
    buff[i] = randnum();
    printf("random %d: %d\n", i, buff[i]);
  }
  if(errno){ //see if any error
    printf("Error number: %d\n", errno);
  }
  printf("Writing numbers to file...\n\n");
  write(fd,buff, sizeof(buff));
  printf("Reading numbers from file...\n\n");
  int buff2[11];
  read(fd, &buff2, sizeof(buff));
  for(int i = 0; i < 10; i++){
    printf("random %d: %d\n", i, buff2[i]);
  }
  printf("Verification that written values were the same:\n");

}
