//1. Ðachmatø turnyras
#include <iostream>
#include <fstream>
using namespace std;

int countFull(int Full[], int Pieces[]){    // Funkcija apskaiciuojanti kiek komplektu gaunasi
    int q=Pieces[0]/Full[0];
    for(int i=1;i<6;i++){
        if(Pieces[i]/Full[i]<q)q=Pieces[i]/Full[i];
    }
    return q;
}

int main(){
    int Full[6] = {8,2,2,2,1,1},
        Pieces[6] = {0,0,0,0,0,0},
        n,tmp;
    // Skaitome duomenis
    ifstream f("U1.txt");
    f>>n;
    for(int i=0;i<n;i++){
        for(int o=0;o<6;o++){
            f>>tmp;
            Pieces[o]+=tmp;
        }
    }
    f.close();
    // Isvesti rezultatus
    ofstream out("U1rez.txt");
    out<<countFull(Full,Pieces);
    out.close();
    return 0;
}
