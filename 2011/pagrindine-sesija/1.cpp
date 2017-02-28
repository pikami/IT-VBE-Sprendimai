//1. Pirðtinës
#include <iostream>
#include <fstream>
using namespace std;

struct pirstine{
    int l;  // Lytis
    int r;  // ranka
    int d;  // Dydis
};

bool exists(pirstine a, pirstine P[], int n, int Kk[], int Kd[]){           // Funkcija surandanti pirstines tipa masyve
    for(int i=0;i<n;i++){
        if(P[i].l==a.l && P[i].d==a.d){
            if(a.r==1)Kk[i]++;
            else Kd[i]++;
            return true;
        }
    }
    return false;
}

void read(int&n, int&q, pirstine P[], int Kd[], int Kk[]){                  // Funkcija skaitanti duomenis is failo
    ifstream f("U1.txt");
    f>>n;
    for(int i=0;i<n;i++){Kd[i]=0;Kk[i]=0;}
    pirstine cur;     // Dabartine pirstine
    for(int i=0;i<n;i++){
        f>>cur.l>>cur.r>>cur.d;
        if(!exists(cur,P,q,Kk,Kd)){
            P[q] = cur;
            q++;
            exists(cur,P,q,Kk,Kd);
        }
    }
    f.close();
}

void quantity(int&vq, int&mq, int n, int Kk[], int Kd[], pirstine P[]){     // Funkcija suskaiciuojanti poru kieki
    for(int i=0;i<n;i++){
        if(P[i].l==3) vq+=min(Kk[i],Kd[i]);
        else  mq+=min(Kk[i],Kd[i]);
    }
}

void remaining(int&vq, int&mq, int n, int Kk[], int Kd[], pirstine P[]){    // Funkcija randanti atliekamu pirstiniu kieki
    for(int i=0;i<n;i++){
        if(P[i].l==3) vq+=max(Kk[i],Kd[i])-min(Kk[i],Kd[i]);
        else  mq+=max(Kk[i],Kd[i])-min(Kk[i],Kd[i]);
    }
}

void write(int mq,int vq,int mr,int vr){                                    // Funkcija isvedanti rezultatus i faila
    ofstream f("U1rez.txt");
    f<<mq<<"\n"<<vq<<"\n"<<mr<<"\n"<<vr;
    f.close();
}

int main(){
    // Skaitome
    int n,q=0;
    pirstine P[100];      // Pirstiniu rusiu masyvas
    int Kd[100],Kk[100];  // Pirstiniu kiekis
    read(n,q,P,Kd,Kk);
    // Skaiciuojame poras
    int vq=0,mq=0;
    quantity(vq,mq,n,Kk,Kd,P);
    // skaiciuojame atliekas
    int vr=0,mr=0;
    remaining(vr,mr,n,Kk,Kd,P);
    // Isvedame
    write(mq,vq,mr,vr);
}
