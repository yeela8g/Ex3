#include "GetOutput.h"

GetOutput::GetOutput(){};

void GetOutput::setPresicion(double toPrint){ //gets double type and check whethere its valuse is integer or float - and print accordingly
    fixed(std::cout);
    int intForm = (int)toPrint;
    if(toPrint == intForm) {
        std::cout.precision(afterPointInt);
    }else{
        std::cout.precision(afterPointDouble);
    }
    std::cout << toPrint << std::endl;
}

void GetOutput::printDist(Vector v1,Vector v2){
    Dist dis; //creat object of distance calculation class
    setPresicion(dis.euclideanDistance(v1,v2)); //calculations using dis.methods
    setPresicion(dis.manhattanDistance(v1,v2));
    setPresicion(dis.ChebyshevDistance(v1,v2));
    setPresicion(dis.CanberraDistance(v1,v2));
    setPresicion(dis.MinkowskiDistance(v1,v2,dis.p));
}