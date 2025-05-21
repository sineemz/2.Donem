#include<iostream>
#include<cmath>
using namespace std;
double fnk(double x){
	return x*x-5;
}
double IntKbul(double a,double b){
	double dx,x1,x2,x;
	dx=abs(b-a);
	x1=a;x2=b;
	while(dx>1e-5){
		if(fnk(x1)*fnk(x2)<0){
			x=(x1+x2)/2;
			if(fnk(x1)*fnk(x)<0);
			x1=x;
		}
		else{
			cout<<"\n kok yok \n";
			return -99999;
		}
		dx=abs(x2-x1);
	}
	return x;
}
int main(){
	double a=0, b=5;
	cout<<"denklemin koku:"<<IntKbul(a,b)<<endl;
	return 0;
}
