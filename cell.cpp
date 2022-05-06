#include "cell.hpp"

using namespace std;

CL::cellType *makeCell(std::string index_in, std::string sampleNumber_in, std::string cellID_in, std::string strictType_in, std::string non_strictType_in){
    CL::cellType* tmp = new CL::cellType;
    tmp->index = index_in;
    tmp->sampleNumber = sampleNumber_in;
    tmp->cellID = cellID_in;
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