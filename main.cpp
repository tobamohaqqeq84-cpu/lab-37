#include <iostream>
#include <fstream> // for part 2

using namespace std;

int gen_hash_index(const string& s){
    int sum =0;
    for (char c : s){
        sum += (int)c;
    }
    return sum % TABLE_SIZE;
}
int main() {
    cout << GEN("536B9DFC93AF")<< endl;
    cout << sum_ascii("E1D2665B21EA") << endl;

    ifstream fin("lab-37-data.txt");

    if (!fin){
        cout << "Error opening file!" << endl;
        return 1;
    }
    string line;

    long long grand_total = 0;

    while (fin >> line){
        grand_total += sum_ascii(line);
    }
    cout << "Grand total ACII sum = " << grand_total << endl; 
    return 0;

    //milestone two
    
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
