# Ex1_2
---
## Description
the purpose of the program in this milestone is to impement KNN machine learning algorithm.Given a classified dataset, the KNN algorithm predict the label of test a sample by its similarity to features of other samples. it calculates similarity by distance metrics, choose the k closest samples to the test sapmle with the lowest distances, and returns the most common label among them.

the input of the algorithm is:
- k (number of closest neighbors to predict by them)
- file path (with the classified dataset)
- distance metric (auclidean/manhatten/chebishev/canberra/minkovski formula)
- features of the test sample
and the output is the predicted label of the sample.
for example: ![image](https://user-images.githubusercontent.com/118124478/206866038-b80ab769-8a18-4c6a-bab2-71b6956416d9.png)


## Optimization
- created dedicated class ('KnnManager') for controlling the algorithm flow.
>this optimized our code by maintaining the main class simple and clean.

## edge cases treatment
- in case of equality between labels the knn will select the first Label that appears in the dataset.
- in case of sample in the dataset with invalid values, the program will print a message and will keep predicting without it.
- in case of invalid input of one of the program's three arguments (k/path/distance metric), or missing arguments, a runtime error will be thorwed and the program will end.
- for calculating minkovski distance we chose constant p = 2;


## How to use
for running on university u2 server use the commands:
### $make
### $./output [k] [path] [distance-metric]
>for example:
![image](https://user-images.githubusercontent.com/118124478/206895893-77e1c9b2-d177-4eb1-b089-2f2cb0197057.png)





