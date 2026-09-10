#include <stdio.h>
#include <math.h>

//creating a function
double f(double x){
	return exp(x)-2 ;
}
// differwential of that function
double df(double x){
	return exp(x) ;
}

int main(){
	double x=1;
	int n=100;
	//writing for loop for iltreation by newton rapson method
	for (int i=0;i<n;i++){
		x=x-f(x)/df(x);
	}
	printf("%.2lf/n",x);
}
