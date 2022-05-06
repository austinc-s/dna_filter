#include "cell.hpp"

using namespace std;

/*parseFields
* Given a list of strings from Kenichi's DAPHNe cell type file, parses into cellType struct fields
* WARNING: Inherently flawed due to input format and ONLY useful for this exact purpose
* .csv logic for parsing
* Returns void; Fills the cells vector with cellType structs
*/
void CL::Sample::parseFields(std::list <std::string> inList){
    for(auto const& line : inList){ //for each line in the list
        char delimiter = ',';
        vector <string> ar;
        stringstream lineStream(line);
        string token;

        while(getline(lineStream, token, delimiter)){ //pushes all fields into ar
            ar.push_back(token);
        }

        CL::cellType* tmp = makeCell(ar.at(0), ar.at(1), ar.at(2));
        cells.push_back(tmp);
    }
}

/*makeCell()
* Allocates memory for a cellType struct and initializes fields with the function parameters
* Returns a pointer to the cellType struct
*/
CL::cellType* CL::Sample::makeCell(std::string index_in, std::string strictType_in, std::string non_strictType_in){
    CL::cellType* tmp = new CL::cellType;
    tmp->index = index_in;
    tmp->strictType = strictType_in;
    tmp->non_strictType = non_strictType_in;
    return tmp;
}

/*Sample()
* Default constructor for Sample class
*/
CL::Sample::Sample(){}

/*~Sample()
* Destructor for Sample class
*/
CL::Sample::~Sample(){
    for(int i = 0; i < cells.size(); i++){ delete cells.at(i); cells.at(i) = NULL;}
}