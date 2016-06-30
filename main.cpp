#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

typedef __int64 value_type;
typedef int count_type;

inline value_type getMax(const value_type &lhs, const value_type &rhs)
{
	return lhs > rhs ? lhs : rhs;
}

bool can(vector<value_type> &data, value_type result, count_type K)
{
	if (result == 0)
	{
		return true;
	}

	value_type temp = result;
	count_type count = 0;
	vector<value_type>::iterator vi;

	do
	{
		vi = upper_bound(data.begin(), data.end(), temp, greater<value_type>());
		count += vi - data.begin();
		temp += result;
	} while (vi != data.begin());

	return (count >= K);
}

int main()
{
	count_type N, K;
	cin >> N >> K;

	vector<value_type> sorted_input;		// 降序
	sorted_input.reserve(N);

	value_type left = 0, right = 0;

	double temp_f;
	for (value_type i = 0; i < N; ++i)
	{
		cin >> temp_f;
		sorted_input.push_back((value_type) ((temp_f + 0.005) * 100.0));
		right = getMax(sorted_input[i], right);
	}

	sort(sorted_input.begin(), sorted_input.end(), greater<value_type>());

	while (left <= right)
	{
		value_type mid = (left + right) / 2;
		if (can(sorted_input, mid, K))
			left = mid + 1;
		else
			right = mid - 1;
	}

	printf("%.2lf", (float)right / 100.f);
	return 0;
}
