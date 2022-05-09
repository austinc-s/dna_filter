This program removes lines from an unmicst.csv file based on corresponding "NA" strict_type entries in cell type files provided by Kenichi Shimada.  
  
The program takes two required command line arguments: kenichi_file.csv and unmicst.csv  
To use the provided script, these files must have the same name but be placed in separate directories.  
These files must be for the correct/corresponding sample and, therefore, contain the same number of total lines. If they do not, the program will not run.  
  
Note that the cell index is not updated when lines are removed.