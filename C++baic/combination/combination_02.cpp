#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {0,1,2,3,4};
    vector<int> box;
    int n = arr.size();
    int r = 3;
    for ( int i = 0 ; i < n ; i++)
    {
        box.push_back(arr[i]);
        for ( int j = i + 1 ; j < n ; j++)
        {
            box.push_back(arr[j]);
            for ( int k = j + 1 ; k < n ; k++)
            {
                box.push_back(arr[k]);

                //다 차면 cout
                for ( int x : box) { cout << x << " ";} cout << endl;
                box.pop_back();
            }
            box.pop_back();
        }
        box.pop_back();
    }


    return 0;
}