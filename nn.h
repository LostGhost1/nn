#ifndef NN_H
#define NN_H
#include <stdio.h>
#include <stdlib.h>
#include "neuron.h"
struct nn{
	struct neuron **inputs;
	struct neuron *neuron;
	
};
void nn_feed(struct nn *nn, double x, double y, double expectedresult);
double nn_forward(struct nn *nn, double x, double y);
struct nn *nn_init();
#endif
