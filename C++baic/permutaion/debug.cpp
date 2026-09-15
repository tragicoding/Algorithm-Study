#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {10,50,30,60,20};
    sort(vec.begin(),vec.end());
    do{
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << "\n";
    }while(next_permutation(vec.begin(),vec.end()));

}