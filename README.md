# Ex3
---
## Description
The purpose this repository is to implement server-client communication where the clilent asks the server to classify a vector. client ask the user to enter input of the required vector, distance metric to calculate knn, and integer k of number of neighbors for the prediction.
the client validate the input and send it to the server. the server returns the knn prediction if the input is valid, otherwise returns "invalid input".

the server program input is:
- file path (with the classified dataset)
- port

the client program input is:
- server ip
- server port

## Optimization
- dedicated function of string input splitting and string input validation inside a class that recognized by Server and Client classes so they both could use it to Process the input
>this optimized our code by preventing code duplication.

## notes
- if the connection for some reason fails, error message will be presented and the client and server programs will be closed.
- for client disconnecting the user enter "-1", and the server will be able to connect to new client.

## How to use
>for running on university u2 server use the commands:

for running the server:
### $make
### $./Server [filePath] [port]

>and for running the client:
### $./Client [ip] [port]
>for example:
![image](https://user-images.githubusercontent.com/118124478/210151348-91fcf537-9960-4b52-8d91-b067cddcc837.png)





