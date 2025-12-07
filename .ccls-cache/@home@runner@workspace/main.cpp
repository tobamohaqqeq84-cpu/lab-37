#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream> // for part 2

using namespace std;

const int TABLE_SIZE = 97;

int gen_hash_index(const string& s){
    int sum =0;
    for (char c : s){
        sum += (int)c;
    }
    return sum % TABLE_SIZE;
}
int main() {

    ifstream fin("lab-37-data.txt");

    if (!fin){
        cout << "Error opening file!" << endl;
        return 1;
    }
      map<int, list<string>> hash_table;

    string line;
    while (fin >> line){
        int index = gen_hash_index(line);
        hash_table[index].push_back(line);
    }
    int shown = 0;
    for(auto &entry :hash_table){
        cout << "Index " << entry.first << ": ";
        for (const string &s : entry.second){
            cout << s << " ";
        }
        cout << endl;
        shown++;
        if (shown == 100){
            break;
        }
        return 0;
    }
//milestone 3
    
    
//char a = 'A';
//cout << a << endl;
//cout << (int) a << endl
    
//int b = 66;
//cout << b << endl;
//cout << (char) b << endl;
//return 0;
}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
//starting the code 
