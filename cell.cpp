#include "cell.hpp"

using namespace std;

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