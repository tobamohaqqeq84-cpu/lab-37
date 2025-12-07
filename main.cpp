#include <iostream>
using namespace std;

int sum_ascii(const std::string &s){
    int total =0;
    for (char c : s){
        total +=  static_cast<unsigned char>(c);
    }
    return total;
}
int main() {
    cout << sum_ascii("536B9DFC93AF")<< endl;
    cout << sum_ascii("E1D2665B21EA") << endl;
    //milestone one 
    
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
