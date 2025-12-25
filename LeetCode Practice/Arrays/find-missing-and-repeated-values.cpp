#include<iostream>
#include<vector>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

    vector<int> ans;


    return ans;

}


int main() {

    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};

    int add = 0;
    
    for(const auto& i: grid) {
        add += grid[i].size();
    }

    vector<int> ans = findMissingAndRepeatedValues(grid);

    for(int each: ans) {
        cout<<each<<", ";
    }

    cout<<endl;

    return 0;
}
