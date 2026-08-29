#include <iostream>
using namespace std;
int main(){
long long seed=3043;

while(true){
int j;

int k;

cout<<"numero del alfabeto a usar: "<<"\n"; // o en otras palabras el tamaño del alfabeto
cin>>k;
cout<<"longitud de la cadena: "<<"\n";
cin>>j;
if(j==-67){
    break;
}

for(int i=0;i<j;i++){
long long x=((1103515245* seed) +12345)%(2147483648);
    cout<<x<<"\n";
    int h=x%k;
    cout<<"resultado de la division: "<<h<<"\n";
    seed=x;

}

cout<<"se finalizo el calculo, la semilla (si se requiere hacer algo) es: "<<seed<<"\n";
}

}

//primera contraseña: 2,25,22,3
//la unica forma para salir es que j ==-67
//para finalizar,dependiendo del alfabeto usado en cada parte se contrata con la posicion obtenida con el de dicho alfabeto