all: network
gentestdata: gentestdata.c
	gcc -o gentestdata gentestdata.c
	./gentestdata
edit:
	nano main.c neuron.c nn.c
network: nn.o neuron.o main.o
	gcc -o network nn.o neuron.o main.o
nn.o: nn.c
	gcc -c nn.c
neuron.o: neuron.c
	gcc -c neuron.c
main.o: main.c
	gcc -c main.c
clean:
	rm *.o gentestdata network
