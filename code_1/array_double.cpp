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
    } else {
        std::cout << "Failed to open " << ignoreWordFileName << std::endl;
    }
    

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
    wordRecord temp;
    for (int i = 0; i < length; i++){
        for (int j = i+1; j < length; j++){
            if (distinctWords[i].count < distinctWords[j].count){
                temp = distinctWords[i];
                distinctWords[i] = distinctWords[j];
                distinctWords[j] = temp;
            }

            if(distinctWords[i].count == distinctWords[j].count) {
                if(distinctWords[i].word.compare(distinctWords[j].word) > 0) {
                    temp = distinctWords[i];
                    distinctWords[i] = distinctWords[j];
                    distinctWords[j] = temp;
                }
            }

        }
    }


}


void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords){
    cout << "Probability of next 10 words from rank " << N << endl;
    cout << "--------------------------------------- "<<endl;

    for(int i = N;i<(N+10);i++) {
        float probability = (distinctWords[i].count / float(totalNumWords));
        // cout << fixed << setprecision(5) << probability << endl;
        cout << fixed << setprecision(5)<<probability<<" - " <<distinctWords[i].word<<endl;
    }
}

