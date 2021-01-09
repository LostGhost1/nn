#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *f=fopen("testdata","w");
	for(int i=0;i<100;i++){
		double x=(double)((rand()%200)-100);
		double y=(double)((rand()%200)-100);
		int result=(x>y)?-1:1;
		fprintf(f,"%f %f %d\n",x,y,result);
	}
	fclose(f);
	return 0;
}
