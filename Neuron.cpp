#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <random>
#include "Neuron.hpp"

using namespace std;

Neuron::Neuron(double J)		
		: resistance(2.0e10),temps(0.0),tau(0.02),tension(0.0),spike(false),refractory(false),J(J)
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
															
void Neuron::ProchaineTension(double Iext, double h, int n,double Vreset,double Vth){
	static random_device rd;
	static mt19937 gen(rd());
	static poisson_distribution<>PoissonDistrib(2);
	for (int i(1);i<=n;++i){
		if (refractory == true){
			tension = Vreset;}
		else if (tension >=Vth){
			tension = Vreset;
			spike = true;}
		else{
			tension=tension*exp(-h/tau)+Iext*resistance*(1-exp(-h/tau))+0.1e-3*PoissonDistrib(gen);};
			temps= temps + h ;
spike = false;};}
		else{
			tension=tension*exp(-h/tau)+Iext*resistance*(1-exp(-h/tau))+0.1e-3*PoissonDistrib(rd);};
			temps= temps + h ;
			spike = false;};};
			
