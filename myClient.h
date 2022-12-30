#include <stdexcept>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include "InputValidation.h"

#define BUFFERSIZE 4096

class myClient{
public:
myClient();
void communicate(std::string ip,std::string port);
bool validation(std::string str);

};