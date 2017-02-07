#include <iostream>
#include <cstdlib>
using namespace std;

//Function Prototype
int countWords(char words[]);

int main(){

    char words[256];

    cout << "Enter a sentence: ";
    cin.getline(words, 256);

    int word_num = countWords(words);
    cout << "The number of words in a string is: " << word_num << endl;

    system("PAUSE");
    return 0;
}

int countWords(char words[]){
    int nSpaces = 0;
    //unsigned int i = 0;

    /*while(isspace(words[i])){
        i++;
    }*/

    for (int i=0; i<256; i++){
        if(isspace(words[i])){
           nSpaces++;
            // Skip over duplicate spaces & if a NULL character is found, we're at the end of the string
            //while(isspace(words[i++]))
                if(words[i] == '\0')
                    nSpaces--;
        }
    }
    // The number of words = the number of spaces + 1
    return nSpaces + 1;
}