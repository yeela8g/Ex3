#include "GetInput.h"

class GetOutput{ //prints disances results

public:
    static const int afterPointInt = 1; //number to print after point in case of integer value
    static const int afterPointDouble = 16;//number to print after point in case of float value
    GetOutput();//constructor
    void printDist(Vector v1,Vector v2);//print all distances method
    void setPresicion(double toPrint); //print by integer or float number
};
