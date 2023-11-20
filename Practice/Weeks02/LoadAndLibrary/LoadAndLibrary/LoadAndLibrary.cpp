#define _CRT_SECURE_NO_WARNINGS
#include <bits.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <stdlib.h>
#include <functional>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

 /*

 모든 시민들이 도서관에 가는데 걸리는 최소 비용을 구해라
 1~n을 가진 n개의 도시가 있고 도시들은 연결되어 있지 않다.
 cities에 주어지는 도시들 사이에만 양방향 도로를 지을 수 있다.

 도시가 도서관을 포함하거나, 도로로 이동할 수 있는 경우
 해당 도시의 시민들이 도서관에 접근할 수 있다.

 q: 주어지는 문제의 수
 n: 주어지는 도시의 개수
 c_road: 도로 건설 비용
 c_lib: 도서관 건설 비용
 cities: 도로를 지을 수 있는 두 도시
 return: 최소 비용

 */

struct Node
{
    int idx = 0;
    vector<Node*> neighbor;
};

void BFS(bool* visited, Node* node, long& city, long& road)
{
    visited[node->idx] = 1;
    queue<Node*> Q;
    Q.push(node);

    while (!Q.empty())
    {
        Node* frontNode = Q.front();
        Q.pop();
        city++;

        vector<Node*>::iterator it = frontNode->neighbor.begin();
        for (; it < frontNode->neighbor.end(); it++)
        {
            if (visited[(*it)->idx] != 1)
            {
                visited[(*it)->idx] = 1;
                Q.push((*it));
                road++;
            }
        }
    }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
    Node* nodes = new Node[n];
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        nodes[i].idx = i;
        visited[i] = 0;
    }

    vector<vector<int>>::iterator it = cities.begin();
    for (; it != cities.end(); it++)
    {
        int u = (*it)[0];
        int v = (*it)[1];
        nodes[u - 1].neighbor.push_back(&nodes[v - 1]);
        nodes[v - 1].neighbor.push_back(&nodes[u - 1]);
    }

    long lib = 0;
    long road = 0;
    vector<int> cityCnt;
    vector<int> roadCnt;
    for (int i = 0; i < n; i++)
    {
        long citytmp = 0;
        long roadtmp = 0;
        if (visited[i] != 1)
        {
            BFS(visited, &nodes[i], citytmp, roadtmp);

            lib++;
            road += roadtmp;
            roadCnt.push_back(roadtmp);
            cityCnt.push_back(citytmp);
        }
    }
    long cost = lib * c_lib + road * c_road;

    for (long i = 0; i < roadCnt.size(); i++)
    {
        long roadCost = roadCnt[i] * c_road;
        long cityCost = (cityCnt[i] - 1) * c_lib;
        if (roadCost > cityCost)
        {
            cost += cityCost;
            cost -= roadCost;
        }
    }

    delete[] nodes;
    delete[] visited;
    return cost;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<long> results;
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);
        results.push_back(result);
        
        //fout << result << "\n";
    }

    for(int i = 0; i < results.size(); i++)
        ::cout << results[i] << "\n";

    //fout.close();

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
