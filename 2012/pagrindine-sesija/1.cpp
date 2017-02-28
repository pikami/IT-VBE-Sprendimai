//1. Krepðinis
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void readData(int&n,int NR[12], int T[12][41]){             // Funkcija skaitanti duomenis is failo
    ifstream f("U1.txt");
    f>>n;
    for(int i=0;i<n;i++){
        f>>NR[i]>>T[i][0];
        for(int o=1;o<T[i][0]+1;o++)
            f>>T[i][o];
    }
    f.close();
}
void getFirst5(int n,int NR[12], int T[12][41], int S[5]){  // Funkcija gaunanti startini penketuka
    int I=0;
    for(int i=0;i<n;i++){
        if(T[i][1]>0){
            S[I]=NR[i];
            I++;
            if(I==5)break;
        }
    }
}

void sortM(int M[], int n){                                 // Funkcija surikiuojanti sportininkus
    vector<int> Mvector (M, M+n);
    sort (Mvector.begin(), Mvector.begin()+n);
    for(int i=0;i<n;i++)
        M[i]=Mvector[i];
}

void total(int n,int T[12][41],int Total[12][2]){           // Funkcija skaiciuojanti kiek laiko zaidejas praleido
    Total[12][2] = {0};
    for(int i=0;i<n;i++)
        for(int o=1;o<T[i][0]+1;o++)
            if(T[i][o]>0)Total[i][0]+=T[i][o];
            else Total[i][1]+=abs(T[i][o]);
}

int maxI(int n, int Total[12][2],int o){                    // Funkcija randanti kas ilgiausiai isbuvo ant suoliuko/aiksteje
    int I=0;
    for(int i=1;i<n;i++){
        if(Total[i][o]>Total[I][o])I=i;
    }
    return I;
}

int main(){
    int n;            // Krepsininku kiekis
    int NR[12];       // Krepsininku nr
    int T[12][41];    // Krepsininku laikai
    readData(n,NR,T); // Skaitome duomenis
    // Apskaiciavimai
    int S[5];                   // Startinis penketukas
    getFirst5(n,NR,T,S);        // Gauname startini penketuka
    sortM(S,5);                 // Surikiuojame startini penketa
    int Total[12][2]={0};       // [Zaidejas][laikas(0-aiksteje,1-ant suoliukp)]
    total(n,T,Total);           // Apskaiciuojame
    int maxA=maxI(n,Total,0),   // Kas ilgiausiai isbuvo aiksteje
        maxS=maxI(n,Total,1);   // Kas ilgiausiai isbuvo ant suoliuko
    // Isvedame rezultatus
    ofstream fo("U1rez.txt");
    for(int i=0;i<5;i++)
        fo<<S[i]<<" ";
    fo<<"\n"
        <<NR[maxA]<<" "<<Total[maxA][0]<<"\n"
        <<NR[maxS]<<" "<<Total[maxS][1];
    fo.close();
    return 0;
}
