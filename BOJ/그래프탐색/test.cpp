// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> nodes;

int main()
{
    // Write C++ code here

    // for(int i=0; i< )
    vector<int> tmp = {1, 2};
    vector<int> tmp2 = {3, 4};
    nodes.push_back(tmp);
    nodes.push_back(tmp2);
    // cout << nodes.size();
    // cout << nodes[0];
    // 접근 불가능
    cout << nodes[1].size() << endl;
    cout << nodes[1][1] << endl;
    // 접근 가능
}