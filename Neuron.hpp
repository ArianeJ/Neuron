#ifndef NEURON
#define NEURON
#include <iostream>
#include <vector>
#include <fstream>
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
	    void ProchaineTension(double Iext, double h, int n,double Vreset,double Vth,double CE,double J);
	    int NombrePic(double tini,double tfin,double Vth,int n,double h,double Iext,double Vreset,double CE,double J);
	    Neuron(double R, double t, double tau, double V, bool refr);
};

#endif
