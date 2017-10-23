#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <random>
#include "Neuron.hpp"

using namespace std;

Neuron::Neuron(double R, double t, double tau, double V, bool refr)
		: resistance(R),temps(t),tau(tau),tension(V),refractory(refr)
		{}

double Neuron::GetTension() const {       
	return tension;}
	
double Neuron::GetTime() const {
	return temps;}
	
bool Neuron::GetRefr() const {
	return refractory;}
	
void Neuron::SetTension(double V){
	tension = V;}
															
void Neuron::ProchaineTension(double Iext, double h, int n,double Vreset,double Vth,double CE,double J){
	random_device rd;
	poisson_distribution<>PoissonDistrib(Vth*CE*h*J);
	for (int i(1);i<=n;++i){						 		//to make an update of the Neuron features
		if (tension >=Vth){                             	//if the tension is to high, tension = Vreset
			tension = Vreset;
			refractory = true;}
		else{
			tension=tension*exp(-h/tau)+Iext*resistance*(1-exp(-h/tau))+ PoissonDistrib(rd);}; // equa diff solution
			temps= temps + h ;
			refractory = false;};};
			
int Neuron::NombrePic(double tini,double tfin,double Vth,int n,double h,double Iext,double Vreset,double CE,double J){
	int pic(0);                                             //pike are counted and stocked with time
	double temps_pic [2][n];
	for (int i(1);i<=n;++i){
		ProchaineTension(Iext,h,1, Vreset,Vth,CE,J);                                    
		temps_pic[0][i-1]=temps;
			if (tension >=Vth){
				pic+=1;
				temps_pic[1][i-1]=1;}                   	//in the table, "1" means pike,  "0" means no pike
			else {
				temps_pic[1][i-1]=0;};
			};
	cout<<temps_pic<<endl;
return pic;};
