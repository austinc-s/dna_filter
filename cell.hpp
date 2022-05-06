#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

namespace CL{
    struct cellType{
        std::string index;
        std::string sampleNumber;
        std::string cellID;
        std::string strictType;
        std::string non_strictType;
    };


    class Sample{
        public:
            Sample();
            ~Sample();

            std::vector <CL::cellType*> const &getCells(){return cells;}
        private:
            std::vector <CL::cellType*> cells;
    };
}