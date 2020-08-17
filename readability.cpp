#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//IMPROVEMENT: detect double whitespaces

int main() {

string words;
float n_of_words=1;
float n_of_letters=0;
float n_of_sentences=0;


while(free){
    getline(cin,words);

    //n_of_letters+= cin.gcount();
    for (int i = 0; words[i]!='\0'; i++) {
      if(words[i]==' '){
      n_of_words++;
      }
      if (words[i]=='.' || words[i]=='!' || words[i] =='?') {
      n_of_sentences++;
      }
    }
    for (int i = 0; words[i]!='\0'; i++) {
      if(!isspace(words[i])&&!ispunct(words[i])){
      n_of_letters++;
      }
    }
    break;
}
//cout<<n_of_letters<<';'<<n_of_words<<';'<<n_of_sentences<<endl;

float averL= (n_of_letters/n_of_words)*100;
float averS= (n_of_sentences/n_of_words)*100;
//cout<<<<averS<<';'<<averL<<endl;

//Coleman-Liau index:
float index= (0.0588*100*(n_of_letters/n_of_words))-(0.296*(n_of_sentences/n_of_words)*100)-15.8;

int readability_index= round(index);
cout<<"->> The 'Coleman-Liau readability index' of this text is : "<<readability_index<<endl;
  return 0;
}
