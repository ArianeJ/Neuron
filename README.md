# Neuron

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Neuron{
	private:
		double resistance;
		double temps;
		double tau;
		double tension;
	public:
	  double GetTension()const{       
			return tension;};                                     //the pgrm doesn't work from that line
		void prochaine_tension(double Iext; double h; int n;double Vreset;double Vth){
			for (i(1);i<=n;++i){				      //to make an update of the Neuron features
				if (tension >=Vth){                           //if the tension is to high, tension = Vreset
					tension = Vreset;};
				else{
					tension=tension*exp(-h/tau)+Iext*resistance*(1-e(-h/tau));};                
									      // equa diff solution
				temps= temps + h ;};};
		int nombre_pic(double tini;double tfin;double Vth;int n;double tini;double tfin;double h;double Iext;double Vreset){
			int pic(0);                                           //pike are counted and stocked with time
			double temps_pic [2][n];
			for (i(1);i<=n;++i){
				prochaine_tension(Iext,h,1, Vreset,Vth);                                    
				temps_pic[0][i-1]=temps;
				if (tension >=Vth){
					pic+=1;
					temps_pic[1][i-1]=1;};                 //in the table, "1" means pike,  "0" means none
				else {
					temps_pic[1][i-1]=0;};
				};
			cout<<temps_pic<<endl;
			return pic;};
};

int main(double tfin;int nombre_intervalle;double a;double b;double R;double C;double V0;double Iext;double R;double tau; Vreset, Vth){
	Neuron Neu(R,0,tau,V0);
	int h;
	h=(tfin)/nombre_intervalle;                                              //h is the time between two simulations
	double resultat[2][nombre_intervalle +1];                                //n fields mean n+1 fences
	ofstream fichier("membrane_potential",ios::out);                         //create a file in which is stocked tension
	for(i(0);i<=nombre_intervalle + 1;++i){
		if((Neu.temps<a) or (Neu.temps>b)){                              //Iext != 0 in [a,b]
			Neu.prochaine_tension(0,h,1,Vreset,Vth);}
		else{
			Neu.prochaine_tension(Iext,h,1,Vreset,Vth);}
		fichier<<Neu.tension<<" ";
		resultat[0][i]=Neu.temps;                                        //tension and time in a table
		resultat[1][i]=Neu.tension;};
	
	cout<<resultat<<endl;
	return 0 ;}
	
void twoNeuron(double Vth, double J){
	Neuron n;
	Neuron p;
	if (n.tension >= Vth){
		p.tension += J;};
	};
