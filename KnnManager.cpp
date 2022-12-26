#include "KnnManager.h"

KnnManager::KnnManager(){};

void KnnManager::manage(int k, std::string path, std::string distanceMatric){
GetInput in;//input validation object
    std::list<std::string> featuresLabelsArr[2]; //create array to contain x and y list - strings type
    in.fileInput(path, featuresLabelsArr); //insert to the array the data from the file
   
    while(1){
        std::string xStr;
        std::getline(std::cin,xStr); //get features test-sample, as a sentence (with " ")
        std::list<Vector> xValidList;
        std::list<std::string> yValidList;
        std::list<std::string>::iterator itrY = featuresLabelsArr[1].begin(); //loop for data validation and creating vectors out of the strings
        for(std::list<std::string>::iterator itrX = featuresLabelsArr[0].begin(); itrX != featuresLabelsArr[0].end(); itrX++){
            in.input(*itrX, xStr);
            if(in.getValid_toMain() == true){
                Vector v1=in.getV1();  //vectors creation for x_i list
                xValidList.push_back(v1);
                yValidList.push_back(*itrY);
            }else{
                std::cout << "wrong training sample inserted" << std::endl;
            }
            itrY++;
        }
        
        if(k<1 || k>xValidList.size()){ //checking k values
        throw std::runtime_error("k out of range");
        }

        Vector xVect=in.getV2();//vectors creation for x test sample
        if(!xValidList.empty()){ //calculate k nearest neighbors in the list
            Knn knn(xValidList,yValidList,xVect,k,distanceMatric);
            knn.predict(); //calculat distances metrix, find k nearest neighbors and return most common label
        }
    }


}