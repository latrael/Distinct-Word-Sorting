#include <iostream>
#include <fstream>
#include "../code_1/array_double.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    // int n;
    ifstream text;
    string open = argv[2];
    string str;
    //text.open(argv[2]);
    // n = *argv[1] / 2;
    string ignoreWords[50];
    //cout << argv[3] << endl;
    getIgnoreWords(argv[3], ignoreWords);
    wordRecord *distinctWords = new wordRecord[100];
    int numElements = 0;
    int doubling = 100;

    text.open(open.c_str());

    if (text.is_open())
    {
        while (text>>str)
        {
            cout << str << endl;
            if (!isIgnoreWord(str, ignoreWords, 50))
            {

                bool wordRepeat = true;

                if (numElements == doubling)
                { // if the amount of elements will exceede the array size, start the doubling
                    wordRecord *temp = new wordRecord[2 * doubling];
                    for (int i = 0; i < numElements; i++)
                    {
                        temp[i] = distinctWords[i];
                    }

                    doubling = doubling * 2;
                    delete[] distinctWords;

                    distinctWords = new wordRecord[doubling];
                    for(int i=0; i < numElements;i++) {
                        distinctWords[i] = temp[i];
                    }
                    //distinctWords = temp;
                    delete [] temp;
                    
                }

                for (int i = 0; i < numElements; i++)
                { // checks to see if the distinct word has already been recorded
                    if (distinctWords[i].word == str)
                    {
                        distinctWords[i].count++;
                        wordRepeat = false;
                    }
                }
                if (wordRepeat)
                {
                    //wordRecord b;
                    //distinctWords[numElements] = b;
                    distinctWords[numElements].word = str;
                    distinctWords[numElements].count = 1;
                    numElements++;
                }
            }
        }
        for (int i = 0; i < numElements; i++)
        {
            cout << distinctWords[i].word << endl;
        }
    }

    return 0;
}