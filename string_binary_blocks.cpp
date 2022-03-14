#include <bits\stdc++.h>
using namespace std;

// shannon entropy
double shannon_entropy(double freq, double size)
{
    double probability = freq / size;
    if (probability == 1)
        return 0;
    double shan_entpy = -(probability * (log2f(probability)));
    return shan_entpy;
}

//** tsallis Entropy **
double tsallis_entropy(double freq, double size, double q)
{
    double pow_probability = pow(freq / size, q);
    double tsal_entpy = (1 / (q - 1)) * (1 - pow_probability);
    return tsal_entpy;
}

//** frequency part **
void frequency(vector<string> ans)
{
    int size = ans.size();
    map<string, int> freq_map;
    for (int i = 0; i < size; i++)
    {
        freq_map[ans[i]]++;
    }
    for (const auto &elm : freq_map)
    {
        cout << "frequency of " << elm.first << " is  " << elm.second << endl;

        //** calling the shannon function **
        cout << "shanon entropy of " << elm.first << "is  " << shannon_entropy(double(elm.second), double(size)) << endl;

        //** calling the shannon function **
        for (double q = 2; q <= 4; q++)
        {
            cout << "tsallis entropy of " << elm.first << " for q = " << q << "is " << tsallis_entropy(double(elm.second), double(size), q) << endl;
        }
        cout<<endl<<endl;
    }
}
int main()
{
    vector<string> ans;
    string str = "";

    //** opening the input file **
    ifstream input;
    input.open("random_numbers_binary_edition.csv");

    //**putting all number blocks in a string and then pushing in a vector**
    while (!input.eof())
    {
        getline(input, str);
        ans.push_back(str);
    }
    input.close();
    frequency(ans);

    return 0;
}