#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long int n,k,lenght,op=0,extra=0,aux;
    cin>>n,k;
    vector<long int> drinks(n);
    lenght=n;
    for(int i=0; i<n; i++){
        cin>>drinks[i];
    }
    sort(drinks.begin(), drinks.end());

    long int new_drink=0;

        while((lenght>1)&& (drinks[0]<k)){ //AQUI ES DONDE NO ENTRA UnU

            new_drink=drinks[0]+2*drinks[1];

            aux=drinks[0];
            drinks[0]=drinks[lenght-1];
            drinks[lenght-1]=aux;
            aux=drinks[1];
            drinks[1]=drinks[lenght-2];
            drinks[lenght-2]=aux;

            drinks.pop_back();
            drinks.pop_back();

            drinks.push_back(new_drink);
            sort(drinks.begin(), drinks.end());
            lenght--;
            extra+=2;
            op+=1;
        }
    if(lenght>1){
        cout<<op;
    }else if(drinks[extra]>k){
        cout<<op;
    }else{
        cout << -1;
    }
    return 0;
}
