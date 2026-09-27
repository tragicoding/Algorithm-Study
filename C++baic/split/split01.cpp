#include <string>
#include <iostream>
#include <vector>

using namespace std;

void split(const string& str,string parser )
{
    auto start = 0;
    auto end = str.find(parser);
    vector<string> result; 
    while ( end != string::npos )
    {
        result.push_back(str.substr(start,end - start));
        start = end + parser.size();//parser 길이가 길 수도 있기 때문 
        end = str.find(parser , start); //다음 loop의 시작점
        //모든 loop의 시작점을 방금 마친 end로 하기 위해
    }

    result.push_back(str.substr(start,end-start)); //맨 마지막은 parsing 대상이 아니라서 직접 추가

    for (string i : result)
    {
    cout << i << " ";
    }
    cout << " /Original : " << str;
}

int main()
{
    string input;
    cin >> input;
    string parser;
    cin >> parser;

    split(input,parser);

    return 0; 
}