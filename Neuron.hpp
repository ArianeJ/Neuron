#ifndef NEURON
#define NEURON
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Neuron {
	private:
		const double resistance;
		double temps;
		const double tau;
		double tension;
		bool spike;
		bool refractory;
		const double J;				//cet attribut va différencier neurone excitateur et neurone inhibiteur
	public:
	    double GetTension() const;
	    double GetTime() const;
	    bool GetIfSpike() const;
	    bool GetRefr() const;
	    void SetTension(double V);
	    void SetRefr(bool refr);                                                      
	    void ProchaineTension(double Iext, double h, int n,double Vreset,double Vth);
	    Neuron(double J);
};

#endif
