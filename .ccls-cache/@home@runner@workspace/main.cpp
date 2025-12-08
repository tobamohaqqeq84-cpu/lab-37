//Toba Mohaqqeq
//COMSC-210
//lab -37

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream> 
#include <limits>
#include <algorithm>

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

bool search_key(const map<int, list<string>>& hash_table, const string& key){
    int index = gen_hash_index(key);
    auto it = hash_table.find(index);

    if (it == hash_table.end()){
        return false;
    }
    const list< string>& bucket = it->second;
    for (const string& s : bucket){
        if (s == key){
            return true;
        }
}
    return false;
    }

void add_key(map<int, list<string>>& hash_table, const string& key){
    if (search_key(hash_table,key)){
        cout << "key "<< key << " already exists in the table." << endl;
        return;
    }
    int index = gen_hash_index(key);
    hash_table[index].push_back(key);
    cout << "key " << key << " added to the table at index " << index << endl;
}

bool remove_key(map<int, list<string>>& hash_table, const string& key)
{
    int index = gen_hash_index(key);
    auto it = hash_table.find(index);

    if (it == hash_table.end()){
        return false;
    }
    list<string>& bucket = it->second;
    for (auto lit = bucket.begin(); lit != bucket.end(); ++lit){
        if (*lit == key){
            bucket.erase(lit);
        if(bucket.empty()){
            hash_table.erase(it);
        }
return true;
        
    }
}
return false;
}

bool modify_key( map<int, list<string>>& hash_table, const string& old_key, const string& new_key){
    if (!search_key(hash_table, old_key)){
        cout << "key " << old_key << " not found in the table." << endl;
        return false;
    }
    if (search_key(hash_table, new_key)){
        cout << "key " << new_key << " already exists in the table." << endl;
        return false;
    }
    remove_key(hash_table, old_key);

    int new_index = gen_hash_index(new_key);
    hash_table[new_index].push_back(new_key);
    
    cout << "key " << old_key << " modified to " << new_key << " at index " << new_index << endl;
return true;
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
            
            case 2: {
                string key;
            cout <<"Enter key to search for: ";
                cin >> key;

                if (search_key(hash_table, key)){
                    int index = gen_hash_index(key);
                    cout<< "key " << key << " found at index "<< index << endl;
                     }else{
                     cout << "key " << key << " not found." << endl;
                        }//3
             break;
    }
            
            case 3:{
                string key;
                cout << "Enter key to add: ";
                cin >> key;
                add_key(hash_table, key);
             break;
            }
            
            case 4:{
                string key;
                cout << "Enter key to remove: ";
                cin >> key;
                if (remove_key(hash_table, key)){
                    cout << "key " << key << " removed from the table." << endl;
                }else{
                    cout << "key " << key << " not found in the table." << endl;
                }
             break;
            }

            case 5:{
                string old_key, new_key;
                cout << "Enter key to modify: ";
                cin >> old_key;
                cout << "Enter new key: ";
                cin >> new_key;

                modify_key(hash_table, old_key, new_key);
             break;

            }
            case 6:
            cout << "Exiting program." << endl;
            break;

            default:
            cout << "Invalid choice. Please try again." << endl;
        }
        }while (choice!=6);
    return 0;
}      
            
    