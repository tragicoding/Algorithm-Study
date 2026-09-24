#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> arr;
    arr = {0,1,2,3,4};
    int n = arr.size();
    for ( int i = 0 ; i < n ; i ++)
    {
        for ( int j = i + 1; j < n ; j ++)
        {
            for ( int k = j + 1 ; k < n ; k++)
            {
                cout << i << " " << j << " " << k << endl;
            }
        }
    }
    return 0;
}