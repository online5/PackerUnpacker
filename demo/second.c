#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc, char* argv[])
{
  int fd=0;
  fd=open(argv[1], O_RDONLY);
  if(fd == -1)
  {
    printf("Error: File not openned.\n");
    return -1;
  }


  printf("File obtained successfully with file descriptor %d.\n", fd);

  close(fd);
  return 0;
}
