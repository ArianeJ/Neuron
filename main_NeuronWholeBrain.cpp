#include <iostream>
#include "Neuron.cpp"
#include <random>
int main(){
	const double Tau(0.02);				//variables initialisees dans le papier															
	double R(2.0e10);
	double D(1.5e-3);
	double J(0.1e-3);
	double Vth(2.0e-2);
	double Vreset(0.0);
	double h(0.1e-3);
	double CE(1000);					//nombre de connections venant de neurones excitatory
	double CI(250);						//nombre de connections venant de neurones inhibitory
	
	int nombreIntervalle(1000);			//variables initialisees par moi
	double a(0.2e-3);
	double b(0.8e-3);
	double V0(0.0);
	double Iext(1.01);
	
	poisson.gen(Vth*CE*h*J);
	Neuron N1(R,0.0,Tau,V0,false);		//tstart = 0
	Neuron N2(R,0.0,Tau,V0,false);
	double globalClock(0);    
	double resultat[3][nombreIntervalle +1];	//n fields mean n+1 fences
	resultat[0][0]=globalClock;					//tension and time in a table
	resultat[1][0]=N1.GetTension();
	resultat[2][0]=N2.GetTension();              
	                          
	ofstream fichier("membrane_potential",ios::out);		//create a file in which is stocked tension
	fichier<<globalClock<<" "<<N1.GetTension()<<" "<<N2.GetTension()<<endl;
	int T1(1), T2(1);										//valeurs arbitraires pour éviter que les premiers if soient true  => a mettre dans le update
	for(int i(1);i<nombreIntervalle;++i){
		if (N1.GetTime() == T1){
			N1.SetTension(N1.GetTension() + J);};
		if (N2.GetTime() == T2){
			N2.SetTension(N2.GetTension() + J);};										
		if (N1.GetRefr() == true){
			T1 += globalClock + D;};										
		if (N2.GetRefr() == true){
			T2 += globalClock +D;};												
		if((N1.GetTime()<a) or (N1.GetTime()>b)){			//Iext != 0 in [a,b]
			N1.ProchaineTension(0,h,1,Vreset,Vth);}			//INCLURE GENERATION DE POISSON DANS UPDATE
		else{
			N1.ProchaineTension(Iext,h,1,Vreset,Vth);}
		if((N2.GetTime()<a) or (N2.GetTime()>b)){   		//Iext != 0 in [a,b]
			N2.ProchaineTension(0,h,1,Vreset,Vth);}
		else{
			N2.ProchaineTension(Iext,h,1,Vreset,Vth);}
		globalClock += h;
		fichier<<globalClock<<" "<<N1.GetTension()<<" "<<N2.GetTension()<<endl;
		resultat[0][i]=globalClock;                                              
		resultat[1][i]=N1.GetTension();
		resultat[2][i]=N2.GetTension();};
	cout<<resultat<<endl;
return 0 ;}
