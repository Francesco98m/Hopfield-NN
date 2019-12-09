#include "HNN.cpp"


int  main()
{
    srand(time(NULL));
    
    int n;
    cout<<"Creo una rete di Hopfiel. Quanti neuroni? \t", cin>>n;
    HNN Net(n);

    cout<<"Imposto i pesi della rete. Quanti elementi nel set?", cin>>n;
    vector<vector<int>> training_set;
    training_set.resize(n);
    for(int i = 0; i<training_set.size(); ++i) 
    { 
     training_set[i].resize(Net.Neurons.size());
     cout<<"Inserire il "<<i+1<<"° elemento (un numero binario alla volta):\n";
     for(int j=0; j< training_set[i].size();++j)   cin>>training_set[i][j];
    }
    
    cout<<"Energy of the system before training: E="<<Net.Energy()<<endl;
    Net.Train(training_set);
    cout<<"Energy of the system after training: E="<<Net.Energy()<<endl;

    while(true)
    {
        cout<<"Scegliere azione: \n (0) Quit \n (1) Print State \n (2) Update Sinchronous \n (3) Update Asinchronous \n (4) Change state\n";
        cin>>n;
        if (n==0) break;
        else if (n==1) Net.Print_State();
        else if (n==2) Net.Update_Sinchronous();
        else if (n==3) 
        {
         cout<<"Quanti step? ", cin>>n;
         Net.Update_Asinchronous(n);
        }
        else if(n==4)
        {
            vector<int> lk;
            lk.resize(Net.Neurons.size());
            cout<<"Insert vector (one element a time):\n";
            for (int i=0; i< lk.size();++i) cin>>lk[i];
            Net.Set_State (lk);
        }
    }
    
}
