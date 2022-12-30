#include "InputValidation.h"
#include <cctype>
#include <cstring>

InputValidation::InputValidation(){};

void InputValidation::setValid(bool flag){
    valid = flag;
}

bool InputValidation::getValid(){
    return valid;
}

void InputValidation::vectorSize(Vector v1, Vector v2){
    std::vector<double> vec_v1 = v1.getVec();
    std::vector<double> vec_v2 = v2.getVec();
    if(vec_v1.size()!=vec_v2.size()){
         setValid(false);
    }
}

 void InputValidation::zeroDivision(Vector v1, Vector v2){
    std::vector<double> vec_v1 = v1.getVec();
    std::vector<double> vec_v2 = v2.getVec();
    std::vector<double>::iterator itr_v2 = vec_v2.begin();//get v2 iterator 
    for (std::vector<double>::iterator itr_v1 = vec_v1.begin(); itr_v1 != vec_v1.end(); itr_v1++)//go throught v1 
    {
        if(*itr_v1==0 && *itr_v2==0){//check no zero in both vectors position
            setValid(false);
        }
        *itr_v2++; //increament
    }
 }

 void InputValidation::isEmpty(Vector v1){
    std::vector<double> vec_v1 = v1.getVec();
    if (vec_v1.empty()){
        setValid(false);
    }
 }

 void InputValidation::isNumber(std::string str){ 
    std::stringstream sstrim(str); //streaming the input
    std::string newStr; //new string to contain each word from the input string which be converted to double
       try{
            while(std::getline(sstrim,newStr,' ')){
                int pointCount=0; //prevent two points like 2..0
                for (int i = 0; i < newStr.length(); i++){ 
                    if(newStr[i]=='.'){ // counting points
                        pointCount++;
                    }
                    if (!(newStr[i]=='.') &&(!isdigit(newStr[i]))){ //make sure it's a digit or a point
                       return setValid(false);
                    }
                }if (pointCount>1){ //prevent two points like 2..0
                    return setValid(false);
                }
                if (newStr[newStr.length()-1] == '.'){ //prevent 2.
                    return  setValid(false);
                }
                stod(newStr);
               
                
            }
        }catch (...) {
            
            return setValid(false);
        }
}

bool InputValidation::validVectorMatricK(std::string str){
    std::list<std::string> separatedStr;
    std::stringstream ss(str);  //wrapping line for the getline function
    std::string word;
    while(std::getline(ss, word, ' ')){  //separetad each line by comma into the container
        separatedStr.push_back(word);
    }
    if (separatedStr.size() < 3){
        return 0;
    }
    std::string k = (separatedStr.back()); //push into k the last string from the user input
    separatedStr.pop_back(); //remove the k from the list
    std::string matric = (separatedStr.back()); //push into matric the second from the end user input
    separatedStr.pop_back(); //remove the matric from the list
    std::string x ="";
    for(std::list<std::string>::iterator itrSeparatedStr = separatedStr.begin(); itrSeparatedStr != separatedStr.end(); itrSeparatedStr++){
        x += *itrSeparatedStr; //creating string of features
        x += " ";
    }
    bool flag = 1;
    isNumber(x);
    if(getValid()== false || x.empty()){
        return 0;
    }
    if(matric!="AUC" && matric!="CHB" && matric!="CAN" && matric!="MIN" && matric!="MAN"){
        return 0;
    }
    isNumber(k);
    if (getValid()== false){
        return 0;
    } 
    if(std::stoi(k)!= std::stod(k)){
        return 0;
    } else if (std::stoi(k)<1){
        return 0;
    }
    return 1; // vector, distance and k are valid
}
 
