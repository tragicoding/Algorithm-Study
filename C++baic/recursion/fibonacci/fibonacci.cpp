#include <iostream>

using namespace std;

int fibo( int n)
{
    //탈출조건
    if ( n < 3 )
    {
        return n; 
    }

    //로직
    //재귀호출
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    int number;
    cin >> number;
    cout << "The Fiponacci of " << number << "is " << fibo(number);

    return 0;
}