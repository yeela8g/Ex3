#include "MyClient.h"


int main(int argc, char *argv[]){
    if (argc != 3) { //validation ro argument number.
        throw std::runtime_error("invalid input");
    } 
    MyClient client;
    client.communicate(argv[1],argv[2]);
}