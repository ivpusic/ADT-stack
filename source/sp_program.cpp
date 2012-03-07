#include <iostream>
#include "stog_polje.h"
//#include "stog_pokazivac.h"

using namespace std;

stog *S = InitS(S);

void izbornik(){
     cout<<"0. Izlaz iz programa"<<endl;
     cout<<"1. Dodavanja zapisa"<<endl;
     cout<<"2. Iskrcaj svih automobila proizvedenih poslije 2006 / bez 'Audi' "<<endl;
     cout<<"3. Ispis svih marke 'Audi' (bez obzira na god. proizvodnje)"<<endl;
     }//fun
void ispis(){
     cout<<"Novo stanje: "<<endl<<endl;
    tauto temp, polje[50];
    int kursor=0;
    while(!IsEmptyS(S)){
      temp = TopS(S);
      polje[kursor] = temp;
      kursor++;
      PopS(S);                   
    }//while
    cout << endl;
    for (int i=kursor-1;i>=0;i--) {
          cout << "Serijski broj: " << polje[i].sb << endl;
          cout << "Proizvodac: " << polje[i].proizvodac << endl;
          cout << "Model: " << polje[i].model << endl;
          cout << "Godina proizvodnje: " << polje[i].godina << endl;
          cout<<"----------------------------------"<<endl<<endl;
      temp = polje[i];
      PushS(temp, S);
   }//for(i)
}//fun

void unos() {
     tauto novi;
     cout << "Serijski broj: "; cin >> novi.sb;
     cout << "Proizvodac: "; cin.ignore(); cin.getline(novi.proizvodac, 20);
     cout << "Model: "; cin >> novi.model;
     do {
       cout << "Godina: "; cin >> novi.godina;
       } while (novi.godina<1995 || novi.godina>2010);     
     PushS(novi, S);
     cout<<"----------------------------------"<<endl<<endl;
}//fun

void iskrcaj1(){
   stog *P = InitS(P);
   tauto pom;
   while (!IsEmptyS(S)) {
      pom=TopS(S);
      PopS(S);
      PushS(pom, P);  
      if(pom.godina >= 2006){
       if(stricmp(pom.proizvodac,"audi")) {
       cout << "Serijski broj: " << pom.sb << endl;
       cout << "Proizvodac: " << pom.proizvodac << endl;
       cout << "Model: " << pom.model << endl;
       cout << "Godina proizvodnje: " << pom.godina << endl;
       cout<<"----------------------------------"<<endl<<endl;
       }//if
       }//if
      }//while
      cout<<"Novo stanje: "<<endl<<endl<<endl;
      
   while (!IsEmptyS(P)) {
      pom=TopS(P);
      PopS(P); 
      if(pom.godina<2006 || !(stricmp(pom.proizvodac,"audi"))) {
       PushS(pom,S);
       cout << "Serijski broj: " << pom.sb << endl;
       cout << "Proizvodac: " << pom.proizvodac << endl;
       cout << "Model: " << pom.model << endl;
       cout << "Godina proizvodnje: " << pom.godina << endl;
       cout<<"----------------------------------"<<endl<<endl;
      }
  }
}//fun

void iskrcaj2(){
  if (!IsEmptyS(S)) {
   tauto pom;
   pom = TopS(S);
   PopS(S);
   if(!IsEmptyS(S))
     iskrcaj2();
     
   if(!(stricmp(pom.proizvodac,"audi"))){
      cout << "Serijski broj: " << pom.sb << endl;
       cout << "Proizvodac: " << pom.proizvodac << endl;
       cout << "Model: " << pom.model << endl;
       cout << "Godina proizvodnje: " << pom.godina << endl;
       cout<<"----------------------------------"<<endl<<endl;
       }
   else
     PushS(pom, S);
   return;   
  }   
}//fun

int main() {
    int iz;
    bool uneseno = false;
do{
    izbornik();
    cin >> iz;
    switch(iz){
                  case 1:
                       for(int i=0;i<3;i++){
                               unos();
                               }
                       uneseno = true;
                       break;
                  case 2:
                       if(!uneseno){
                                    cout<<"Prvo unesite podatke o automobilima!!!"<<endl;
                                    break;
                                    }
                       iskrcaj1();
                       break;
                  case 3:
                       if(!uneseno){
                                    cout<<"Prvo unesite podatke o automobilima!!!"<<endl;
                                    break;
                                    }
                       iskrcaj2();
                       ispis();
                       break;
                  }//switch
}while(iz != 0);
system("PAUSE");
return 0;    
}
