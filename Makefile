All : Server Client clean

Server: Dist.o GetInput.o InputValidation.o Knn.o Vector.o MyServer.o Server.o
	g++ Dist.o GetInput.o InputValidation.o Knn.o Vector.o MyServer.o Server.o -o Server

Client: Client.o MyClient.o InputValidation.o Vector.o
	g++ Client.o MyClient.o InputValidation.o Vector.o -o Client

Dist.o: Dist.cpp Dist.h
	g++ -std=c++11 -c Dist.cpp

GetInput.o: GetInput.cpp GetInput.h
	g++ -std=c++11 -c GetInput.cpp

InputValidation.o: InputValidation.cpp InputValidation.h
	g++ -std=c++11 -c InputValidation.cpp

Vector.o: Vector.cpp Vector.h
	g++ -std=c++11 -c Vector.cpp

Knn.o: Knn.cpp Knn.h
	g++ -std=c++11 -c Knn.cpp

Client.o: Client.cpp
	g++ -std=c++11 -c Client.cpp

MyClient.o: MyClient.cpp MyClient.h
	g++ -std=c++11 -c MyClient.cpp

Server.o: Server.cpp
	g++ -std=c++11 -c Server.cpp

MyServer.o: MyServer.cpp MyServer.h
	g++ -std=c++11 -c MyServer.cpp

clean:
	rm -f *.o
