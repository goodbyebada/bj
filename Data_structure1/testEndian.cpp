#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

int main()
{
    int a = 0x00000001;
    if (((char *)&a)[0] == 1)
    {
        // little endian
        cout << "litte";
    }
    else
    {
        // big endian
        cout << "bigEndian";
    }
}