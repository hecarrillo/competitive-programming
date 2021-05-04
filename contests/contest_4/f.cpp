#include <bits/stdc++.h>

using namespace std;

int main(){

   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   auto a = 0, b = 0, n = 0;
   cin>>a;
   cin>>b;
   cin>>n;

   for(auto i=0; i<n ;i++){
      string conv_a = to_string(a);

      for(auto i=0;i<10;i++){
         if(stoll(conv_a + to_string(i)) % b == 0){
            a = stoll(conv_a + to_string(i));
         }
      }
   }

   if((a%b) == 0){
      cout<<a;
   }else{
      cout<<"-1";
   }

   cout << endl;

   return 0;
}
