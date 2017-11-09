#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <random>
#include "Neuron.hpp"

using namespace std;

Neuron::Neuron(double J)	///the only difference betwenn neurons are their inhibitory or excitatory nature, determined by J
		: resistance(2.0e10),temps(0.0),tau(0.02),tension(0.0),spike(false),refractory(false),J(J),buffer(16,0)
		{}

double Neuron::GetTension() const {       
	return tension;}
	
double Neuron::GetTime() const {
	return temps;}

double Neuron::GetJ() const {
	return J;}
	
void Neuron::CopyBuffer(unsigned int n){
	tension += buffer[n];}
	
void Neuron::SetBuffer(unsigned int n,double a){
	buffer[n]=a;}
	
bool Neuron::GetRefr() const {
	return refractory;}
	
void Neuron::SetTension(double V){
	tension = V;}
	
void Neuron::SetRefr(bool refr){
	refractory = refr;}
															
bool Neuron::ProchaineTension(double Iext, double h, int n,double Vreset,double Vth){
	static random_device rd;		
	static mt19937 gen(rd());
	static poisson_distribution<>PoissonDistrib(2);	///excitations coming from the rest of the brain
	for (int i(1);i<=n;++i){
		if (refractory == true){		///the neuron cannot spike if it is refractory
			tension = Vreset;			
			spike = false;}
		else if (tension >=Vth){
			tension = Vreset;
			spike = true;}
		else{
			tension=tension*exp(-h/tau)+Iext*resistance*(1-exp(-h/tau))+0.1e-3*PoissonDistrib(gen);
			spike = false;
			};
			temps= temps + h ;
	}
	return spike;						/// this assessment is useful in the main
}
