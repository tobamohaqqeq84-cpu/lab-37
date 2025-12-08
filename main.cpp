//Toba Mohaqqeq
//COMSC-210
//lab -37

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream> 
#include <limits>

using namespace std;

const int TABLE_SIZE = 97;

int gen_hash_index(const string& s){
    int sum =0;
    for (char c : s){
        sum += static_cast<int> (c);
    }
    return sum % TABLE_SIZE;
}

void print_first_100(const map<int, list<string>>& hash_table){
    int shown = 0;
    for (const auto& entry : hash_table){
        cout << "Index " << entry.first << ": ";
        for (const string& s : entry.second){
            cout << s << " ";
        }
        cout << endl;
        shown++;
        if (shown == 100){
            break;
        }
    }
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

    int choice = 0;
    do{
        cout << "\n****Hash Table Menu****\n";
        cout << "1. Print first 100 entries\n";
        cout << "2. Search for a key\n";
        cout << "3. Add a key\n"; 
        cout << "4. Remove a key\n";
        cout << "5. Modify a key\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(!cin ){
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        switch(choice){
            case 1:
                print_first_100(hash_table);
                break;
            case 2: 
            cout <<"NY";
             break;

            case 3:
            cout <<"NY";
             break;

            case 4:
            cout <<"NY";
             break;

            case 5:
            cout <<"NY";
             break;

            case 6:
            cout << "Exiting program." << endl;
            break;

            default:
            cout << "Invalid choice. Please try again." << endl;
        }
        }while (choice!=6);
    return 0;
}      
            
    