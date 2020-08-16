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
cout<<"Input card number:";
cin>>card_digits;

if(card_digits.size()==15 || card_digits.size()==13 || card_digits.size()==16){
  cout<<"aaa"<<endl;
  if(checksum(card_digits)){

    if(isAMERICAN_EXPRESS(card_digits) && card_digits.size()==15){
      cout<<"AMERICAN_EXPRESS"<<endl;
      }
    if(isMASTERCARD(card_digits) && card_digits.size()==16){
      cout<<"MASTERCARD"<<endl;
      }
    if(isVISA(card_digits) && (card_digits.size()==13 || card_digits.size()==16)){
      cout<<"VISA"<<endl;
      }
  }
}else{ cout<<"INVALID"<<endl;
}
}
//FUNCTIONS:

//American express start with 34 or 37
bool isAMERICAN_EXPRESS(string d){
  if(d.substr(0,1)=="34" || d.substr(0,1)=="37"){
    return true;
  }else{return false;}
}

//Mastercards start with 51,52,53,54 or 55
bool isMASTERCARD(string d){
  if(d.substr(0,1)=="51" || d.substr(0,1)=="52" || d.substr(0,1)=="53" || d.substr(0,1)=="54" || d.substr(0,1)=="55"){
    return true;
  }else{return false;}
}

//Visas start with 4
bool isVISA(string d){
  if(d.substr(0)=="4"){
    return true;
  }else{return false;}
}

//convert string char into int char
char conv_stringchar(string){
    return 1;
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
  //long long int card_number=stoll(card);  //need to convert to long long int because the number is very big once converted
  int sum1=0;
  int sum2=0;
  int sum3;
  int card_code;
  vector<int> v;


  if(card.length()==16){
    for (int i=0; i < card.length(); i=i+2){ // even positions
      v.push_back((int)(card[i])*2);      // in this way i convert the chars of the string into int
    }
    for(int p=0; p<v.size();p++){  // summing the content of vector v
      sum1= sum1 + splitsum(v[p]);
    }
    for(int t=1; t<card.length(); t=t+2){ //adding the sum to the sum of the digits that weren't multiplied by 2
      sum2= sum2 + (int)(card[t]);
    }
    sum3=sum2+sum1;
    if(sum3 % 10 ==0){
      return true;
    }else{return false;}
  }

  if(card.length()==13 || card.length()==15){   //odd positions
    for (int i=1; i < card.length(); i=i+2){
      v.push_back((int)(card[i])*2);
      }
      for(int p=0; p<v.size();p++){  // summing the content of vector v
        sum1= sum1 + splitsum(v[p]);
      }
      for(int t=0; t<card.length(); t=t+2){ //adding the sum to the sum of the digits that weren't multiplied by 2
        sum2= sum2 + (int)(card[t]);
      }
      sum3=sum2+sum1;
      if(sum3 % 10 ==0){
        return true;
      }else{return false;}
    }
  }
