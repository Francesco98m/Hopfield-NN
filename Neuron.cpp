#include "Neuron.h"

Neuron::Neuron()
{
 input = output=0; 
}




void Neuron::Update(double in)
{
 input = in;
 if(in>=0) output =1;
 else output=-1;
}
