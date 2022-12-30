#include "myClient.h"


int main(int argc, char *argv[]){
    if (argc != 3) { //validation ro argument number.
        throw std::runtime_error("invalid input");
    } 
    myClient client;
    client.communicate(argv[1],argv[2]);
}