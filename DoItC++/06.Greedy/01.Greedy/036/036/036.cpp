#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> v_str;
    vector<int> v_int;
    string input;
    cin >> input;

    int prev = 0;
    int cur = input.find('-');
    while (cur != string::npos) 
    {
        string sub = input.substr(prev, cur - prev);
        v_str.push_back(sub);
        prev = cur + 1;
        cur = input.find('-', prev);
    }
    v_str.push_back(input.substr(prev, cur - prev));

    int result = 0;
    v_int.resize(v_str.size(), 0);
    for (int i = 0; i < v_str.size(); i++)
    {
        string data = v_str[i];
        prev = 0;
        cur = data.find('+');
        while (cur != string::npos) 
        {
            string sub = data.substr(prev, cur - prev);
            v_int[i] += stoi(sub);
            prev = cur + 1;
            cur = data.find('+', prev);
        }
        v_int[i] += stoi(data.substr(prev, cur - prev));

        if (i == 0) result += v_int[i];
        else result -= v_int[i];
    }

    ::printf("%d", result);
    return 0;
}