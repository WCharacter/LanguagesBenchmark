#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>
#include <tuple>
#include <chrono>
#include <algorithm>

using namespace std;

struct test_object
{
	string name;
	double amount;
	test_object(string&& name_, double am) :
		name{move(name_)},
		amount{am}
	{}
};

int main()
{
	const int tests_amount = 10;
	uint64_t time_total = 0.;

	for (int i = 0; i < tests_amount; ++i)
	{
		auto beg = chrono::high_resolution_clock::now();
		vector<test_object> vec;
		vec.reserve(10'000'000);

		for (int i = 0; i < vec.capacity(); ++i)
		{
			vec.emplace_back(to_string(i), i);
		}

		double sum = 0;
		for (const auto& i : vec)
		{
			sum += i.amount;
		}

		auto end = chrono::high_resolution_clock::now();
		cout << setprecision(16) << sum << '\n';
		uint64_t elapsed = chrono::duration_cast<chrono::milliseconds>(end - beg).count();

		time_total += elapsed;
		cout << "Elapsed " << elapsed << " ms." << '\n';
	}
	double mean = static_cast<double>(time_total) / tests_amount;
	cout << "Mean: " << mean << " ms.";
	return 0;
}