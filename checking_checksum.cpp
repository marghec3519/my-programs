#include <iostream>
#include <vector>
#include <string>
using namespace std;

int splitsum(int x);

int main(){

  string card="4003600000000014";
  //long long int card_number=stoll(card);  //need to convert to long long int because the number is very big once converted

  int sum1=0;
  int sum2=0;
  int sum3;
  int card_next;
  int card_code;
  vector<int> v;

  if(card.size()==16){
    for (int i=0; i < card.size(); i=i+2){ // even positions
      card[i]= card[i]-48;    //in ASCII 48 is the difference between char and numbers!
      card_next=card[i]*2;

      v.push_back(card_next);

      cout<<"line 23 : "<<card[i]<<"  "<< card_next<<" ; "<<v[0]<<";"<<v[1]<<";"<<v[2]<<endl;
    }
    for(int p=0; p<v.size();p++){  // summing the content of vector v
      sum1= sum1 + splitsum(v[p]);
      cout<<"line 27 : "<<sum1<<endl;
    }
    for(int t=1; t<card.size(); t=t+2){ //adding the sum to the sum of the digits that weren't multiplied by 2
      card[t]= card[t]-48;
      sum2= sum2 + card[t];
      cout<<"line 35 : "<<sum2<<endl;
    }
    sum3=sum2+sum1;
    cout<<sum3<<endl;
    if(sum3 % 10 ==0){
      cout<<"true16"<<endl;
      return true;
    }else{cout<<"false16"<<endl;
          return false;
          }
  }

  if(card.size()==13 || card.size()==15){   //odd positions
    for (int i=1; i < card.size(); i=i+2){
      card[i]= card[i]-48;    //in ASCII 48 is the difference between char and numbers!
      card_next=card[i]*2;

      v.push_back(card_next);

      }
      for(int p=0; p<v.size();p++){  // summing the content of vector v
        sum1= sum1 + splitsum(v[p]);
      }
      for(int t=0; t<card.size(); t=t+2){ //adding the sum to the sum of the digits that weren't multiplied by 2
        card[t]=card[t]-48;
        sum2= sum2 + card[t];
      }
      sum3=sum2+sum1;
      if(sum3 % 10 ==0){
        cout<<"true13-15";
        return true;
      }else{cout<<"false13-15";
            return false;
            }
    }
  }


  int splitsum(int x){
    if(x>9){

      string n=to_string(x);

      string fir(1,n[0]);
      string sec(1,n[1]);
      int f= stoi(fir);
      int s= stoi(sec);
      int s_sum= f + s;
      return s_sum;
    }else{
      return x;}
  }
