#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

double calcentropy(string str, double count, int file_size)

{
    if (str.length() == 0)
        return -((count / file_size) * log2f(count / file_size)); // use log base 2

    if (str[0] == '1')
        count++;

    return calcentropy(str.substr(1), count, file_size);
}

int main()
{
    string str = "";
    ifstream file;
    file.open("ok.csv");


    file >> str;

    // file.seekg(0, ios::end );
    // int file_size = file.tellg();
    // cout<<"Size of the file is"<<" "<< file_size<<" "<<"bytes" << endl;

    //cout << " contents of file are " << file.rdbuf() << endl;

    int file_size = str.size();
    int win_size;
    file >> win_size;



    int count = 0;
    for (int i = 0; i < file_size; i++)
    {
        if ((i + win_size) > file_size)
            break;

        count++;
    }

    cout << "size of file is : " << file_size << endl;


    ofstream storage_file;
    storage_file.open("storage.csv");
    storage_file.clear();

    for (int i = 0; i < count; i++)
    {
        storage_file << "entropy " << i + 1 << ": " << calcentropy(str.substr(i, win_size),0, file_size) << endl;
    }

    storage_file.close();
    file.close();

    return 0;
}