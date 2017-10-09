#include<iostream>
int main(double tfin;int nombre_intervalle;double a;double b;double R;double C;double V0;double Iext;double R;double tau; Vreset, Vth){
	Neuron Neu(R,0,tau,V0);
	int h;
	h=(tfin)/nombre_intervalle;                                                       //h is the time between two simulations
	double resultat[2][nombre_intervalle +1];                                         //n fields mean n+1 fences
	ofstream fichier("membrane_potential",ios::out);                                  //create a file in which is stocked tension
	for(i(0);i<=nombre_intervalle + 1;++i){
		if((Neu.temps<a) or (Neu.temps>b)){                                       	  //Iext != 0 in [a,b]
			Neu.prochaine_tension(0,h,1,Vreset,Vth);}
		else{
			Neu.prochaine_tension(Iext,h,1,Vreset,Vth);}
		fichier<<Neu.tension<<" ";
		resultat[0][i]=Neu.temps;                                                	  //tension and time in a table
		resultat[1][i]=Neu.tension;};
	
	cout<<resultat<<endl;
	return 0 ;}
