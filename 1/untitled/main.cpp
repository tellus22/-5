#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
    ifstream input("main.txt");
    char buffer[1024];
    while(input.getline(buffer,1024)) {
        if(strstr(buffer, "https")){
            cout << buffer << endl;
        } else if(strstr(buffer, "http")){
            cout << buffer << endl;
        }
    }
    cin >> buffer;
    return 0;
}
