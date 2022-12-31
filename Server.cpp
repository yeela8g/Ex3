#include "myServer.h"

int main (int argc, char *argv[]){
    if (argc == 3) { //check user gave ip and port
        int port; //port validation
        try {
             port = std::stoi(argv[2]); //check port is integer
        } catch(...){
            throw std::runtime_error("invalid port"); //not digit
        }
        if (port <= 0 || port >= 65536){ //chek port is in the right range
            throw std::runtime_error("invalid port");
        } else {
         myServer server(argv[1],port); // create myServer object with file and port members
         server.loadFile(); //extract th features and labels from the csv file - still as string
         server.communicate(); //classigy vector x to a client
        }
    } else {
        throw std::runtime_error("invalid input"); //unvalid number of arguments
    }
}