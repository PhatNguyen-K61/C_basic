#include <bits/stdc++.h>
using namespace std; 
int main(int argc, char* argv[]){
    if (argc > 1) {
        cout << "argv[1] = " << argv[1] << endl; 
    } else {
        cout << "No file name entered. Exiting...";
        return -1;
    }
    ifstream infile(argv[1]); //open file
    if (infile.is_open() && infile.good()) {
        cout << "File is now open!"<<endl<<"Contains:"<<endl;
        string line = "";
        while (getline(infile, line)){
            _sleep(50);
            cout << line << endl;
        }
    } else {
        cout << "Failed to open file..";
    }
    return 0;
}