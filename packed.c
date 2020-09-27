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
// myexe   argv[1]   argv[2]
// argv[1] : Name of directory that we want to open
// argv[2]: Name of the file that we want to create.

struct FileInfo
{
	char Fname[230];
	int fsize;
};

int main(int argc, char* argv[])
{
	DIR *dp=NULL;
	struct FileInfo fobj;
	struct stat sobj;
	struct dirent *dip=NULL;
	char buffer[1024]={'\0'};
	
	int ret=0;
	int fd_dest=0, fd_src=0;

	char name[512]={'\0'};

	if(argc != 3)
	{
		printf("Error: Insufficient argument.\n");
		printf("Usage: ./executable_file Directory_name file_name\n");
		printf("Directory Name: Name of the directory which contains the files we want to combine.\n");
		printf("File_Nmae: Name of the file which contains the data of all files.\n");
		return -1;
	}

	dp=opendir(argv[1]);
	if(dp == NULL)
	{
		printf("Error: Unable to open directory %s.\n", argv[1]);
		return -1;
	}
	fd_dest=creat(argv[2],0777);// Create new file to merge the data.\n
	if(fd_dest == -1)
	{
		printf("Unable: To create new file %s\n", argv[2]);
		closedir(dp);
		return -1;
	}

	//printf("Names of the files are\n");	
	while((dip=readdir(dp)) != NULL)
	{
		
		sprintf(name, "%s/%s", argv[1],dip->d_name);
		ret=stat(name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{	
			// Copy the contents of file into structure
			strcpy(fobj.Fname,dip->d_name);
			fobj.fsize=sobj.st_size;
			write(fd_dest,&fobj, sizeof(fobj));
		
			memset(&fobj,0,sizeof(fobj));// Zerout the memory(firstparameter array.)

			fd_src=open(name, O_RDONLY);	 //printf("%s: %ld\n", dip->d_name, sobj.st_size);
			
			while((ret=read(fd_src, &buffer, sizeof(buffer))) != 0)
			{
				write(fd_dest,buffer, ret);
			}
			memset(buffer, 0, sizeof(buffer));
			close(fd_src);
		}	
	}

	close(fd_dest);
	closedir(dp);
	return 0;
}




