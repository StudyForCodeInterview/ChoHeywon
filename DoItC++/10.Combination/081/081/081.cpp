#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

long long val;
long long input[21];
long long factorials[21];
bool visited[21] = { false, };

int main()
{
    int n, q, k;
    scanf("%d", &n);
    scanf("%d", &q);

    factorials[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        factorials[i] = factorials[i - 1] * i;
    }

    if (q == 1)
    {
        scanf("%lld", &val);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1, idx = 1; j <= n; j++)
            {
                if (visited[j] == true) continue;

                if (val <= (idx * factorials[n - i]))
                {
                    val -= ((idx - 1) * factorials[n - i]);
                    input[i] = j;
                    visited[j] = true;
                    break;
                }
                idx++;               
            }
        }

        for (int i = 1; i <= n; i++)
        {
            ::printf("%lld ", input[i]);
        }
    }
    else
    {
        val = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &input[i]);

            int idx = 0;
            for (int j = 1; j < input[i]; j++)
            {
                if (visited[j] == false) idx++;
            }
            val += (idx * factorials[n - i]);
            visited[input[i]] = true;
        }

        ::printf("%lld\n", val);
    }
}
