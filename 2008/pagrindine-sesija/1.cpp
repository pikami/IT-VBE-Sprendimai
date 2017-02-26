//1. Tyrimai
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
const int _limit = 15;

int getBusID(int M[],int n, int id){            // Funkcija frazinanti autobuso index pagal id
    for(int i=0;i<n;i++){
        if(M[i]==id)return i;
    }
    return -1;                                  // Graziname -1 jei neradome
}

void sortBus(int M[], int K[], int L[], int q){ // Funkcija rikuojanti marsrutus
    for(int i=0;i<q;i++){
        for(int o=i;o<q;o++){
            if(M[o]<M[i]){
                swap(M[i],M[o]);
                swap(K[i],K[o]);
                swap(L[i],L[o]);
            }
        }
    }
}

int getMostUsed(int K[],int L[], int q){        // Funkcija gaunanti populeriausia marsruta
    int maxID = 0;
    int N[_limit] = {0};
    //Suformuoti
    for(int i=0;i<q;i++){
        if(K[i]<abs(L[i]))
            N[i]=L[i];
        else N[i]=K[i];
    }
    //Ieskoti
    for(int i=1;i<q;i++){
        if(N[i]>N[maxID])maxID=i;
    }
    return maxID;
}

void read(int M[], int K[], int L[], int&q){    // Funkcija skaitanti duomenis is failo
    int n,nr,tmp;
    ifstream f("U1.txt");
    f>>n;
    for(int i=0;i<n;i++){
        f>>nr;
        int id=getBusID(M,n,nr);
        if(id!=-1){
            f>>tmp;
            if(tmp<0)
                L[id]+=tmp;
            else K[id]+=tmp;
        } else {
            M[q]=nr;
            f>>tmp;
            if(tmp<0)
                L[q]+=tmp;
            else K[q]+=tmp;
            q++;
        }
    }
    f.close();
}

int main(){
    int M[_limit]={0},K[_limit]={0}, L[_limit]={0},q=0; //marsruto nr, ilipusieji keleiviai, islipusieji keleiviai, marsrutu kiekis
    read(M,K,L,q);
    sortBus(M,K,L,q);
    ofstream f("U1rez.txt");
    //Naudotas
    for(int i=0;i<q;i++){
        f<<setw(4)<<M[i]<<" ";
    }
    f<<setw(4)<<endl;
    //Kiek keleiviu vezta
    for(int i=0;i<q;i++){
        if(K[i]<abs(L[i]))
            f<<setw(4)<<L[i]<<" ";
        else f<<setw(4)<<K[i]<<" ";
    }
    f<<setw(4)<<endl;
    //Kiek islipo
    for(int i=0;i<q;i++){
        f<<setw(4)<<L[i]<<" ";
    }
    f<<setw(4)<<endl<<M[getMostUsed(K,L,q)];
    f.close();
    return 0;
}

