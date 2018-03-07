#include <iostream>

#include "gtest/gtest.h"

#include "StableMatching.h"
using namespace std;

TEST(StableMatchingTest, Test1) {
	int menPref[2][2] = { { 1, 0 }, { 0, 1 } };
	int womenPref[2][2] = { { 0, 1 }, { 1, 0 } };
	StableMatching<2U> sm(menPref, womenPref);
	sm.getStablePairs();
	ostringstream oss;
	oss << sm;
	string testOutput = "woman: 0 man: 1\nwoman: 1 man: 0\n";
	ASSERT_STREQ(oss.str().c_str(), testOutput.c_str());
}

TEST(StableMatchingTest, Test2) {
	StableMatching<2> sm;
	string prefs = "1 0 0 1 0 1 1 0";
	istringstream iss(prefs);
	iss >> sm;
	sm.getStablePairs();
	ostringstream oss;
	oss << sm;
	string testOutput = "woman: 0 man: 1\nwoman: 1 man: 0\n";
	ASSERT_STREQ(oss.str().c_str(), testOutput.c_str());
}

TEST(StableMatchingTest, Test3) {
	int menPref[3][3] = { { 0, 1, 2 }, { 1, 0, 2 }, { 0, 1, 2 } };
	int womenPref[3][3] = { { 1, 0, 2 }, { 0, 1, 2 }, { 0, 1, 2 } };
	StableMatching<3U> sm(menPref, womenPref);
	sm.getStablePairs();
	ostringstream oss;
	oss << sm;
	string testOutput = "woman: 0 man: 0\nwoman: 1 man: 1\nwoman: 2 man: 2\n";
	ASSERT_STREQ(oss.str().c_str(), testOutput.c_str());
}

TEST(StableMatchingTest, Test4) {
	StableMatching<3> sm;
	string prefs = "0 1 2 1 0 2 0 1 2 1 0 2 0 1 2 0 1 2";
	istringstream iss(prefs);
	iss >> sm;
	sm.getStablePairs();
	ostringstream oss;
	oss << sm;
	string testOutput = "woman: 0 man: 0\nwoman: 1 man: 1\nwoman: 2 man: 2\n";
	ASSERT_STREQ(oss.str().c_str(), testOutput.c_str());
}

