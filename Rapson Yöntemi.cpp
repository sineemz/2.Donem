#include<iostream>
#include<cmath>
#include<locale.h>
using namespace std;
float fnk(float x, float T){
	return x-tanh(4*x/T);
}
float trv (float x, float T){
	float h=1e-5;
	return(fnk(x+h,T)-fnk(x-h,T))/(2*h);
}
float NRapson(float x, float T){
	float dx,xk;
	int i=0;
	xk=x-fnk(x,T)/trv(x,T);
	dx=abs(xk-x);
	x=xk;
	while(dx>1e-5&&i<50){
		xk=x-fnk(x,T)/trv(x,T);
		dx=abs(xk-x);
		x=xk;
	}
	if(i==50){
		cout<<"\n kok yok \n";
		return -99999;
	}
	else 
	return xk;
}
int main(){
	int i=0;
	float t,dx;
	dx=1e-1;
	for(i=1;i<50;i++){
		t=t+i*dx;
		cout<<"Denklemin koku:"<<t<<" "<<NRapson(2,t)<<"\n";
		
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
