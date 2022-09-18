#include <iostream>
#include <fstream>
#include "../code_1/array_double.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    // int n;
    ifstream text;
    string str;
    text.open(argv[2]);
    // n = *argv[1] / 2;

    string ignoreWords[50];

    cout << argv[3] << endl;
    getIgnoreWords(argv[3], ignoreWords);

    wordRecord *distinctWords = new wordRecord[100];
    int numElements = 0;

    if (text.is_open())
    {
        while (getline(text, str, '\n'))
        {
            if (!isIgnoreWord(str, ignoreWords, 50))
            {

                bool wordRepeat = true;

                if (numElements > 100)
                { // if the amount of elements will exceede the array size, start the doubling
                    wordRecord *temp = new wordRecord[2 * numElements];
                    for (int i = 0; i < numElements; i++)
                    {
                        temp[i] = distinctWords[i];
                    }

                    delete[] distinctWords;
                    distinctWords = temp;
                    numElements = 2 * numElements;
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
            cout << distinctWords[i].word << " Count: " << distinctWords[i].count << endl;
        }
    }

    return 0;
}