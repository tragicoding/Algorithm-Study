#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> box;
int r;

void combination(int current)
{
    int n = arr.size();
    if ( box.size() == r )
    {
        for (int x : box)
        {
            cout << x;
        }
        cout << "\n";
        return;
    }

    for (int i = current; i < n ; i++)
    {
        box.push_back(arr[i]);
        combination(i + 1);
        box.pop_back();
    }
}

int main()
{
    arr = {0,1,2,3,4,5};
    r = 3;
    combination(0);

    return 0;

}