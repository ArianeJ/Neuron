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
	public:
	    double GetTension() const;                                                          //the pgrm doesn't work from that line
		void prochaine_tension(double Iext, double h, int n,double Vreset,double Vth);
		int nombre_pic(double tini,double tfin,double Vth,int n,double h,double Iext,double Vreset);
};
