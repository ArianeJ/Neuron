#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Neuron {
	private:
		double resistance;
		double temps;
		double tau;
		double tension;
		bool refractory;
	public:
	    double GetTension() const;                                                         
		void prochaine_tension(double Iext, double h, int n,double Vreset,double Vth);
		int nombre_pic(double tini,double tfin,double Vth,int n,double h,double Iext,double Vreset);
};
