/*
1. 문제

UN은 사람 두명을 달로 보내려고 한다. 
그들은 서로 다른 국적을 가져야 한다. 
우주인의 ID는 0~N-1이다.

두 우주인의 ID 페어 리스트가 주어진다. 
각 페어는 동일 국가에서 온 우주인 ID로 이루어진다. 
얼마나 많은 우주인을 고를 수 있는지 구하시오. 

2. 예제
n = 4, a = [1,2],[2,3]
이 경우 우주인들의 국적 set은 [0], [1,2,3]이므로
[0,1],[0,2],[0,3] 세가지 경우가 가능하다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <stdlib.h>
#include <functional>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

void Union(int* group, int A, int B)
{
    int a = group[A];
    int b = group[B];
    while (a != group[a]) a = group[a];
    while (b != group[b]) b = group[b];

    if (a != b)
    {
        if (a > b) group[b] = a;
        else group[a] = b;
    }
}

bool Find(int* group, int A, int B)
{
    int a = group[A];
    int b = group[B];
    while (a != group[a]) a = group[a];
    while (b != group[b]) b = group[b];
    if (a == b) return true;
    return false;
}

long journeyToMoon(int n, vector<vector<int>> astronaut)
{
    int* group = new int[n];
    for (int i = 0; i < n; i++) 
        group[i] = i;

    vector<vector<int>>::iterator it = astronaut.begin();
    for (; it != astronaut.end(); it++)
        Union(group, (*it)[0], (*it)[1]);

    // TO-DO

    delete[] group;

    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
