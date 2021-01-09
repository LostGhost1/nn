#include "nn.h"
#include <stdio.h>
#include <time.h>
int main(){
	srand(time(NULL));
	FILE *f=fopen("testdata","r");
	double x,y;
	double result;
	struct nn *nn=nn_init();
	int a=0;
	while(fscanf(f,"%lf %lf %lf", &x, &y, &result)!=EOF){
		for(double i=-10;i<=10;i+=1){
			for(double j=-10;j<=10;j+=1){
				printf("% 02.0lf ",nn_forward(nn,i,j));
			}
			printf("\n");
		}
		nn_feed(nn,x,y,result);
//		scanf("%d",&a);
	}
	fclose(f);
	
	return 0;
}
