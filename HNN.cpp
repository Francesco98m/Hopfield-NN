#include "HNN.h"

 HNN::HNN (int n_neurons)
 {
  Neurons.resize(n_neurons);
  W.resize(n_neurons);
  for(int i=0; i<n_neurons; i++)
    {
        W[i].resize(n_neurons);
        int r=rand()%100;
        if(r<49) Neurons[i].output =-1;
        else Neurons[i].output=1;
        for(int j=0; j<W[i].size(); j++)
        {
            W[i][j]=((double)(rand()%100)/100.);
        }
    }
 } 



void HNN::Set_State(int* v)
{
    for(int i=0; i< Neurons.size();++i) Neurons[i].output = v[i];
}

void HNN::Set_State(vector<int> v)
{
    for(int i=0; i< Neurons.size();++i) Neurons[i].output = v[i];
}


void HNN::Print_State()
{
    for(int i=0; i<Neurons.size(); i++)
    {
        cout<<Neurons[i].output<<"\t";
    }
    cout<<endl;
}


void HNN::Update_Sinchronous()
{
 double* in= new double[Neurons.size()];
 for(int i=0; i<Neurons.size(); i++)
 {
  in[i]=0;
  for(int j=0; j<Neurons.size(); j++)
  {
    in[i] += W[i][j]*Neurons[j].output;
  }
 }

 for (int i =0; i< Neurons.size();++i) Neurons[i].Update(in[i]); 
}




void HNN::Update_Neuron(int n)
{
 double input = 0;
 for (int j=0;j<Neurons.size();++j)
 {
  input += (W[n][j]*Neurons[j].output);
 }
 Neurons[n].Update(input);
}




void HNN::Update_Asinchronous(int h =1)
{
 double input = 0;
 for (int i =0; i<h;++i)
 {
  int n = rand()%Neurons.size();
  Update_Neuron(n);
  for (int j=0;j<Neurons.size();++j)
  {
   input += (W[n][j]*Neurons[j].output);
  }
  Neurons[n].Update(input);
 }
} 


double HNN::Energy()
{
    double E=0;
    for(int i=0; i<W.size(); i++)
    {
        for (int j=0; j < W[i].size(); j++)
        {
            E += (W[i][j]*Neurons[i].output*Neurons[j].output);
        }
    }
    return -(E)/2;
}


void HNN::Train(vector<vector<int>> set)
{
    double p=0;
    int size=set.size();
    for(int i=0; i<W.size(); i++)
    {
        for(int j=0; j<W.size(); j++)
        {
            for(int a=0; a<size; a++)
            {   
                p+=(set[a][i]*set[a][j]);
            }
            p /= size;
            W[i][j]=p;
        }
    }
}






