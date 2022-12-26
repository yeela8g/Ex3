output: main.o Dist.o GetInput.o GetOutput.o InputValidation.o Vector.o Knn.o KnnManager.o
	g++ main.o Dist.o GetInput.o GetOutput.o InputValidation.o Vector.o Knn.o KnnManager.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Dist.o: Dist.cpp Dist.h
	g++ -std=c++11 -c Dist.cpp

GetInput.o: GetInput.cpp GetInput.h
	g++ -std=c++11 -c GetInput.cpp

GetOutput.o: GetOutput.cpp GetOutput.h
	g++ -std=c++11 -c GetOutput.cpp

InputValidation.o: InputValidation.cpp InputValidation.h
	g++ -std=c++11 -c InputValidation.cpp

Vector.o: Vector.cpp Vector.h
	g++ -std=c++ -c Vector.cpp

Knn.o: Knn.cpp Knn.h
	g++ -std=c++11 -c Knn.cpp

KnnManager.o: KnnManager.cpp KnnManager.h
	g++ -std=c++11 -c KnnManager.cpp

clean:
	rm *.o output
