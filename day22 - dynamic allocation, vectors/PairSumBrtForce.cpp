#include <iostream>
#include <vector>

using namespace std;

vector<int> pairSum(vector<int> numbers, int target) {
    vector<int> ans;
    for(int i=0; i<numbers.size(); i++) {
        for(int j=i+1; j<numbers.size(); j++) {
            if(numbers[i] + numbers[j] == target) {
                ans = {i, j};
                return ans;
            }
        }
    }
    return ans;
}

int main() {
    
    vector<int> numbers = {2, 7, 11, 15}; 
    
    int target = 9;
    
    vector<int> ans = pairSum(numbers, target);

    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<", ";
    }
    cout<<endl;

    return 0;
}