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

 void InputValidation::isEmpty(Vector v1, Vector v2){
    std::vector<double> vec_v1 = v1.getVec();
    std::vector<double> vec_v2 = v2.getVec();
    if (vec_v1.empty() || vec_v2.empty()){
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
 
