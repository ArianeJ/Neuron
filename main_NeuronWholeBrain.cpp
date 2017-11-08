#include <iostream>
#include "Neuron.hpp"
#include <random>
#include <vector>
#include <cstdlib>
#include <fstream>
int main(){							// informations given in the paper
	int const d(15);						// D = d * 0.1e-3 
	double const Vth(2.0e-2);
	double const Vreset(0.0);
	double const H(0.1e-3);
	int const h(1);						// H = h * 0.1e-3
	int const CE(1000);					//excitatory connection
	int const CI(250);					//inhibitory connection
	double const JI(-0.5e-3);				
	double const JE(0.1e-3);				
	int const tref(20);					//Tref = 2 ms
	
	int const nombreIntervalle(1000);		
	double const Iext(0);
	int const Nbr_Neuron(12500);			
	
										
	
	vector<Neuron>neurons;	// creation of neurons
	neurons.reserve(Nbr_Neuron);
	for(int i(0);i<10000;++i){
		neurons.push_back(Neuron(JE));};	//excitator neurons
	for(int i(10000);i<12500;++i){
		neurons.push_back(Neuron(JI));};	//inhibitor neurons
	int globalClock(0);    					//real time = globalClock * 0.1e-3
	cout<<"neurones initialise"<<endl;
	
	vector<vector<int> >connection(Nbr_Neuron, vector<int>(CE+CI));		//	initialization of connections
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<int>UniformDistribE(0,9999);
	static uniform_int_distribution<int>UniformDistribJ(10000,12499);
	for(int i(0);i<Nbr_Neuron;++i){
		for(int j(0);j<1000;++j){
			connection[i][j]=UniformDistribE(gen);	//the table contain the n° of the neuron which make the n°j connection with neuron n°i
		};										
		for(int j(1000);j<1250;++j){
			connection[i][j]=UniformDistribJ(gen);
		};
	};
	
	cout<<"connection initialise"<<endl;

	vector<vector<bool> >refract(Nbr_Neuron,vector<bool>(nombreIntervalle +1));		//we guess it is initialized with false
	                        
	ofstream file_spikes("spikes");
		
	for(int k(1);k<nombreIntervalle;++k){				//action
		for(int i(0);i<Nbr_Neuron;++i){
			neurons[i].SetRefr(refract[i][globalClock]);
			neurons[i].CopyBuffer(globalClock%16);	// ajouter buffer et supprimer et creer la methode
			neurons[i].SetBuffer(globalClock%16,0.0);
			if (neurons[i].ProchaineTension(Iext,H,1,Vreset,Vth) == true){
				for(int elem : connection[i]){
					neurons[elem].SetBuffer((globalClock + d)%16,neurons[elem].GetJ());		//(clock + delai) % 16 += J
					cout<<"le buffer se remplit"<<i<<", "<<elem<< endl;	//segmentation fault
				};
				for(int j(globalClock);j<globalClock + tref;++j){
					refract[i][j]=true;
					cout<<"le tableau refract se remplit"<<endl;
				};
				file_spikes<<globalClock<<"\t"<<i<<"\n";
				cout<<globalClock<<"\t"<<i<<"\n";		//mettre le temps en ms
			};
		};
		globalClock += h;
	};
	file_spikes.close();
return 0 ;}

