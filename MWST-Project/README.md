#### Minimum Weight Spanning Tree    
   

### FILES:   
   
**mwst.cpp**: This file contains the code for calculating the minimum weight spanning tree of a given graph.   
  

**Makefile**: This file is used to compile the mwst.cpp file. Type "make" or "make all" to compile the code.   
Then type "MWST" followed by an input.txt file and an output.txt file in the command line to execute the code.  
For example: "MWST input.txt output.txt". Type "make clean" to remove all compiler generated files, including   
the "MWST" executable file.   
   
   
**Check**: This file is used to check the accuracy of the program. You can make this file executable by typing  
"chmod 700 Check" on UNIX timeshare, and then run it by typing "Check input-file output-file".   
   

### INPUT FILE FORMAT:   
The first two lines of the input file must contain single integers n and m, where n specifies the number of   
vertices and m specifies the number of edges in input graph G. The next m lines each contain two integers   
separated by spaces that specifies the vertex level and on the same line will include the weight of the given   
edge (also separated by a space).   
   

### OUTPUT FILE FORMAT:   
The output file will contain n lines. The first n-1 lines will display the edges of the MWST calculated in the   
format: "label: (end1, end2) weight". The last line in the file will give the total weight of the spanning tree.   
   

   