#include<iostream>
#include<cmath>
using namespace std;
const double h=6.62607015e-34;
const double c=3.0e8;
const double k=1.380649e-23;
double karaCisimIsimasi(double dalgaBoyu, double sicaklik){
	double pay =2.0*h*pow(c,3)/pow(dalgaBoyu,5);
	double us=(h*c)/(dalgaBoyu*k*sicaklik);
	double payda=exp(us-1.0);
	return pay/payda;
}
int main(){
	double dalgaBoyu,sicaklik;
	cout<<"Dalga boyunu giriniz(metre):"<<endl;
	cin>>dalgaBoyu;
	cout<<"Sicakligi giriniz(kelvin):"<<endl;
	cin>>sicaklik;
	double isima=karaCisimIsimasi(dalgaBoyu,sicaklik);
	cout<<"Kara cisim isima yogunlugu:"<<isima<<"w/m^2/sr/m"<<endl;
	return 0;
}