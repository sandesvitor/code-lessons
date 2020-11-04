#include <iostream>
using namespace std;

int main(){
    // "string" is a class of namespace std
    // std::string
    string title = "Mr. ";
    string name("John");
    string end(10, '!');

    // since "string" is a class
    // we can access its attributes and methods with "."
    cout << name.size() << endl;
    cout << name.back() << endl;
    
    name += " Doe";
    name.append("???");
    cout << title + "";
    for (int i = 0; i < name.size(); i++){
        cout << name[i];
    }

    cout << endl << end << endl;

    return 0;
}