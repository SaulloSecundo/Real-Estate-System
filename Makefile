CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

OBJS = main.o corretor.o imovel.o cliente.o funcoes_auxiliares.o tipoImovel.o

imobiliaria: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o imobiliaria
main.o: main.cpp corretor.h imovel.h cliente.h funcoes_auxiliares.h tipoImovel.h
	$(CXX) $(CXXFLAGS) -c main.cpp
corretor.o: corretor.cpp corretor.h 
	$(CXX) $(CXXFLAGS) -c corretor.cpp
imovel.o: imovel.cpp imovel.h tipoImovel.h
	$(CXX) $(CXXFLAGS) -c imovel.cpp
cliente.o: cliente.cpp cliente.h
	$(CXX) $(CXXFLAGS) -c cliente.cpp
funcoes_auxiliares.o: funcoes_auxiliares.cpp funcoes_auxiliares.h corretor.h cliente.h imovel.h
	$(CXX) $(CXXFLAGS) -c funcoes_auxiliares.cpp
tipoImovel.o: tipoImovel.cpp tipoImovel.h
	$(CXX) $(CXXFLAGS) -c tipoImovel.cpp
clean:
	rm -f *.o imobiliaria