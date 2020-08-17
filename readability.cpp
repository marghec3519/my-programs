#include <iostream>
#include <string>
#include <vector>
using namespace std;

//IMPROVEMENT: detect double whitespaces

float average_letter_number(int n_of_letters, int n_of_words);
float average_sentence_number(int n_of_sentences, int n_of_words);
int readability(float average_L, float average_S);

int main() {

char letter;
char whitespace= ' ';
string words;
vector<string> text;
int n_of_words=1;
int n_of_letters=0;
int n_of_sentences=0;


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
    for (int i = 0; words[i]=='\0'; i++) {
      n_of_letters++;
    }


    break;

}

cout<<n_of_letters<<';'<<n_of_words<<';'<<n_of_sentences<<endl;
  return 0;
}

float average_letter_number(int n_of_letters, int n_of_words){

  float average_L= (n_of_letters/n_of_words)*100;
  return average_L;
}

float average_sentence_number(int n_of_sentences, int n_of_words){

  float average_S=(n_of_sentences/n_of_words)*100;
  return average_S;
}

int readability(float average_L, float average_S){
  int index= (0.0588*average_L)-(0.296*average_S)-15.8;
  return index;
}
