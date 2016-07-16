//white noise generator

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

int main()
{
    srand(time(NULL));
    long long int value=0;
    ofstream myfile;
    myfile.open("Random.txt", ios::out | ios::app );
        for (int i = 0; i < 1000000; ++i)
        {
            value = rand();
            myfile<<value<<"\n";
        }
    return 0;
}
