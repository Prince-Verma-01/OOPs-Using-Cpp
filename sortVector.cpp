#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverseVector(vector<int> &vec, int n);
void sortVector(vector<int> &vec, int n);
void removeDuplicate(vector<int> &vec, int n);

int main()
{
    vector<int> vec;
    int n;
    cout << "Enter Number of elements You want to Enter :\n";
    cin >> n;
    
//  Taking User Input
    cout << "Enter Elements of the Vector : ";
    int input;
    for(int i = 0; i < n; i++){
        cin >> input;
        vec.push_back(input);
    }
    
    // reverseVector(vec, n);
    sortVector(vec, n);
    removeDuplicate(vec, n);
    
//  Printing Vector Elements 
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *(it) << "  ";
    }
    
    return 0;
}


// Utility Functions 
    void reverseVector(vector<int> &vec, int n){
        int temp;
        for(int i = 0; i < n/2; i++){
            temp = vec[i];
            vec[i] = vec[n- i - 1];
            vec[n - i - 1] = temp;
        }
    }
    
    void sortVector(vector<int> &vec, int n){
        int temp;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(vec[j] < vec[j + 1]){
                    temp = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = temp; 
                }
            }
        }
    }
    
    
    void removeDuplicate(vector<int> &vec, int n){
        for(int i = 0; i < vec.size() - 1;   ){
            if(vec[i] == vec[i + 1]){
                vec.erase(vec.begin() + i + 1);
            } else {
                i++;
            }
        }
    }
    
    
    
    