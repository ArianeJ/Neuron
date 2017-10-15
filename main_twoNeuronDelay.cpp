#include<iostream>
#include "Neuron.cpp"
int main(double tfin,int nombre_intervalle,double a,double b,double R,double V0,double Iext,double tau,double Vreset,double Vth,double J,double D){
	Neuron N1(R,0,tau,V0,false);												//tstart = 0
	Neuron N2(R,0,tau,V0,false);
	int h;
	h=(tfin)/nombre_intervalle; 												//h is the time between two simulations
	double GlobalClock(0);
	double Delay;     
	double resultat[3][nombre_intervalle +1];									//n fields mean n+1 fences
	resultat[0][0]=GlobalClock;													//tension and time in a table
	resultat[1][0]=N1.tension;
	resultat[2][0]=N2.tension;                                        
	ofstream fichier("membrane_potential",ios::out);                            //create a file in which is stocked tension
	fichier<<GlobalClock<<" "<<N1.tension<<" "<<N2.tension<<endl;
	int T1(1), T2(1)															//valeurs arbitraires pour éviter que les premiers if soient true
	for(i(1);i<=nombre_intervalle + 1;++i){
		if (N1.temps = T1){
			N1.tension += J};
		if (N2.temps = T2){
			N2.tension += J};										
		if (N1.refractory == true){
			T1 += GlobalClock + D;};										
		if (N2.refractory == true){
			T2 += GlobalClock +D;};												
		if((Neu.temps<a) or (Neu.temps>b)){                                     //Iext != 0 in [a,b]
			Neu.prochaine_tension(0,h,1,Vreset,Vth);}
		else{
			Neu.prochaine_tension(Iext,h,1,Vreset,Vth);}
		GlobalClock += h
		fichier<<GlobalClock<<" "<<N1.tension<<" "<<N2.tension<<endl;
		resultat[0][i]=GlobalClock;                                              
		resultat[1][i]=N1.tension;
		resultat[2][i]=N2.tension;};
	cout<<resultat<<endl;
	return 0 ;}
