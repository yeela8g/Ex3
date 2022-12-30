#include "myServer.h"

       myServer::myServer(std::string file1 ,int port1){ //constructor
            file = file1;
            port = port1;
        }

        void myServer::loadFile(){ // export from file all features aand labeles as strings
            GetInput in;//input validation object
            in.fileInput(file, featuresLabelsArr); //insert to the array the data from the file
            std::cout<< "features:"<<featuresLabelsArr[0].size()<<", lables:"<<featuresLabelsArr[1].size()<<std::endl;
        }

         void myServer::communicate(){ // create connection with client and conversate with him by getting (x,metric,k) or "-1" and sending classification (or invalid input). 
            std::cout<< "Creating server socket..." << std::endl;
            int sock= socket(AF_INET, SOCK_STREAM, 0); //create a TCP socket 
            if(sock < 0){
                perror("couldn't create socket");
                exit(1);
            }
            std::cout << "creating server struct"<<std::endl;
            struct sockaddr_in serverAdress; //create server address details struct
            memset(&serverAdress,0, sizeof(serverAdress));
            serverAdress.sin_family = AF_INET;
            serverAdress.sin_addr.s_addr = INADDR_ANY;
            serverAdress.sin_port = htons(port);
            std::cout << "Binding socket to address & port..." << std::endl;
            if (bind(sock, (const sockaddr *)&serverAdress, sizeof(serverAdress)) < 0) {// bind() assigns the socket to an IP address and a port
                perror("error binding socket");
                exit(1);
            }
            std::cout << "Setup successful!"<< std::endl;
            if(listen(sock,5)<0){ // listen up to 5 clients
                perror("error accepting client");
                exit(1);
            }
            std::cout << "listening..."<< std::endl;
            while (1)
            {
                struct sockaddr_in clientAddress;
                unsigned int client_addr_len = sizeof(clientAddress);
                int secondSock = accept(sock,(sockaddr *)&clientAddress, &client_addr_len); // create second socket after accepting client
                if (secondSock < 0){
                    perror("error accepting client");
                    exit(1);
                }
                std::cout << "client accepted!"<< std::endl;
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
                    std::cout << "Got message: \"" << buffer << "\"!!!" << std::endl;
                    std::string reply; //contain the message from server
                    reply = "temp answer" ;// need to change !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    int sent_bytes = send(secondSock,reply.c_str(),reply.size(),0);
                    if (sent_bytes < 0){
                        perror("error sending to client");
                        break;
                    }
                    std::cout<<"message sent"<<std::endl;
                }
                if (close(secondSock) < 0){ //close connection eith this client and connect to new client
                    perror("ERROR - closing client-specific socket failed: ");
                    exit(1);
                }
                std::cout<<"second socket closed"<<std::endl;
            }
         }
