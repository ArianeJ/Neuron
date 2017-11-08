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
		vector<double> buffer
	public:
	    double GetTension() const;
	    double GetTime() const;
	    double GetJ() const;
		void CopyBuffer(unsigned int n);
	    void SetBuffer(unsigned int n,double a);
	    bool GetRefr() const;
	    void SetTension(double V);
	    void SetRefr(bool refr);                                                      
	    bool ProchaineTension(double Iext, double h, int n,double Vreset,double Vth);
	    Neuron(double J);
};

#endif
