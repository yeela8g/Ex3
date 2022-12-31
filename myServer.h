#include "Knn.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

#define BUFFERSIZE 4096

class myServer {
    private:
        std::string file;
        int port;
        std::list<std::string> featuresLabelsArr[2];

    public:
        myServer(std::string file,int port);//constructor
        void loadFile();// export from file all features aand labeles as strings
        void communicate();// create connection with client and conversate with him by getting (x,metric,k) or "-1" and sending classification (or invalid input).
        std::string mngKnn(std::string x, std::string metric, std::string k); //create vectors out of strings after validation of the vectors and their lengths relative to x
        
};