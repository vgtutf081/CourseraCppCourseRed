//============================================================================
// Name        : airplane_tickets.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "airline_ticket.h"
#include "test_runner.h"

#include <tuple>
#include <iomanip>
#include <algorithm>
#include <numeric>
using namespace std;

#define SORT_BY(field)												\
	[](const AirlineTicket & lhs, const AirlineTicket & rhs){		\
		return lhs.field < rhs.field;								\
	}

	tuple<int, int, int> getDate (const Date & d){
		return make_tuple(d.year, d.month, d.day);
	}

	pair<int, int> getTime(const Time & t){
		return make_pair(t.hours, t.minutes);
	}

	bool operator < (const Date & lhs, const Date & rhs){
		return getDate(lhs) < getDate(rhs);
	}

	bool operator == (const Date & lhs, const Date & rhs){
		return getDate(lhs) == getDate(rhs);
	}

	bool operator < (const Time & lhs, const Time & rhs){
		return getTime(lhs) < getTime(rhs);
	}

	bool operator == (const Time & lhs, const Time & rhs){
		return getTime(lhs) == getTime(rhs);
	}

	ostream& operator << (ostream &os, const Date & d){
		os << setw(4) << setfill('0') << d.year << '-'
		   << setw(2) << setfill('0') << d.month << '-'
		   << setw(2) << setfill('0') << d.day;
		return os;
	}

	ostream& operator << (ostream &os, const Time & t){
		os << setw(2) << setfill('0') << t.hours << '-'
		   << setw(2) << setfill('0') << t.minutes;
		return os;
	}


void TestSortBy() {
  vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  sort(begin(tixs), end(tixs), SORT_BY(price));
  ASSERT_EQUAL(tixs.front().price, 1200);
  ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
  ASSERT_EQUAL(tixs.front().from, "AER");
  ASSERT_EQUAL(tixs.back().from, "VKO");

  sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
  ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
  ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSortBy);
}
