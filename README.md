# PackerUnpacker
Welcome packer and unpacker application.

In this application, we take files as input, gather the data from each file, and combine them into a merged file.
This file consists of metadata about our files(taken as input) and the content within them.

After the packing phase, this combined file is passed on to the next phase i.e the unpacking phase where the original files are created based upon the data within the packing phase.


To run this application use the following commands

1: First run packed.c file
a: gcc packed.c -o <executable_file_name>
b: ./<executable_file_name> <DirectoryFileName> <FileName>

Explaination: <DirectoryFileName> : Name of the directory which contains all our files.
	      <FileName>: FileName which is created at runtime and contains metadata as well as data of our file.


After the end of the packing phase, we would have our file say CombinedText.txt. 

2: Second phase run unpacked.c file
a: gcc unpacked.c -o <exectable_file_name>
b: ./<exectable_file_name> <FileName> <DirectoryName>

Explanation for arguments:
	<FileName>: File text which consists of all data of files and their metadata;
	<DirectoryName>: Name of the directory which is given at runtime, which is created to store our newly created files.

After the unpacking phase, we would have a directory that would contain all the files.

For more info please refer the diagram.
