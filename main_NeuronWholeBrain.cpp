#include <iostream>
#include "Neuron.cpp"
#include <random>
int main(){
	const double Tau(0.02);				//variables initialisees dans le papier															
	double R(2.0e10);
	double D(1.5e-3);
	double d(15);						// D = d * 0.1e-3  (pour aller avec l'incrément unité)
	double J(0.1e-3);
	double Vth(2.0e-2);
	double Vreset(0.0);
	double H(0.1e-3);
	double h(1);						// H = h * 0.1e-3	(incrément unité)
	double CE(1000);					//nombre de connections venant de neurones excitatory
	double CI(250);						//nombre de connections venant de neurones inhibitory
	
	int nombreIntervalle(1000);			//variables initialisees par moi
	double a(0.2e-3);
	double b(0.8e-3);
	double V0(0.0);
	double Iext(1.01);
	int Nbr_Neuron(12500);				//nombre de neurons
	
	vector<Neuron>neurons(Nbr_Neuron);	// /!\ comment initialiser 12500 neurones ? L'usage d'un vecteur...
	Neuron N(R,0.0,Tau,V0,false);		//tstart = 0
	double globalClock(0);    			//pour obtenir le temps réel, il suffit de faire (globalClock * 0.1e-3)
										//il faut créer les neurones inhibiteurs et excitateurs par hérédité            
	                          
	ofstream fichier("membrane_potential",ios::out);	//create a file in which is stocked tension
	fichier<<globalClock<<" "<<N.GetTension()<<endl;	//y mettre les tensions de tous les neurones
	double buffer[Nbr_Neuron][nombreIntervalle +1];		//création du buffer
	
	for(int i(1);i<nombreIntervalle;++i){										
		if (N.GetRefr() == true){
			buffer[globalClock + d][Nlié]+= J;};					//Nlié représente les n° de neurones liés au neurone considéré																	
		if((N.GetTime()<a) or (N.GetTime()>b)){						//Iext != 0 in [a,b]
			N.ProchaineTension(0,H,1,Vreset,Vth,CE,J);				//Background et refractory inclus dans la fonction update
			N.SetTension(N.GetTension() + buffer[N][globalClock]);} //ligne n° N représente le n° du neurone	
		else{
			N.ProchaineTension(Iext,H,1,Vreset,Vth,CE,J);
			N.SetTension(N.GetTension() + buffer[N][globalClock]);}
		globalClock += h;
																	//Et comment fait-on pour tracer des graphes ?
return 0 ;}
