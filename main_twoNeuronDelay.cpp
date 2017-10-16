#include<iostream>
#include "Neuron.cpp"
int main(){
	const double Tau(0.02);														//variables initialisees dans le papier															
	double R(2.0e10);
	double D(1.5e-3);
	double J(0.1e-3);
	double Vth(2.0e-2);
	double Vreset(0.0);
	double h(0.1e-3);
	
	int nombreIntervalle(1000);													//variables initialisees par moi
	double tFin(nombreIntervalle * h);
	double a(0.2e-3);
	double b(0.8e-3);
	double V0(0.0);
	double Iext(1.01);
	
	Neuron N1(R,0.0,Tau,V0,false);												//tstart = 0
	Neuron N2(R,0.0,Tau,V0,false);
	double globalClock(0);
	double Delay;     
	double resultat[3][nombreIntervalle +1];									//n fields mean n+1 fences
	resultat[0][0]=globalClock;													//tension and time in a table
	resultat[1][0]=N1.tension;
	resultat[2][0]=N2.tension;              
	                          
	ofstream fichier("membrane_potential",ios::out);                            //create a file in which is stocked tension
	fichier<<globalClock<<" "<<N1.tension<<" "<<N2.tension<<endl;
	int T1(1), T2(1);															//valeurs arbitraires pour éviter que les premiers if soient true  => a mettre dans le update
	for(int i(1);i<nombreIntervalle;++i){
		if (N1.temps = T1){
			N1.tension += J};
		if (N2.temps = T2){
			N2.tension += J};										
		if (N1.refractory == true){
			T1 += globalClock + D;};										
		if (N2.refractory == true){
			T2 += globalClock +D;};												
		if((Neu.temps<a) or (Neu.temps>b)){                                     //Iext != 0 in [a,b]
			Neu.prochaine_tension(0,h,1,Vreset,Vth);}
		else{
			Neu.prochaine_tension(Iext,h,1,Vreset,Vth);}
		globalClock += h
		fichier<<globalClock<<" "<<N1.tension<<" "<<N2.tension<<endl;
		resultat[0][i]=globalClock;                                              
		resultat[1][i]=N1.tension;
		resultat[2][i]=N2.tension;};
	cout<<resultat<<endl;
return 0 ;}
