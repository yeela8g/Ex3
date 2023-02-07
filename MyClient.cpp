
#include "MyClient.h"

MyClient::MyClient(){}//constructor

void MyClient::communicate(std::string ip,std::string port1){
    int port; //validation to port value.
    try {
        port = std::stoi(port1);//port is integer
    } catch(...){
        throw std::runtime_error("invalid port");
    }
    if (port <= 0 || port >= 65536){//port is in range
        throw std::runtime_error("invalid port");
    } 
    int sock= socket(AF_INET, SOCK_STREAM, 0); //create a TCP socket 
    if(sock < 0){
        perror("couldn't create socket");
        exit(1);
    }
    
    struct sockaddr_in clientAdress; //create client address details struct
    memset(&clientAdress,0, sizeof(clientAdress));
    clientAdress.sin_family = AF_INET;
    clientAdress.sin_port = htons(port);
    if (inet_aton(ip.c_str(), &clientAdress.sin_addr) == 0){
        throw std::invalid_argument("IP Address is not valid");
    }
    if (connect(sock, (struct sockaddr *)&clientAdress, sizeof(clientAdress)) < 0){//concect to server
        perror("Could not connect to server");
        exit(1);
    }
    char buffer[BUFFERSIZE];
    while(1){
        std::string data;
        std::getline(std::cin,data);//ask from vector from user
        if (data == "-1"){//if user ask for exit by entering -1 -> disconnect from the server and close the client program (server still running)
            break;
        } 
        bool flag = validation(data);//validate input
        if (!flag){
            std::cout<<"invalid input"<<std::endl;
            continue;
        }
        if(send(sock,data.c_str(),strlen(data.c_str())+1,0) < 0) {//send input to server
            perror("error sending message to client");
            break;
        }
        bzero(buffer,BUFFERSIZE); //initiation
        int byte_read= recv(sock,buffer,sizeof(buffer),0); //get response from server
        if(byte_read < 0){
            perror("error reading server reply");
            break;
        }
        if(byte_read== 0){ //no response from client or client disconnected
            break;
        }
        std::cout << buffer << std::endl;//print the classification to the user
    }
    close(sock); //stop the connection to server-end the client program
}

bool MyClient::validation(std::string str){ //send user input for component seprating and validating
    InputValidation check;
    std::string vectorMatricK[3];
    if(!check.separateVectorMatricK(str, vectorMatricK)){
        return 0;
    }
    return check.validVectorMatricK(vectorMatricK);
}
