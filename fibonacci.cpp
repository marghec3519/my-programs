#include <iostream>

// This program is meant to print the fibonacci serie

using namespace std;

int main(){

  int param;
  int x1=0;
  int x2=1;
  int next;

  cout<<"Enter parameter: ";
  cin>>param;
  cout<<"Fibonacci series: "<<endl;

  cout<<x1<<endl<<x2<<endl;

  for(int i=2; i<param; i++){
    next=x1+x2;
    cout<<next<<endl;
    x1=x2;
    x2=next;

    }
}

/*
0
1
1
2
3
5
8
13
21
34
*/
