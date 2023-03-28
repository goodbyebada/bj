#include <iostream>
// #include <string>
using namespace std;

string cmp(int a, int b)
{
    if (a % b == 0)
    {
        return "multiple";
    }
    else if (b % a == 0)
    {
        return "factor";
    }
    else
    {
        return "neither";
    }
}

int main(void)
{

    int a, b;

    while (1)

    {
        cin >> a >> b;
        if (a == b)
            break;
        cout << cmp(a, b) << endl;
    }

    return 0;
};
