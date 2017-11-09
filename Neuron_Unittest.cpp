#include "gtest/gtest.h"
#include "Neuron.hpp"
#include <random>
#include <vector>
#include <cstdlib>
#include <fstream>
						
int const d(15);						
double const Vth(2.0e-2);
double const Vreset(0.0);
double const H(0.1e-3);
int const h(1);						
int const CE(4);					
int const CI(1);					
double const JI(0.5e-3);				
double const JE(0.1e-3);				
int const tref(20);					
	
int const nombreIntervalle(10);		
double const Iext(0);
int const Nbr_Neuron(10);			
	
										
	
vector<Neuron>neurons;	
neurons.reserve(Nbr_Neuron);
for(int i(0);i<8;++i){
	neurons.push_back(Neuron(JE));};	
for(int i(8);i<10;++i){
	neurons.push_back(Neuron(JI));};	
		
TEST (Neuron construction, Jtest){	///are the exctitator and the inhibitor neurons in the good place in the neuron ?
	EXPECT_EQ(neurons[7].GetJ(),JE);
	EXPECT_EQ(neurons[7].GetJ(),JI);
	}
	
vector<vector<int> >connection(Nbr_Neuron, vector<int>(CE+CI));		
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int>UniformDistribE(0,7);
uniform_int_distribution<int>UniformDistribJ(8,9);
for(int i(0);i<Nbr_Neuron;++i){
	for(int j(0);j<5;++j){
		connection[i][j]=UniformDistribE(gen);	
	};										
	connection[i][5]=UniformDistribJ(gen);
};
	
TEST (Distribution, Connection){	///are the chosen neurons for connection in the good range ?
	EXPECT_LT(connection[0][4],8);
	EXPECT_GT(connection[0][5],7);
	}
	
TEST (ProchaineTension, Expect refract){	///does the update function what it is supposed to to a spiking neuron ?
	Neuron N(JE)
	N.SetTension(Vth);
	N.ProchaineTension(0.0,H,1,Vreset,Vth);
	EXPECT_EQ(N.GetTension(),Vreset);
	EXPECT_EQ(N.GetRefr(),true);}
		
int main() {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
