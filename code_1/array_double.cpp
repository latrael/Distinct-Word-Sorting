#include "array_double.hpp"

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[]){
    ifstream inStream;
    inStream.open(ignoreWordFileName);
    string str;

    int numElements = 0;
    if(inStream.is_open()) {
        while(getline(inStream, str, '\n')) {
            ignoreWords[numElements] = str;
            numElements++;
        }
    }
    std::cout << "Failed to open " << ignoreWordFileName << std::endl;

}


bool isIgnoreWord(string word, string ignoreWords[], int length){
    for(int i = 0;i<length;i++) {
        if(word == ignoreWords[i]) {
            return true;
        }
    }
    return false;  
}


int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length){
    int total = 0;
    for(int i = 0;i<length;i++) {
        total += distinctWords[i].count;
    }
    return total;
}


void sortArray(wordRecord distinctWords[], int length){
    int num = 0;
    wordRecord temp[length];
     for(int i = 0;i<length;i++) {
        temp[i] = distinctWords[i];
    }
    for(int i=0;i<length;i++) {
        if(distinctWords[i].count > num) {
            temp[i+1] = temp[i];
            temp[i] = distinctWords[i];
        }
        temp[i] = distinctWords[i];
    }

    for(int i = 0;i<length;i++) {
        distinctWords[i] = temp[i];
    }
}


void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords){
}

