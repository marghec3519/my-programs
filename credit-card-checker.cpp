#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*This program checks if the number of the credit card is valid according to Luhn's algorithm - a checksum
and outputs which type of card it is*/

/* input a string of chars
if alpha QUIT or if more than x chars QUIT
if digit proceed
  if start with -- and has-- digits => VISA
  if start with -- and has-- digits => MASTERCARD

  LUHN'S algorithm */

bool isAMERICAN_EXPRESS(string d);
bool isMASTERCARD(string d);
bool isVISA(string d);
int splitsum(int x);
bool checksum(string d);

int main(){
string card_digits;
cout<<"Input card number: ";
cin>>card_digits;

if(card_digits.size()==15 || card_digits.size()==13 || card_digits.size()==16){

  if(checksum(card_digits)){
      cout<<"Valid: ";
    //cout<<"line 31 here!"<<endl;
    if(isAMERICAN_EXPRESS(card_digits) && card_digits.length()==15){
      cout<<"AMERICAN_EXPRESS"<<endl;
      }
    if(isMASTERCARD(card_digits) && card_digits.length()==16){
      cout<<"MASTERCARD"<<endl;
      }
    if(isVISA(card_digits) && (card_digits.length()==13 || card_digits.length()==16)){
      cout<<"VISA"<<endl;
      }
  }else{cout<<"INVALID"<<endl;}
}else{
cout<<"INVALID"<<endl;
}
}
//FUNCTIONS:

//American express start with 34 or 37
bool isAMERICAN_EXPRESS(string d){
  if(d[0]=='3' && (d[1]==4 || d[1]==7)){
    return true;
  }else{return false;}
}

//Mastercards start with 51,52,53,54 or 55
bool isMASTERCARD(string d){
  if(d[0]=='5' && (d[1]==1 || d[1]==2 || d[3]==3 || d[4]==4 || d[5]==5)){
    return true;
  }else{return false;}
}

//Visas start with 4
bool isVISA(string d){
  if(d[0]=='4'){
    return true;
  }else{return false;}
}

//split a number and sum its digits
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

//Luhn's Algorithm:
bool checksum(string card){

  //string card="4003600000000014";

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

    //  cout<<"line 104 : "<<card[i]<<"  "<< card_next<<" ; "<<v[0]<<";"<<v[1]<<";"<<v[2]<<endl;
    }
    for(int p=0; p<v.size();p++){  // summing the content of vector v
      sum1= sum1 + splitsum(v[p]);
      //cout<<"line 108 : "<<sum1<<endl;
    }
    for(int t=1; t<card.size(); t=t+2){ //adding the sum to the sum of the digits that weren't multiplied by 2
      card[t]= card[t]-48;
      sum2= sum2 + card[t];
      //cout<<"line 113 : "<<sum2<<endl;
    }
    sum3=sum2+sum1;
    //cout<<sum3<<endl;
    if(sum3 % 10 ==0){
    //  cout<<"true16"<<endl;
      return true;
    }else{//cout<<"false16"<<endl;
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
        //cout<<"true13-15";
        return true;
      }else{//cout<<"false13-15";
            return false;
            }
    }
  }
