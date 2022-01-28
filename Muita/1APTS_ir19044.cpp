#include <iostream>
#include <fstream>
using namespace std;
int P_size,N_size; ///muitnieku skaits - kaudzes max izmers
int P_length=0,N_length=0; /// kaudzes esosais izmers
int start_P=0,start_N=0; ///norade uz gaidisanas rindas sakumu
int finish_P=0,finish_N=0; ///norade uz gaidisanas rindas beigam
int MM = 149999; ///Gaidisanas rindas garums
bool free_P[100],free_N[100]; ///brivas kases
int pre_P[100],pre_N[100]; ///Ieprieksejais laiks muitniekiem
int worktime_P[100],worktime_N[100];
int COUNT_P=0,COUNT_N=0; ///cilveku skaits rindaa

struct heap{ ///heap muitniekiem
    unsigned int time; ///exit time for person
    int cashier; ///Kases ID
    char tips; ///P vai N
    int id; ///Cilveka numurs
};

struct rinda{ ///Gaidisanas rindai
    int id;
    char tips;
};
rinda P[150000];
rinda N[150000];
heap H[200];

bool change(int &a, int b){ ///Mainam vietam kartosanai (Heap Sort)
    heap T;
    int x,y;
    x = H[a].cashier;
    y = H[b].cashier;
    if(H[a].tips=='N') x+=100;
    if(H[b].tips=='N') y+=100;
    if(H[a].time>H[b].time || ((H[a].time==H[b].time) && x>y)){
        T=H[a];
        H[a] = H[b];
        H[b] = T;
        a = b;
        return true;
    } else return false;
}

void up(){ ///Celam augsaa elementus heapaa
    int tmp,v;
    heap T;
    tmp=N_length+P_length+1;
    v = tmp/2;
    while(change(v,tmp) && tmp>1){
        tmp=tmp/2;
        v= tmp/2;
    }
}

void down(){
    int pos=1,tmp,x,y; ///position which can be drowned
    bool flag=true;
    heap T;
    tmp=P_length+N_length;
    if(tmp>1){
        while(flag){  /// Kamer kaudze nav izlabota
            flag=false;
            if(tmp>=2*pos+1){ ///ir 2 berni
                if (H[2*pos].time>H[pos].time && H[2*pos+1].time>H[pos].time) break; ///berni stingri lielaki
                else if(H[2*pos].time<H[2*pos+1].time){ ///kreisais berns mazaks

                    if(change(pos,2*pos)) flag=true;

                } else if(H[2*pos].time>H[2*pos+1].time){ /// labais berns mazaks

                    if(change(pos,2*pos+1)) flag=true;

                } else  { ///laiks abiem berniem vienads,

                    x = H[2*pos].cashier;
                    y = H[2*pos+1].cashier;
                    if(H[2*pos].tips=='N') x+=100;
                    if(H[2*pos+1].tips=='N') y+=100;

                    if(x>y){
                        if(change(pos,2*pos+1)) flag=true;
                    }
                    if(x<y){
                        if(change(pos,2*pos)) flag=true;
                    }
                }
            } else if(tmp>=2*pos){ ///ir 1 berns
                if(change(pos,2*pos)) flag=true;
            }
        }
    }
}

void h_insert(int cashier,int id, char tips, int mas[], int pre[]){ ///mas - kases darba laiks
    heap T;
    T.time = max(pre[cashier],id)+mas[cashier];
    T.cashier = cashier;
    T.tips = tips;
    T.id = id;
    H[N_length+P_length+1] = T;
    up();
}

heap h_delete(){ ///dzest augsejo elements
    int tmp;
    heap y=H[1];
    tmp=P_length+N_length;
    if(H[1].tips=='P') P_length--;
    else N_length--;
    H[1] = H[tmp];
    H[tmp].time = 0;
    down();
    return y;
}

int free_cashier(bool mas[],int S){ ///atrast pirmo brivo kasi
    for(int i=1; i<=S; i++) if(mas[i]==true) return i;
    return 0;
}

void free_heap(ofstream &fout){
    int w;
    heap r;
    w = H[1].time;
    while(w==H[1].time){
        r=h_delete();
        fout<<r.id<<' '<<r.time<<'\n';
        if(r.tips=='P') {
            free_P[r.cashier]=true;
            pre_P[r.cashier] = r.time;
        }
        if(r.tips=='N') {
            free_N[r.cashier]=true;
            pre_N[r.cashier] = r.time;
        }
    }
}

