#include <stdexcept>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include "InputValidation.h"

#define BUFFERSIZE 4096

class MyClient{
public:
MyClient();//constructor
void communicate(std::string ip,std::string port);//send vector,metric,k to server for classifying
bool validation(std::string str);//valid the vector,metric,k input from the user

};