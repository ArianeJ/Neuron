#include <iostream>
#include "Neuron.cpp"
#include <random>
#include <vector>
#include <cstdlib>
#include <fstream>
int main(){								//il faudrait normaliser toutes ces valeurs													
	double D(1.5e-3);					//variables initialisees dans le papier	
	int d(15);						// D = d * 0.1e-3  (pour aller avec l'incrément unité)
	double Vth(2.0e-2);
	double Vreset(0.0);
	double H(0.1e-3);
	int h(1);						// H = h * 0.1e-3	(incrément unité)
	int CE(1000);					//nombre de connections venant de neurones excitatory
	int CI(250);						//nombre de connections venant de neurones inhibitory
	double JI(0.5e-3);						//puissance des connections inhibitrices (en mV)
	double JE(0.1e-3);						//puissance des connections excitatrices
	
	int nombreIntervalle(1000);			//variables initialisees par moi
	double a(50);
	double b(850);
	double Iext(1.01);
	int Nbr_Neuron(12000);				//nombre de neurons
	
										
	
	vector<Neuron>neurons;	//initialisation des tableaux ; créations des neurones
	neurons.reserve(12500);
	for(int i(0);i<10000;++i){
		neurons.push_back(Neuron(JE));};	//tstart = 0	//ne met pas de nom (sinon c'est le même neuron)
	for(int i(10000);i<12500;++i){
		neurons.push_back(Neuron(JI));};
	double globalClock(0);    			//pour obtenir le temps réel, il suffit de faire (globalClock * 0.1e-3)
	
	int connection[Nbr_Neuron][CE+CI];	//création des connexions
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int>UniformDistribE(0,9999);
	uniform_int_distribution<int>UniformDistribJ(10000,12500);
	for(int i(0);i<Nbr_Neuron;++i){
		for(int j(0);j<1000;++j){
			connection[i][j]=UniformDistribE(gen);			//n° du neurone de la j-ème connexion de neurone i
		};										
		for(int j(1000);j<1250;++j){
			connection[i][j]=UniformDistribJ(gen);
		};
	};
	
	double buffer[Nbr_Neuron][nombreIntervalle +1];		//création du buffer
	bool refract[Nbr_Neuron][nombreIntervalle +1];		//je suppose qu'il est initialisé par défaut avec que des 0
	int resultat[Nbr_Neuron][nombreIntervalle +1]		//0 mean no spike, 1 mean spike
	                          
	ofstream fichier_potential("mebrane_potential",ios::out or ios::app);	//create a file in which is stocked tension
	fichier_potential<<globalClock ;
	for(auto N : neurons){
		fichier_potential<<" "<<N.GetTension();}					//y mettre les tensions de tous les neurones (vu que c'est des 0 on s'en fiche p-ê)
		
	//Lucie a écrit ofstream f_spikes_time  ("spikes_time");
		
	for(int k(1);k<nombreIntervalle;++k){				//boucle d'action
		for	(int i(0);i<10000){							//transmission des pics
			if (neurons[i].GetIfSpike()== true){
				for(auto j : connection[i]){
					buffer[j][globalClock + d]+= JE;};};
		};
		for (int i(10000);i<12500){
			if (neurons[i].GetIfSpike()== true){
				for(auto j : connection[i]){
					buffer[j][globalClock + d]+= JI;};};
		};
		for(auto N : neurons){
			N.SetRefr(refract[N][globalClock]);
			if((globalClock<a) or (globalClock>b)){						//Iext != 0 in [a,b]
				N.ProchaineTension(0,H,1,Vreset,Vth);				//Background et refractory inclus dans la fonction update
				N.SetTension(N.GetTension() + buffer[N][globalClock]);} //ligne n° N représente le n° du neurone	
			else{
				N.ProchaineTension(Iext,H,1,Vreset,Vth);
				N.SetTension(N.GetTension() + buffer[N][globalClock]);}
			if (N.GetIfSpike == true){
				for(int i(globalClock);i<globalClock + Tref;++i){
					refract[N][i]==true;};
				resultat[N][globalClock]=1;};
		};
		globalClock += h;};
																	//Et comment fait-on pour tracer des graphes ?
return 0 ;}

