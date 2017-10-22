#include<iostream>
#include<math.h>
#include<vector>
#include<fstream>
#include "Neuron.hpp"
using namespace std;

double Neuron::GetTension() const {       
	return tension;}
	
double Neuron::GetTime() const {
	return temps;}
	
bool Neuron::GetRefr() const {
	return refractory;}
	
void Neuron::SetTension(double V){
	tension = V;}
															
void Neuron::prochaine_tension(double Iext, double h, int n,double Vreset,double Vth){
	for (int i(1);i<=n;++i){						 		//to make an update of the Neuron features
		if (tension >=Vth){                             	//if the tension is to high, tension = Vreset
			tension = Vreset;
			refractory = true;}
		else{
			tension=tension*exp(-h/tau)+Iext*resistance*(1-exp(-h/tau));}; // equa diff solution
			temps= temps + h ;
			refractory = false;};};
			
int Neuron::nombre_pic(double tini,double tfin,double Vth,int n,double h,double Iext,double Vreset){
	int pic(0);                                             //pike are counted and stocked with time
	double temps_pic [2][n];
	for (int i(1);i<=n;++i){
		prochaine_tension(Iext,h,1, Vreset,Vth);                                    
		temps_pic[0][i-1]=temps;
			if (tension >=Vth){
				pic+=1;
				temps_pic[1][i-1]=1;}                   	//in the table, "1" means pike,  "0" means no pike
			else {
				temps_pic[1][i-1]=0;};
			};
	cout<<temps_pic<<endl;
	return pic;};
