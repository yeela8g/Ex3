
#include "KnnManager.h"

int main(int argc, char* argiv[]){
    if(argc != 4){
        throw std::runtime_error("invaild arguments number");
    }
    KnnManager mng;
    mng.manage(std::stoi(argiv[1]), argiv[2], argiv[3]);
}
