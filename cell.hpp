#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <list>

namespace CL{
    struct cellType{
        std::string index;
        std::string strictType;
        std::string non_strictType;
    };


    class Sample{
        public:
            //constructors/destructors
            Sample();
            ~Sample();

            //public functions
            void parseFields(std::list <std::string> inList);

            //getters
            std::vector <CL::cellType*> const &getCells(){return cells;}
        private:
            std::vector <CL::cellType*> cells;

            CL::cellType *makeCell(std::string index_in, std::string strictType_in, std::string non_strictType_in);
    };
}