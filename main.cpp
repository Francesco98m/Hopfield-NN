#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
double energy(vector<vector<double>> w, vector<short int> n)
{
    double E=0;
    for(int i=0; i<w.size(); i++)
    {
        for (size_t j = 0; j < w[i].size(); j++)
        {
            E+=(w[i][j]*n[i]*n[j]);
        }
    }
    return -(E)/2;
}

void input_comp(vector<vector<double>> w, vector<short int>& n)
{
    double in=0;
    for(int i=0; i<n.size(); i++)
    {
        for(int j=0; j<n.size(); j++)
        {
            in+=w[i][j]*n[j];
        }
        if(in>=0)
        {
            n[i]=1;
        }
        else
        {
            n[i]=-1;
        } 
    }
}

void input_maker(vector<vector<short int>>& set, int training_size, int n)
{
    set.resize(training_size);
    for(int i=0; i<set.size(); i++)
    {
        set[i].resize(n);
        for(int j=0; j<set[i].size(); j++)
        {
            int a=rand()%100;
            if(j==0 ||j==1)
            {
                set[i][j]=1;
            }
            else
            {
                if(a<49) set[i][j]=-1;
                else set[i][j]=1;
            }
        }
    }
}

void print_status(vector<short int> n)
{
    for(int i=0; i<n.size(); i++)
    {
        cout<<n[i]<<"\t";
    }
    cout<<endl;
}

void trainer(vector<vector<short int>> set, vector<vector<double>>& w)
{
    double p=0;
    int size=set.size();
    for(int i=0; i<w.size(); i++)
    {
        for(int j=0; j<w.size(); j++)
        {
            for(int a=0; a<size; a++)
            {   
                p+=(set[a][i]*set[a][j]);
            }
            p=p/size;
            w[i][j]=p;
        }
    }
}

bool input(vector<short int> in, vector<short int>& n)
{
    if(in.size()==n.size())
    {
        n=in;
        return true;
    } 
    else return false;
}
int  main()
{
    srand(time(NULL));
    int n=5;
    bool con,pon;
    vector<short int> neurons;
    vector<short int> lk;
    lk.resize(n);
    vector<vector<short int>> training_set;
    vector<vector<double>> weights;
    neurons.resize(n);
    weights.resize(n);
    for(int i=0; i<n; i++)
    {
        weights[i].resize(n);
        int r=rand()%100;
        if(r<49) neurons[i]=-1;
        else neurons[i]=1;
        for(int j=0; j<weights[i].size(); j++)
        {
            weights[i][j]=((double)(rand()%100)/100.);
        }
    }
    cout<<"Energy of the system before training: E="<<energy(weights,neurons)<<endl;
    input_maker(training_set,10,5);
    trainer(training_set,weights);
    cout<<"Energy of the system before training: E="<<energy(weights,neurons)<<endl;
    while(true)
    {
        input_comp(weights,neurons);
        print_status(neurons);
        cout<<"Continue?\n";
        cin>>con;
        if(con) continue;
        cout<<"Change state?\n";
        cin>>pon;
        if(pon)
        {
            cout<<"Insert vector:\n";
            cin>>lk[0];
            cin>>lk[1];
            cin>>lk[2];
            cin>>lk[3];
            cin>>lk[4];
            input(lk,neurons);
            print_status(neurons);
            continue;
        }
        break;
    }
    
}