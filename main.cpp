//Toba Mohaqqeq
//COMSC-210
//lab -37

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream> 

using namespace std;

const int TABLE_SIZE = 97;

int gen_hash_index(const string& s){
    int sum =0;
    for (char c : s){
        sum += (int)c;
    }
    return sum % TABLE_SIZE;
}
void load
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
        }
        return 0;
    }
//THE END
