/*
<1번>
1. 문제
2차원 스트링 배열로 된 로그 데이터 생성 함수를 개발한다.
로그는 날짜, 시간, 상태, 메시지를 포함한다. 
모든 로그는 도착 시간에 따라 ERROR, CRITICAL 상태를 가진다. 
날짜는 DD-MM-YYYY, 시간은 HH:MM의 포맷을 가진다. 
두 로그의 시간이 같으면 입력 순서대로 출력

2. 예제
input
01-01-2023 14:00 ERROR failed
01-01-2023 15:00 INFO established
01-01-2023 01:30 ERROR failed

output
01-01-2023 01:30 ERROR failed
01-01-2023 14:00 ERROR failed

ERROR 로그만, 도착 시간을 기준으로 정렬

3. 함수 상세
string[][4] extractErrorLogs (string logs[n][4])
정렬되지 않는 정보를 입력으로 받는다. 

4. 제약 조건
1 <= 로그 크기 <= 10^5
시간, 날짜는 뭐 대충...
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
struct Log
{
    int year;
    int month;
    int day;
    int hour;
    int min;
};

struct cmp 
{
    bool operator() (Log* const& n1, Log* const& n2) const
    {
        if (n1->year == n2->year)
        {
            if (n1->month == n2->month)
            {
                if (n1->day == n2->day)
                {
                    if (n1->hour == n2->hour)
                    {
                        if (n1->min == n2->min)
                        {
                            return false;
                        }
                        return n1->min < n2->min;
                    }
                    return n1->hour < n2->hour;
                }
                return n1->day < n2->day;
            }
            return n1->month < n2->month;
        }
        return n1->year < n2->year;
    }
};

string** extractErrorLogs(string* logs[4])
{
    int n = 0;
    for (int i = 0; i < n; i++)
    {

    }
}

int main()
{
    
}

