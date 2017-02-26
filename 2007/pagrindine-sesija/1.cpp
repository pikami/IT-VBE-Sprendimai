//1. Grybai
#include <iostream>
#include <fstream>
using namespace std;

void readFile(int K[31][3]){ //Failo nuskaitymo funkcija
    int d=0,n=0;
    int TMP[3];
    ifstream f("U1.txt");
    f>>n;
    for(int i=0;i<n;i++){
        f>>d;
        f>>TMP[0]>>TMP[1]>>TMP[2];
        K[d-1][0]+=TMP[0];
        K[d-1][1]+=TMP[1];
        K[d-1][2]+=TMP[2];
    }
    f.close();
}
int getBestDay(int K[31][3]){ //Funkcija gauti dienos kurioja buvo daugiausiai grybu numeri
    int _max=0;
    for(int i=0;i<31;i++)
        if(K[i][0]+K[i][1]+K[i][2]>K[_max][0]+K[_max][1]+K[_max][2])
            _max=i;
    return _max;
}
void printResults(int K[31][3]){ //Funkcija atspausdinanti rezultatus
    ofstream f("U1rez.txt");
    for(int i=0;i<31;i++)
        if(K[i][0]!=0 || K[i][1]!=0 || K[i][2]!=0)
            f<<i+1<<" "<<K[i][0]<<" "<<K[i][1]<<" "<<K[i][2]<<endl;
    int iB = getBestDay(K);
    f<<iB+1<<" "<<K[iB][0]+K[iB][1]+K[iB][2];
    f.close();
}

int main()
{
    int K[31][3] = {0}; // Diena, Grybo rusis
    readFile(K);        // Skaitome duomenis is failo
    printResults(K);    // Spausdiname rezultatus i faila
    return 0;
}
