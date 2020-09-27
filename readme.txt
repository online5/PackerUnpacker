Welcome packer and unpacker application.

In this application we take files as a input, gather the data from each and every file and combine them together into a combined file.
This file consist of metadata about our files(taken as input) as well as the content within them.

After packing phase this combined file is passed on to the next phase i.e the unpacking phase where the original files are created basesd upon the data within packing phase.


To run this application use the following commands

1: First run packed.c file
a: gcc packed.c -o <executable_file_name>
b: ./<executable_file_name> <DirectoryFileName> <FileName>

Explaination: <DirectoryFileName> : Name of the directory which contains all our files.
	      <FileName>: FileName which is created at runtime and contains metadata as well as data of our file.


After the end of packing phase we would have our file say CombinedText.txt. 

2: Second phase run unpacked.c file
a: gcc unpacked.c -o <exectable_file_name>
b: ./<exectable_file_name> <FileName> <DirectoryName>

Explaination for arguments:
	<FileName>: File text which consist of all data of files and their meta data;
	<DirectoryName>: Name of the directory which is given at runtime, which is created to store our newly created files.

After unpacking phase we would have a directory which would containg all the files.

For more info please refer the digram.
 
