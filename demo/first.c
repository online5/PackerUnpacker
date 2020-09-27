#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(
                int argc,                           // Count of command line arguments
                char *argv[]                        // Array of command line arguments
            )
{
    int fd = 0;
    
    if(argc != 2)
    {
        printf("Error : Invalid number of arguments\n");
        return -1;
    }
    
    if((strcmp(argv[1],"-h") == 0) ||
       (strcmp(argv[1],"-H") == 0))
    {
        printf("Usage : Executable_Name  File_Name\n");
        return 0;
    }
        
    fd = open(
                    argv[1],           // File name
                    O_RDONLY                   // File opening mode
                    );
    
    if(fd == -1)                                   // Failure in opening the file
    {
        printf("Error : Unable to open the file\n");
    }
    else                                             // Succefull file open
    {
        printf("File gets succesfully opened with FD : %d\n",fd);
    }
    
    close(fd);
    
    return 0;
}
