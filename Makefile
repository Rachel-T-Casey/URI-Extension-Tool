

Output: Main.o Request.o RequestExtension.o Histogram.o testRequestExtension.o testHistogram.o
	g++ Main.o Request.o RequestExtension.o Histogram.o testRequestExtension.o testHistogram.o -o Output

Main.o: Main.cpp
	g++ -c Main.cpp
	
Request.o: Request.cpp Request.hpp
	g++ -c Request.cpp


RequestExtension.o: RequestExtension.cpp RequestExtension.cpp 
	g++ -c RequestExtension.cpp

Histogram.o: Histogram.cpp Histogram.hpp 	
	g++ -c Histogram.cpp

testRequestExtension.o: testRequestExtension.cpp testRequestExtension.hpp
	g++ -c testRequestExtension.cpp

testHistogram.O: testHistogram.cpp testHistogram.hpp
	g++ -c testHistogram.cpp
clean:
	rm *.o 