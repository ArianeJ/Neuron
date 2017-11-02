#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <random>
#include "Neuron.hpp"

using namespace std;

Neuron::Neuron(double R, double t, double tau, double V, bool spik)
		: resistance(R),temps(t),tau(tau),tension(V),spike(spik)
		{}

double Neuron::GetTension() const {       
	return tension;}
	
double Neuron::GetTime() const {
	return temps;}
	
bool Neuron::GetIfSpike() const {
	return spike;}
	
bool Neuron::GetRefr() const {
	return refractory;}
	
void Neuron::SetTension(double V){
	tension = V;}
	
void Neuron::SetRefr(bool refr){
	refractory = refr;}
															
void Neuron::ProchaineTension(double Iext, double h, int n,double Vreset,double Vth,double CE,double J){
	random_device rd;
	poisson_distribution<>PoissonDistrib(Vth*CE*h*J);
	for (int i(1);i<=n;++i){						 		//to make an update of the Neuron features
		if (refractory == true){
			tension = Vreset;}
		else if (tension >=Vth){                             	//if the tension is to high, tension = Vreset
			tension = Vreset;
			spike = true;}
		else{
			tension=tension*exp(-h/tau)+Iext*resistance*(1-exp(-h/tau))+ PoissonDistrib(rd);}; // equa diff solution
			temps= temps + h ;
			spike = false;};};
			
return pic;};

