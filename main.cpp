#include "cell.hpp"
#include <list>


using namespace std;

/*data_filter
* Removes dropped/bunched cells from unmicst.csv file based on NA cell types from Kenichi's .csv file.
* Enter the location of Kenichi's file followed by the unmicst file (*.csv) as a command line argument when running the program.
* Program will write a copy of the unmicst file with the appropriate lines removed
*/

int readFileLines(string inFileName, list <string> &lineList);
void writeFileLines(string oFileName, list <string> &lineList);

int main(int argc, char **argv){
    if(argc != 3){
        cout << "Please enter the input files (*.csv) as a command line argument.\nProgram closing.\n";
        return 1;
    }
    string infilename = argv[1];
    string unmicstfilename = argv[2];
    string ofilename = unmicstfilename.substr(0,unmicstfilename.length()-4) + "-trimmed.csv";

    list <string> unmicstFile;
    int unmicstFileLength = readFileLines(unmicstfilename, unmicstFile);

    writeFileLines(ofilename, unmicstFile);

    return 0;
}

int readFileLines(string inFileName, list <string> &lineList){
    ifstream infile; infile.open(inFileName);
    string tmp = "";
    int fileLength = 0;
    lineList.clear();
    while(getline(infile, tmp)){
        lineList.push_back(tmp);
        fileLength++;
    }
    infile.close();
    return fileLength;
}

void writeFileLines(string oFileName, list <string> &lineList){
    ofstream oFile; oFile.open(oFileName);
    for(auto const& i : lineList){
        oFile << i << endl;
    }
}