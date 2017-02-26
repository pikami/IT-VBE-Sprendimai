//1. Mainai
#include <iostream>
#include <fstream>
using namespace std;

int getMoneys(int type[],int tQ,int wallet[]){  // Funkcija kuri skaičiuoja, kokią sumą pinigų keičia studentas
    int total = 0;
    for(int i=0;i<tQ;i++)
        total += type[i]*wallet[i];
    return total;
}
void changeCurrency(int oldT[],int oldN,int newT[],int newN, int wallet[]){ // Funkcija keicianti valiuta
    int moneys = getMoneys(oldT,oldN,wallet);   // Kiek is viso keisime
    for(int i=0;i<50;i++)wallet[i]=0;
    for(int i=0;i<newN;i++){
        while(moneys>=newT[i]){
            moneys-=newT[i];
            wallet[i]++;
        }
    }
}
int countMetal(int wallet[], int n){            // Funkcija suskaiciuojanti kiek is viso monetu gauta
    int q=0;
    for(int i=0;i<n;i++)
        q+=wallet[i];
    return q;
}

int main(){
    //
    int nG,nE; //Skirtingu nominalu kiekis
    //Nuskaitymas
    ifstream f("U1.txt");
    f>>nG;
    int gL[nG],gQ[50];  //Monetu tipai, studento monetos
    for(int i=0;i<nG;i++)
        f>>gL[i];
    for(int i=0;i<nG;i++)
        f>>gQ[i];
    f>>nE;
    int eL[nE],eQ[50];  //Monetu tipai, studento monetos
    for(int i=0;i<nE;i++)
        f>>eL[i];
    for(int i=0;i<nE;i++)
        f>>eQ[i];
    f.close();
    //Keiciame valiuta
    changeCurrency(gL,nG,eL,nE,gQ);
    changeCurrency(eL,nE,gL,nG,eQ);
    //Rasome i faila
    ofstream of("U1rez.txt");
    for(int i=0;i<nE;i++){
        of<<eL[i]<<" "<<gQ[i]<<endl;
    }
    of<<countMetal(gQ,nE)<<endl;
    for(int i=0;i<nG;i++){
        of<<gL[i]<<" "<<eQ[i]<<endl;
    }
    of<<countMetal(eQ,nG)<<endl;
    of.close();
    return 0;
}
