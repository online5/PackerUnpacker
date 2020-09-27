/*
Application which is used to combine all regular files from the directory into one regular file
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>

// myexe direct_name file_name
// myexe   argv[1] 
// argv[1]: Name of the file that which contains merged data.
// argv[2]: Name of the Directory which is to be created.

struct FileInfo
{
	char Fname[230];
	int fsize;
};

int main(int argc, char* argv[])
{
	
	struct FileInfo fobj;
	char path[300]={'\0'};
	//char buffer[1024]={'\0'};
	int ret=0, size=0;
	int fd_dest=0, fd_src=0;
	char* buffer;
	char name[512]={'\0'};
	

	if(argc != 3)
	{
		printf("Error: Invalid Parameter Number.\n");
		printf("Usage: ./Executable File FileName DirectoryName\n");
		return -1;
	}

	fd_src=open(argv[1],O_RDONLY);
	if(fd_src == -1)
	{
		printf("Error: Source File cannot be opened.\n");
		return -1;
	}
	ret=mkdir(argv[2], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if(ret== -1)
	{
		printf("Directory cannot be made succesfully.\n");
		return -1;
	}

	while((ret=read(fd_src,&fobj,sizeof(fobj))) != 0)
	{
		printf("FileName: %s FileSize %d.\n", fobj.Fname, fobj.fsize);
		sprintf(path, "%s/%s",argv[2],fobj.Fname);
		fd_dest=creat(path, 0777);

		if(fd_dest == -1)
		{
			printf("Unable to create file.\n");	
			return -1;
		}
		buffer=(char*)malloc(sizeof(fobj.fsize));

		read(fd_src, buffer, fobj.fsize);

		write(fd_dest, buffer,fobj.fsize);
		memset(path,0,sizeof(path));	
		free(buffer);
		close(fd_dest);
		
	}
	unlink(argv[1]);
	close(fd_src);


	return 0;
}




