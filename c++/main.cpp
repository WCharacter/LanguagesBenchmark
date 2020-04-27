#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>
#include <tuple>
#include <chrono>
#include <algorithm>

using namespace std;

int main()
{
	const int tests_amount = 10;
	uint64_t time_total = 0.;

	for (int i = 0; i < tests_amount; ++i)
	{
		auto beg = chrono::high_resolution_clock::now();
		vector<tuple<string, double>> vec(10'000'000);
		double cnt = 0;
		generate(vec.begin(), vec.end(),
			[&cnt]()
			{
				return tuple<string, double>{ to_string(cnt), cnt++ };
			});

		double sum = 0;
		for (const auto& i : vec)
		{
			sum += get<double>(i);
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