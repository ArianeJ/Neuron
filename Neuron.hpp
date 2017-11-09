#ifndef NEURON
#define NEURON
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Neuron {
	private:
		const double resistance;	///these 4 attribut are constant caracteristic of the neuron
		const double tau;
		const double J;
		double temps;				///these 2 attribut will change throught experiences
		double tension;
		bool spike;					///these 2 answer the questions : is the neuron spiking ? Is it refractory ?
		bool refractory;
		vector<double> buffer;		///the vector will serve to register tension the neuron has to get
	public:
	    double GetTension() const;	///getter
	    double GetTime() const;
	    double GetJ() const;
	    bool GetRefr() const;
	    void SetTension(double V);	///setter
	    void SetRefr(bool refr);
		void CopyBuffer(unsigned int n);	///method linked to the manipulation of the buffer
	    void SetBuffer(unsigned int n,double a);
	    bool ProchaineTension(double Iext, double h, int n,double Vreset,double Vth);	///update function
	    Neuron(double J);			///constructor
};

#endif
