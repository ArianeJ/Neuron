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
	    double GetTime() const;
	    bool GetRefr() const;
	    void SetTension(double V);                                                         
	    void prochaine_tension(double Iext, double h, int n,double Vreset,double Vth);
	    int nombre_pic(double tini,double tfin,double Vth,int n,double h,double Iext,double Vreset);
	    Neuron(double R, double t, double tau, double V, bool refr)
		: resistance(R),temps(t),tau(tau),tension(V),refractory(refr)
		{}
};
