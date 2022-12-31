#include "myServer.h"

myServer::myServer(std::string file1 ,int port1){ //constructor
    file = file1;
    port = port1;
}

void myServer::loadFile(){ // export from file all features aand labeles as strings
    GetInput in;//input validation object
    in.fileInput(file, featuresLabelsArr); //insert to the array the data from the file
}

void myServer::communicate(){ // create connection with client and conversate with him by getting (x,metric,k) or "-1" and sending classification (or invalid input). 
    int sock= socket(AF_INET, SOCK_STREAM, 0); //create a TCP socket 
    if(sock < 0){
        perror("couldn't create socket");
        exit(1);
    }
    struct sockaddr_in serverAdress; //create server address details struct
    memset(&serverAdress,0, sizeof(serverAdress));
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_addr.s_addr = INADDR_ANY;
    serverAdress.sin_port = htons(port);
    if (bind(sock, (const sockaddr *)&serverAdress, sizeof(serverAdress)) < 0) {// bind() assigns the socket to an IP address and a port
        perror("error binding socket");
        exit(1);
    }
    if(listen(sock,5)<0){ // listen up to 5 clients
        perror("error accepting client");
        exit(1);
    }
    while (1){
        struct sockaddr_in clientAddress;
        unsigned int client_addr_len = sizeof(clientAddress);
        int secondSock = accept(sock,(sockaddr *)&clientAddress, &client_addr_len); // create second socket after accepting client
        if (secondSock < 0){
            perror("error accepting client");
            exit(1);
        }
        char buffer[BUFFERSIZE]; // contain the message from client
        while (1)
        {
            bzero(buffer,BUFFERSIZE); //initiation
            int read_bytes = recv(secondSock,buffer,sizeof(buffer),0); // get message
            if(read_bytes ==0){  // Read no bytes - either connection has closed or client taking too long // Let's exit
                break;
            } else if (read_bytes<0){
                perror("Error reading from connection socket");
                break;
            }
            std::string reply; //contain the message from server
            std::string vectorMatricK[3];// array to contain the 3 components of the client buffer
            InputValidation check; //validation of the client buffer
            bool separate = check.separateVectorMatricK(buffer, vectorMatricK); //separated the 3 components + validate there is enough input
            bool flag = check.validVectorMatricK(vectorMatricK); //validate the 3 components
            if (!(separate && flag)){
                reply = "invalid input" ;
            }else{
                reply = mngKnn(vectorMatricK[0], vectorMatricK[1], vectorMatricK[2]);//knn
            } 
            int sent_bytes = send(secondSock,reply.c_str(),reply.size(),0);//send response
            if (sent_bytes < 0){
                perror("error sending to client");
                break;
            }
        }
        if (close(secondSock) < 0){ //close connection eith this client and connect to new client
            perror("ERROR - closing client-specific socket failed: ");
            exit(1);
        }
    }
}

std::string myServer::mngKnn(std::string xStr, std::string metric, std::string kStr){
    GetInput in;
    std::list<Vector> xValidList;
    std::list<std::string> yValidList;
    std::list<std::string>::iterator itrY = featuresLabelsArr[1].begin(); //loop for data validation and creating vectors out of the strings
        for(std::list<std::string>::iterator itrX = featuresLabelsArr[0].begin(); itrX != featuresLabelsArr[0].end(); itrX++){
            in.input(*itrX, xStr);
            if(in.getValid_toMain() == true){
                Vector v1=in.getV1();  //vectors creation for x_i list
                xValidList.push_back(v1);
                yValidList.push_back(*itrY);
            }
            itrY++;
        }
        int k = std::stoi(kStr);
        if(k > xValidList.size()){ //checking k values
            return "invalid input";
        }
        Vector xVect=in.getV2();//vectors creation for x test sample
        if(!xValidList.empty()){ //calculate k nearest neighbors in the list
            Knn knn(xValidList,yValidList,xVect,k, metric);
            return knn.predict(); //calculat distances metrix, find k nearest neighbors and return most common label
        }else{
            return "invalid input";
        }
}










