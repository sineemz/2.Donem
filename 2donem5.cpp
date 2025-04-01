#include<iostream>
#include<cmath>
using namespace std;
double fnk(double x){
	return exp(x)*log(x)-pow(x,2);
}
double Kiris(double a, double b){
	double x1, x2,x,dx;
	dx=abs(x2-x1);
	int i=0;
	while((dx>1e-5)&&(i<50)){
		x=x2-(x2-x1)*fnk(x2)/(fnk(x2)-fnk(x1));
		x1=x2;
		x2=x;
		dx=abs(x2-x);
		i++;
	}
	if(i>=50){
		cout<<" kokler bulunamadi"<<endl;
		return -99999;
	}
	else return x;
}
int main(){
	double a=1, b=2;
	cout<<" denklemin koku:"<<Kiris(a,b)<<endl;
	return 0;
}