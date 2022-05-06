#pragma once
#include <iostream>
#include <fstream>
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
            //constructors/destructors
            Sample();
            ~Sample();

            //public functions
            CL::cellType *makeCell(std::string index_in, std::string sampleNumber_in, std::string cellID_in, std::string strictType_in, std::string non_strictType_in);

            //getters
            std::vector <CL::cellType*> const &getCells(){return cells;}

            //setters
            void pushCell(CL::cellType* cell_in){ cells.push_back(cell_in);}
        private:
            std::vector <CL::cellType*> cells;
    };
}