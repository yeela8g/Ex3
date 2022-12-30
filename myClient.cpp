
#include "myClient.h"

myClient::myClient(){}

void myClient::communicate(std::string ip,std::string port1){
    int port; //validation to port value.
    try {
        port = std::stoi(port1);
    } catch(...){
        throw std::runtime_error("invalid port");
    }
    if (port <= 0 || port >= 65536){
        throw std::runtime_error("invalid port");
    } 
    std::cout<< "Creating client socket..." << std::endl;
    int sock= socket(AF_INET, SOCK_STREAM, 0); //create a TCP socket 
    if(sock < 0){
        perror("couldn't create socket");
        exit(1);
    }
    std::cout << "creating client struct"<<std::endl;
    
    struct sockaddr_in clientAdress; //create client address details struct
    memset(&clientAdress,0, sizeof(clientAdress));
    clientAdress.sin_family = AF_INET;
    clientAdress.sin_port = htons(port);
    if (inet_aton(ip.c_str(), &clientAdress.sin_addr) == 0){
        throw std::invalid_argument("IP Address is not valid");
    }
    if (connect(sock, (struct sockaddr *)&clientAdress, sizeof(clientAdress)) < 0){
        perror("Could not connect to server");
        exit(1);
    }
    std::cout << "Connected to server!" << std::endl;
    char buffer[BUFFERSIZE];
    while(1){
        std::string data;
        std::getline(std::cin,data);
        if (data == "-1"){
            break;
        } 
        bool flag = validation(data);
        if (!flag){
            std::cout<<"invalid input"<<std::endl;
            continue;
        }
        if(send(sock,data.c_str(),strlen(data.c_str()),0) < 0) {
            perror("error sending message to client");
            break;
        }
        bzero(buffer,BUFFERSIZE); //initiation
        int byte_read= recv(sock,buffer,sizeof(buffer),0);
        if(byte_read < 0){
            perror("error reading server reply");
            break;
        }
        if(byte_read== 0){
            std::cout<<"byte_read== 0"<<std::endl;
            break;
        }
        std::cout<<buffer<<std::endl;
    }
    close(sock);
}

bool myClient::validation(std::string str){
    InputValidation check;
    return check.validVectorMatricK(str);
}