#include "Neuron.cpp"


class HNN
{
public:
 vector<Neuron> Neurons;
 vector<vector<double>> W;
 
 HNN (){};
 HNN (int n_neurons);

 
 void Set_State(int*);
 void Set_State(vector<int>);
 void Print_State(); 
 double Energy();

 void Update_Sinchronous(); //aggiorna ogni neurone contemporaneamente: calcola tutti gli input poi li invia ai neuroni che aggiornano coerentemente l'output.

 void Update_Neuron(int);   //calcola l'input del neurone che riceve per argomento, poi lo aggiorna
 void Update_Asinchronous(int); //esegue per un numero di volte pari al suo argomento la seguente operazione: sceglie un neurone a caso, lo aggiorna.
 
void Train(vector<vector<int>>);

};
