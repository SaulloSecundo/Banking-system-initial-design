
# alvo padrão
all: Executavel

# objetos
cliente.o: Cliente.cpp Cliente.h
	g++ -c Cliente.cpp -o cliente.o

contaBancaria.o: ContaBancaria.cpp ContaBancaria.h Cliente.h
	g++ -c ContaBancaria.cpp -o contaBancaria.o

main.o: main.cpp ContaBancaria.h Cliente.h
	g++ -c main.cpp -o main.o

# linkagem do executável
Executavel: main.o cliente.o contaBancaria.o
	g++ main.o cliente.o contaBancaria.o -o Executavel

clean:
	rm -f *.o Executavel