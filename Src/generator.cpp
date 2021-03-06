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

#include "generator.hpp"

vector<Card> Generator::rollTable(int maxRandom, int numberOfCards) {

	playerCards.clear();
	rollsResult.clear();

	for (auto i = 0; i < numberOfCards; i++) {

	rollAgain:

		auto roll = rand() % maxRandom;

		if (find(begin(rollsResult), end(rollsResult), roll) != end(rollsResult)) {
			goto rollAgain;
		}

		rollsResult.push_back(roll);
	}

	for (auto i = 0; i < numberOfCards; i++) {
		playerCards.push_back(deck[rollsResult.at(i)]);
	}

	return playerCards;
}

void Generator::createDeck() {

	deck.clear();

	Card card;

	for (char suit = 0; suit < 4; suit++) {
		for (char num = 0; num < 13; num++) {

			card = { suit };
			card.num = num;

			deck.push_back(card);
		}
	}
}
