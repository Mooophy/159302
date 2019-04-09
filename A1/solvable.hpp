#include <iostream>
#include <string>
#include <vector>

inline bool get_xor(bool a, bool b)
{
	return !a != !b;
}

struct Combination
{
	Combination() = default;

	Combination(char i, char j, std::string const& s, std::string const& g)
		:i(i), j(j)
	{
		if (j < i)
		{
			std::swap(i, j);
		}

		auto is = s.find(i);
		auto js = s.find(j);
		auto ig = g.find(i);
		auto jg = g.find(j);

		is_inversion = get_xor(is > js, ig > jg);
	}

	char i, j;
	bool is_inversion;
};

struct Solvable
{
	Solvable() = default;

	Solvable(std::string const& s, std::string const& g) :
		s(s),
		g(g),
		combinations(std::vector<Combination>{}),
		count_of_inversions(0)
	{
		auto all = std::string("12345678");

		for (auto i = 0; i != all.size() - 1; ++i)
		{
			for (auto j = i + 1; j != all.size(); ++j)
			{
				auto c = Combination{ all[i], all[j], s, g };
				combinations.push_back(c);
			}
		}

		for (auto c : combinations)
		{
			count_of_inversions += c.is_inversion ? 1 : 0;
		}
	}

	std::vector<Combination> combinations;
	std::string s, g;
	std::size_t count_of_inversions;

	bool is()
	{
		return count_of_inversions % 2 == 0;
	}
};