#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    
    string temp;
    
    
    for (int i = 0; i<my_str.size(); i+=n){
        answer.push_back(my_str.substr(i, n));
    }
    
    
    return answer;
}