void free_rinda(){
    int free,free2;
    bool A=false,B=false;
    free = free_cashier(free_P,P_size); //mekle brivas vietas pilsoniem
    free2 = free_cashier(free_N,N_size); //mekle brivas vietas pilsoniem
    if(free!=0 && COUNT_P>0) A=true;
    if(free2!=0 && COUNT_N>0) B=true;

    while(A || B){ //ja ir vietas un rindaa ir cilveki
        if(A){
            h_insert(free,P[start_P].id,P[start_P].tips,worktime_P,pre_P);
            free_P[free]=false;
            P_length++;
            if(start_P == finish_P) finish_P++;
            if(start_P==MM) start_P=0;
            else start_P++;
            COUNT_P--;
        }
        if(B){
            h_insert(free2,N[start_N].id,N[start_N].tips,worktime_N,pre_N);
            free_N[free2]=false;
            N_length++;
            if(start_N == finish_N) finish_N++;
            if(start_N==MM) start_N=0;
            else start_N++;
            COUNT_N--;
        }
        free = free_cashier(free_P,P_size); //mekle brivas vietas pilsoniem
        free2 = free_cashier(free_N,N_size); //mekle brivas vietas pilsoniem
        if((free==0 || COUNT_P==0)) A=false;
        if((free2==0 || COUNT_N==0)) B=false;
    }
};

int main(){
    ifstream fin;
    ofstream fout;
    int c,free;
    unsigned int a;
    char b;
    bool E=false, inserting=false;
    heap r;
    fin.open("customs.in", ios::in);
    fout.open("customs.out", ios::out);

    fin>>a; ///Lasam kaudzes izmerus

    P_size=a+1;
    for(int i=1; i<P_size; i++) {free_P[i]=true; pre_P[i]=0;} /// - skaita kopejo laiku pie muitnieka

    fin>>a;
    N_size=a+1;
    for(int i=1; i<N_size; i++) {free_N[i]=true; pre_N[i]=0;}

    fin>>a; ///Darba laiks P un N
    for(int i=1; i<P_size;i++) worktime_P[i]=a;
    fin>>a;
    for(int i=1; i<N_size;i++) worktime_N[i]=a;

    fin>>b;
    while(b=='T'){ ///Personigs darba laiks
        fin>>b;
        fin>>a;
        fin>>c;
        if(b=='P') worktime_P[a]=c;
        else worktime_N[a]=c;
        fin>>b;
    }

    if(b!='X'){ ///Ja ir vismaz kaut kas
        while(b!='X'){
            fin>>a;  ///LASAM personas ID!
            inserting=false;
            if(P_length+N_length>0){
                do{
                    /**DZESAM ARA VISUS MUITNIEKUS AR VIENADU IZESANAS LAIKU**/
                    if(a>=H[1].time || E ) {free_heap(fout);}
                    E=false;

                    /**PIEVIENOJAM NO RINDAS KANDIDATUS, JA TIEM IR BRIVA VIETA**/

                    free_rinda();

                    /** MEGINAM IEVIETOT TIKKO IZLASITO KAUDZEE*/

                    if(b=='P') free = free_cashier(free_P,P_size);
                    else free = free_cashier(free_N,N_size);

                    if(!inserting){ //ja vel neievietojam
                        if(free!=0){ ///100% rinda bus tuksa!
                            if(b=='P'){
                                h_insert(free,a,b,worktime_P,pre_P);
                                inserting=true;
                                free_P[free]=false;
                                P_length++;
                            } else if(b=='N'){
                                h_insert(free,a,b,worktime_N,pre_N);
                                inserting=true;
                                free_N[free]=false;
                                N_length++;
                            }

                    /**MEGINAM IEVIETOT TIKKO IZLASITO RINDAA**/
                        } else{
                            if(b=='P') {
                                if(COUNT_P==MM) {E=true ; continue;}  //Ja ir griesti
                                else{
                                    if(finish_P==MM) finish_P=-1;
                                    if(COUNT_P==0){
                                        P[finish_P].id = a;
                                        P[finish_P].tips = 'P';
                                        inserting=true;
                                    } else{
                                        P[finish_P+1].id = a;
                                        P[finish_P+1].tips = 'P';
                                        finish_P++;
                                        inserting=true;
                                    }
                                    COUNT_P++;
                                }
                            }
                            if(b=='N') {
                                if(COUNT_N==MM) {E=true; continue;}  //Ja ir griesti
                                else{
                                    if(finish_N==MM) finish_N=-1;
                                    if(COUNT_N==0){
                                        N[finish_N].id = a;
                                        N[finish_N].tips = 'N';
                                        inserting=true;
                                    } else{
                                        N[finish_N+1].id = a;
                                        N[finish_N+1].tips = 'N';
                                        finish_N++;
                                        inserting=true;
                                    }
                                    COUNT_N++;
                                }
                            }
                        }
                    }
                } while(a>=H[1].time || E);

            } else{ ///Pasa pirma elementa iesprausana
                if(b=='P') {
                    h_insert(1,a,b,worktime_P,pre_P);
                    free_P[1]=false;
                    P_length++;
                } else{
                    h_insert(1,a,b,worktime_N,pre_N);
                    free_N[1]=false;
                    N_length++;
                }
            }
            fin>>b; ///nakama rinda
        }

       while(COUNT_P!=0 || COUNT_N!=0){ ///atbrivo gaidisanas rindas
            free_heap(fout);
            free_rinda();
        }

        c=P_length+N_length;
        for(int i=0; i<c; i++){ ///atbrivo kaudzi
            r=h_delete();
            fout<<r.id<<' '<<r.time<<'\n';
        }
    } else fout<<"nothing";
    fout.close();
    fin.close();
}
