#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,r;
vector<int> arr;
vector<int> selected;
int count = 0;

void loop(int current_row, int start) //loop(0,0)부터 시작
{
    if (current_row == r) //r-1 까지만 도니까
    {
        for ( int x : selected)
        { cout << x << " ";}
        cout << "\n";
        
        return;
    }

    for (int i = start; i < n; i++)
    {
        selected.push_back(arr[i]);
        loop(current_row + 1 , i + 1);
        selected.pop_back();
    }

}


int main()
{
    arr = {0,1,2,3,4};
    n = arr.size();
    r = 3;
    loop(0,0);
    return 0;
}