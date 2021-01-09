#ifndef NEURON_H
#define NEURON_H
#include <stdio.h>
#include <stdlib.h>
struct neuron{
	struct neuron **inputs;
	double *weights;
	unsigned long long ninputs;
	char fixedoutput;
	double output;
	
};
struct neuron *neuron_make_random();
struct neuron *neuron_make_fixed(double output);
double neuron_forward(struct neuron *neuron);
#endif
