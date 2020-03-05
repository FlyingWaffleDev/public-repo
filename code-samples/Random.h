// ====================
// FlyingWaffle
// 3/4/2020
// Random Generator
// ====================

#include <random>
#include <climits>

#ifndef __RANDOM__
#define __RANDOM__

std::mt19937 seeded_engine() {
	std::random_device rd;
	std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
	return std::mt19937(seed);
}

class Random {
private:
	std::mt19937 eng = seeded_engine();
public:
	auto operator() (int a, int b) {
		std::uniform_int_distribution<int> dist(a, b);
		return dist(eng);
	}

	int nextInt() {
		std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
		return dist(eng);
	}
};

#endif __RANDOM__
