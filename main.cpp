#include "cell.hpp"

using namespace std;

/*data_filter
* Removes dropped/bunched cells from unmicst.csv file based on NA cell types from Kenichi's .csv file.
* Enter the location of Kenichi's file followed by the unmicst file (*.csv) as a command line argument when running the program.
* Program will write a copy of the unmicst file with the appropriate lines removed
*/

int readFileLines(string inFileName, list <string> &lineList);
void writeFileLines(string oFileName, list <string> &lineList);
void trimCells(CL::Sample &sample, list <string> &lineList);

int main(int argc, char **argv){
    if(argc != 3){
        cout << "Please enter the input files (*.csv) as a command line argument.\nProgram closing.\n";
        return 0;
    }
    string infilename = argv[1];
    string unmicstfilename = argv[2];
    string ofilename = unmicstfilename.substr(0,unmicstfilename.length()-4) + "-trimmed.csv";

    //read unmicst file
    //note that the first line is just headings
    list <string> unmicstFile;
    int unmicstFileLength = readFileLines(unmicstfilename, unmicstFile);

    //read Kenichi's file
    //note that the first line is just headings
    list <string> kenichiFile;
    int kenichiFileLength = readFileLines(infilename, kenichiFile);

    //check that they are the same length
    if(unmicstFileLength != kenichiFileLength){
        cout << "File lengths do not match. Check that corresponding files were entered.\nProgram closing.\n";
        return 0;
    }

    //parse Kenichi's file into fields
    CL::Sample sample = CL::Sample();
    sample.parseFields(kenichiFile);

    //remove lines where strictType is NA
    trimCells(sample, unmicstFile);

    //write the unmicst file which now excludes the dropped cells
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

void trimCells(CL::Sample &sample, list <string> &lineList){
    //iterate through cells vector in sample
    //if strictType == NA, remove that entry from lineList
    //need to track which entries are removed for purposes of offsetting the list iterator properly
    int removed = 0;
    list<string>::iterator it1;
    for(int i = 0; i < sample.getCells().size(); i++){
        it1 = lineList.begin();
        if(sample.getCells().at(i)->strictType.compare("NA") == 0){
            advance(it1, (i-removed));
            lineList.erase(it1);
            removed++;
        }
    }
}