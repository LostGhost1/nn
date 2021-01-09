#include "neuron.h"
struct neuron *neuron_make_random(unsigned long long ninputs){
	struct neuron *result=malloc(sizeof(struct neuron));
	result->inputs=calloc(sizeof(struct neuron*),ninputs);
	result->ninputs=ninputs;
	result->weights=malloc(sizeof(double)*ninputs);
	for(unsigned long long i=1;i<ninputs;i++){
		result->weights[i]=((double)(rand()%200)-100)/(double)100;
	}
	result->weights[0]=0;
	result->fixedoutput=0;
	result->output=0;
	return result;
}
struct neuron *neuron_make_fixed(double output){
	struct neuron *result=calloc(sizeof(struct neuron),1);
	result->fixedoutput=1;
	result->output=output;
	return result;
}

double neuron_forward(struct neuron *neuron){
	neuron->output=0;
//	printf("output=");
	for(unsigned long long i=0;i< neuron->ninputs;i++){
//		printf("(%lf)*(%lf)+",(neuron->inputs[i]->output),(neuron->weights[i]));
		neuron->output+=(neuron->inputs[i]->output)*(neuron->weights[i]);
	}
//	printf("=%lf\n",neuron->output);
	if(neuron->output>0)neuron->output=1;
	if(neuron->output<=0)neuron->output=-1;
	return neuron->output;
//	printf("weights[0] %lf weights[1] %lf output %lf\n", neuron->weights[0],neuron->weights[1],neuron->output);
}
