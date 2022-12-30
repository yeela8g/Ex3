#include "myServer.h"

int main (int argc, char *argv[]){
    if (argc == 3) {
        //validation
        int port;
        try {
             port = std::stoi(argv[2]);
        } catch(...){
            throw std::runtime_error("invalid port");
        }
        if (port <= 0 || port >= 65536){
            throw std::runtime_error("invalid port");
        } else {
         // create object with file and port members
         myServer server(argv[1],port);
         server.loadFile();
         server.communicate();
        }
    } else {
        throw std::runtime_error("invalid input");
    }
    
    //init file 
    
    //connection server with client
}