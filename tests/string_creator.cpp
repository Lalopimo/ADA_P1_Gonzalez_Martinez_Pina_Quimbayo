#include <iostream>
#include "../third_party/picosha2.h"


using namespace std;
int main(){
//long long seed=3043;

//esto es para sacar la semilla por la suma de los ASCII
long long suma_ascii=0;
string name_chain;
cout<<"ingrese el nombre al que desea sacarle la suma de sus Ascii: "<<"\n";
cin>>name_chain;

for(char v:name_chain){
 suma_ascii=suma_ascii+v;
}
cout<<"suma de los ascii es igual a: "<<suma_ascii<<"\n";


while(true){
int j;

int k;


cout<<"longitud de la cadena: "<<"\n";
cin>>j;
if(j==-67){
    break;
}
string alphabet;
cout<<"Ingrese el alfabeto sobre el cual se va a trabajar: "<<"\n";
cin>>alphabet;
string world="";
for(int i=0;i<j;i++){
long long x=((1103515245* suma_ascii) +12345)%(2147483648);
    
    
    int h=x%alphabet.length();
   
    suma_ascii=x;
    world+=alphabet[h];

}
cout<<""<<"\n";
cout<<world<<"\n";
string candidateHash = picosha2::hash256_hex_string(world);
cout<<candidateHash<<"\n";

}

}


//la unica forma para salir es que j ==-67
