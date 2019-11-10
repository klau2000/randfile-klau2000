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
  close(fd);
  return buff;
}
int main() {
  int file = open("randnum.txt", O_RDWR | O_CREAT, 666);
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
  write(file,buff, sizeof(buff));
  close(file);
  printf("Reading numbers from file...\n\n");

  printf("Verification that written values were the same:\n");
  int file2 = open("random.txt", O_RDONLY);
  int buff2[11];
  read(file2, &buff2, sizeof(buff2));
  for(int j = 0; j < 10; j++){
    printf("random %d: %d\n", j, buff2[j]);
  }
  if(errno){ //see if any error
    printf("Error number: %d\n", errno);
  }
  close(file2);
}
