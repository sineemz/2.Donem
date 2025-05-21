#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
double const PI=3.141593;
double const N=200;
int main(){
	double x1,v1,x2,v2,dt=PI/N, t=0;
	ofstream file("kutleyay.txt");
	x1=1;
	v1=0;
	cout<<setw(15)<<"zaman"<<setw(15)<<"hiz"<<setw(15)<<"konum"<<endl;
	cout<<setw(15)<<t<<setw(15)<<v2<<setw(15)<<x2<<endl;
	while (t<N){
		v2=v1+(-x1)*dt;
		x2=x1+(v1)*dt;
		t=t+dt;
		cout<<setw(15)<<t<<setw(15)<<v2<<setw(15)<<x2<<endl;
		v1=x2;
		x1=x2;
	}
	file.close();
	return 0;	
}
