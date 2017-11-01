#include <iostream>
#include "Neuron.cpp"
#include <random>
#include <vector>
#include <cstdlib>
int main(){								//il faudrait normaliser toutes ces valeurs
	const double Tau(0.02);				//variables initialisees dans le papier															
	double R(2.0e10);
	double D(1.5e-3);
	double d(15);						// D = d * 0.1e-3  (pour aller avec l'incrément unité)
	double Vth(2.0e-2);
	double Vreset(0.0);
	double H(0.1e-3);
	double h(1);						// H = h * 0.1e-3	(incrément unité)
	double CE(1000);					//nombre de connections venant de neurones excitatory
	double CI(250);						//nombre de connections venant de neurones inhibitory
	double JI(0.5e-3);						//puissance des connections inhibitrices (en mV)
	double JE(0.1e-3);						//puissance des connections excitatrices
	
	int nombreIntervalle(1000);			//variables initialisees par moi
	double a(0.2e-3);
	double b(0.8e-3);
	double V0(0.0);
	double Iext(1.01);
	int Nbr_Neuron(12000);				//nombre de neurons
	
	vector<Neuron>neurons(Nbr_Neuron);
	for(int i(0);i<10000;++i){
		neurons[i]=Neuron NE(R,0.0,Tau,V0,false,false,JE);};	//tstart = 0
	for(int i(10000);i<12500;++i){
		neurons[i]=Neuron NI(R,0.0,Tau,V0,false,false,JI);};
	double globalClock(0);    			//pour obtenir le temps réel, il suffit de faire (globalClock * 0.1e-3)
	
	int connection[Nbr_Neuron][CE+CI];	//création des connexions
	for(auto& i : connection){
		for(int j(0);j<1000;++j){
			connection[i][j]="randomnumber compris entre 0 et 10000"};  //trouver la fonction qui va nous donner ça bien
		for(int j(1000),j<1250;++j){
			connection[i][j]="randomnumber compris entre 10000 et 12500"};
	};
	                          
	ofstream fichier("membrane_potential",ios::out);	//create a file in which is stocked tension
	fichier<<globalClock ;
	for(auto N : neurons){
		fichier<<" "<<N.GetTension();}					//y mettre les tensions de tous les neurones (vu que c'est des 0 on s'en fiche p-ê)
		
	double buffer[Nbr_Neuron][nombreIntervalle +1];		//création du buffer
	bool refract[Nbr_Neuron][nombreIntervalle +1];		//je suppose qu'il est initialisé par défaut avec que des 0
	
	for(int k(1);k<nombreIntervalle;++k){							//Détail supplémentaire : le temps réfractory	
		for	(int i(0);i<10000){
			if (neurons[i].GetIfSpike()== true){
				for(auto j : connection[i]){
					buffer[j][globalClock + d]+= JE;};};
		};
		for (int i(10000);i<12500){
			if (neurons[i].GetIfSpike()== true){
				for(auto j : connection[i]){
					buffer[j][globalClock + d]+= JI;};};
		};
	};
		N.SetRefr(refract[N][globalClock]);
		if((globalClock<a) or (globalClock>b)){						//Iext != 0 in [a,b]
			N.ProchaineTension(0,H,1,Vreset,Vth,CE,J);				//Background et refractory inclus dans la fonction update
			N.SetTension(N.GetTension() + buffer[N][globalClock]);} //ligne n° N représente le n° du neurone	
		else{
			N.ProchaineTension(Iext,H,1,Vreset,Vth,CE,J);
			N.SetTension(N.GetTension() + buffer[N][globalClock]);}
		if (N.GetIfSpike == true){
			for(int i(globalClock);i<globalClock + Tref;++i){
				refract[N][i]==true;};};
		
		globalClock += h;
																	//Et comment fait-on pour tracer des graphes ?
return 0 ;}
