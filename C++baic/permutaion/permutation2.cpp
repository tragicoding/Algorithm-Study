#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {1,2,3};
    do{
        for (int i : a)
        {
            cout << i << " ";
        }
        cout << "\n";
    }while(next_permutation(a,a+3)); //& 안써도 내부적으로 인덱스 접근은 포인터이다. 

    return 0;
}