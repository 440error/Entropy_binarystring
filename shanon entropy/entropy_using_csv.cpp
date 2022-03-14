#include <bits/stdc++.h>
using namespace std;

double calculateEntropy(string str, int start, int end, int window_size)
{

    int count = 0;
    for (int i = start; i < end; i++)
    {

        if (str[i] == '1')
            count++;
    }

    double probability = (double)count / double(window_size);

    double p = probability;

    if (p == 1)
        return 0;
    return -((p)*log2f(p));
}
int main()
{

    string str = "";
    ifstream Input_value;
    Input_value.open("shanon_in.csv");
    cout << "the string is: ";

    while (Input_value.eof() == 0)
    {
        Input_value >> str;
        // getline(Input_value,str) ;
        cout << str << endl;
        Input_value.close();
    }
    cout << "size of string " << str.size() << endl;

    ofstream output;
    output.open("shanon_out.csv");

    int no_of_entropies;
    int window_size;

    cout << endl
         << "the no.of entropies you want : ";
    cin >> no_of_entropies;
    cout << endl;

    window_size = str.size() - (no_of_entropies - 1);
    cout << "window size will be " << window_size << endl;
    
    for (int i = 0; i < no_of_entropies; i++)
    {
        output << "entropy " << i + 1 << " is " << calculateEntropy(str, i, window_size + i, window_size) << endl;
    }

    output.close();

    return 0;
}