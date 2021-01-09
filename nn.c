#include "nn.h"
struct nn *nn_init(){
	struct nn *result = malloc(sizeof(struct nn));
	result->inputs=malloc(sizeof(struct neuron*)*3);
	result->inputs[1]=neuron_make_fixed(0);
	result->inputs[2]=neuron_make_fixed(0);
	result->neuron=neuron_make_random(3);
	result->neuron->inputs[0]=neuron_make_fixed(1);
	result->neuron->inputs[1]=result->inputs[1];
	result->neuron->inputs[2]=result->inputs[2];
	return result;
}
void nn_feed(struct nn *nn, double x, double y, double expectedresult){
	nn->inputs[1]->output=x;
	nn->inputs[2]->output=y;
	neuron_forward(nn->neuron);
	//double error=(((double)expectedresult)-(nn->neuron->output));
	//double error=((nn->neuron->output)-((double)expectedresult));
	printf("w[1]=%lf w[2]=%lf correct=%lf result=%lf\n",nn->neuron->weights[1],nn->neuron->weights[2],((double)expectedresult),nn->neuron->output);
	if(((nn->neuron->output)*(expectedresult))>0){
	//printf("Classified correctly\n");
	return;}
//	printf("Classified incorrectly, adjusting...\n");
//	printf("w[0](%lf)+=0,2*%d*1\n",nn->neuron->weights[0],((expectedresult>0)?1:-1));
	nn->neuron->weights[0]+=(0.2)*((expectedresult>0)?1:-1)*1;
//	printf("w[1](%lf)+=0,2*%d*%lf\n",nn->neuron->weights[1],((expectedresult>0)?1:-1),x);
	nn->neuron->weights[1]+=(0.2)*((expectedresult>0)?1:-1)*x;
//	printf("w[2](%lf)+=0,2*%d*%lf\n",nn->neuron->weights[2],((expectedresult>0)?1:-1),y);
	nn->neuron->weights[2]+=(0.2)*((expectedresult>0)?1:-1)*y;
//	printf("Now weights are %lf %lf %lf\n",nn->neuron->weights[0],nn->neuron->weights[1],nn->neuron->weights[2]);
	
}
double nn_forward(struct nn *nn, double x, double y){
	nn->inputs[1]->output=x;
	nn->inputs[2]->output=y;
	neuron_forward(nn->neuron);
	return nn->neuron->output;
}
