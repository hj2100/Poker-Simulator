/*
MIT License

Copyright (c) 2016 Andrey Lopukhov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef data_hpp
#define data_hpp

#include <string>
#include <vector>

using namespace std;

struct Colors {
	int spades = 0;
	int hearts = 0;
	int diams = 0;
	int club = 0;
};

struct ColorCards {
	vector<int> spadesCards;
	vector<int> heartsCards;
	vector<int> diamsCards;
	vector<int> clubCards;
};

struct Card {
	char suit;
	char num;
};

struct Score {
	unsigned long nothing = 0;
	unsigned long pair = 0;
	unsigned long twopair = 0;
	unsigned long three = 0;
	unsigned long straight = 0;
	unsigned long flush = 0;
	unsigned long full = 0;
	unsigned long four = 0;
	unsigned long straightflush = 0;
	unsigned long royal = 0;
	unsigned long long getTotal() {
		return nothing + pair + twopair + three + straight + flush + full + four + straightflush + royal;
	}
	string returnString() {
		return to_string(nothing) + ";" + to_string(pair)
			+ ";" + to_string(twopair) + ";" + to_string(three)
			+ ";" + to_string(straight) + ";" + to_string(flush)
			+ ";" + to_string(full) + ";" + to_string(four)
			+ ";" + to_string(straightflush) + ";" + to_string(royal) + ";" + to_string(getTotal());
	}
	void clear() {
		nothing = 0;
		pair = 0;
		twopair = 0;
		three = 0;
		straight = 0;
		flush = 0;
		full = 0;
		four = 0;
		straightflush = 0;
		royal = 0;
	}
};

enum class Combo { Nothing, Pair, TwoPairs, ThreeKind, Straight, Flush, Full, FourKind, StraightFlush, RoyalFlush };

#endif
