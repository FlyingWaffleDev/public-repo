// ====================
// FlyingWaffle
// 3/3/2020
// Driver for list tests.
// Compile with:
// "g++ testDriver -o testDriver"
// Run with:
// "./testDriver"
// ====================

#include <iostream>
#include <iomanip>
#include <climits>
#include <chrono>
#include <random>
#include <string>

#include "sllist.h"
#include "dllist.h"
#include "skiplist.h"
#include "../Random.h"

using namespace std;

    int NUMBER_OF_ROUNDS = 10000;

    string operations[] = {"append","prepend","first","last","removefirst","removelast"};
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

void testLists();

int main() {
	auto start = chrono::steady_clock::now();
    int x = 5;
    //cin >> x;
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end-start).count() << endl;

    testLists();

	return 0;
}

void testLists() {
    Random random;
    SLList<int> sllist;
    DLList<int> dllist;
    long sllistTimes[6] = {0};
    long dllistTimes[6] = {0};
    double counts[6] = {0};
    cout << "Testing Lists" << endl;

    // Add values
    for (int i = 0; i < NUMBER_OF_ROUNDS; i++) {
        int x = random.nextInt();
        auto start = chrono::steady_clock::now();
        sllist.Append(x);
        auto end = chrono::steady_clock::now();
        sllistTimes[0] += chrono::duration_cast<chrono::microseconds>(end-start).count();

        start = chrono::steady_clock::now();
        dllist.Append(x);
        end = chrono::steady_clock::now();
        dllistTimes[0] += chrono::duration_cast<chrono::microseconds>(end-start).count();

        counts[0]++;
    }

    for (int i = 0; i < NUMBER_OF_ROUNDS; i++) {
        int x = random.nextInt();
        auto start = chrono::steady_clock::now();
        sllist.Prepend(x);
        auto end = chrono::steady_clock::now();
        sllistTimes[1] += chrono::duration_cast<chrono::microseconds>(end-start).count();
        counts[1]++;
    }

    for (int i = 0; i < NUMBER_OF_ROUNDS; i++) {
        auto start = chrono::steady_clock::now();
        sllist.RemoveLast();
        auto end = chrono::steady_clock::now();
        sllistTimes[5] += chrono::duration_cast<chrono::microseconds>(end-start).count();
        counts[5]++;
    }

    for (int i = 0; i < NUMBER_OF_ROUNDS; i++) {
        auto start = chrono::steady_clock::now();
        sllist.RemoveFirst();
        auto end = chrono::steady_clock::now();
        sllistTimes[4] += chrono::duration_cast<chrono::microseconds>(end-start).count();
        counts[4]++;
    }

    cout << "Time analysis (microseconds per operation)" << endl;
    cout << setw(12) << "Operation" << setw(10) << "SLList" << setw(10) << "DLList" << endl;
    for (int i = 0; i < size(sllistTimes); i++) {
        //System.out.println(String.format("%-10s%15d%15d", queueOperations[i], (long) (10E6 * slowTimes[i]/counts[i])));
        cout << right << setw(12) << operations[i] << "     " << left << setw(10) << sllistTimes[i]/counts[i] << setw(10) << dllistTimes[i]/counts[i]<< endl;
    }
}