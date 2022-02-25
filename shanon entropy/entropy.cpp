// shanon entropy by taking string and window size at runtime by the user
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double calcEntropy(string str, int size, int start, int end)

{
    int c = 0;
    for (int i = start; i < end; i++)
    {
        if (str[i] == '1')
            c++;
    }
    double probability = (double)c / size;
    double p = probability / size;
    return -((p)*log2f(p));
}

int main()
{
    string str;
    cout << "enter a binary string : ";
    cin >> str;

    int win_size;
    cout << "enter the window size : ";
    cin >> win_size;

    int objects_taken = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if ((i + win_size) > str.size())
            break;

        objects_taken++;
    }

    int end = win_size;
    for (int i = 0; i < objects_taken; i++)
    {
        cout << "entropy " << i + 1 << ": " << calcEntropy(str, str.size(), i, end) << endl;
        end++;
    }

    return 0;
}