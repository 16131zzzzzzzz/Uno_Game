#include"FinalCardPile.h"
#include<vector>
#include<iostream>
#include<ctime>

using namespace std;

CardPile::CardPile() {
	pile.reserve(108);
	
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				pile.push_back(Card(i,j));
			}
		}
		pile.push_back(Card(i, 0));
	}

	for (int i = 1; i < 5; i++)
	{
		for (int j = 10; j < 13; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				pile.push_back(Card(i, j));
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		pile.push_back(Card(0, 13));
		pile.push_back(Card(0, 14));
	}

	srand(static_cast<unsigned int>(time(NULL)));
	int i = 108;
	while (i > 1)
	{
		i--;
		int j = rand() % (i + 1);
		swap(pile[i], pile[j]);
	}
}

CardPile::CardPile(int input_num) {
	pile.reserve(input_num);
}


std::ostream& operator<<(std::ostream&in_output, CardPile&in_pile)
{
	in_output << "Below are your cards:\n";
	for (unsigned int i = 0; i < in_pile.pile.size(); i++) {
		in_output << i + 1 << "." << in_pile.pile[i].Translate() << endl;
	}
	return in_output;
}

int CardPile::getNum() {
	return pile.size();
}

bool CardPile::isEmpty() {
	return pile.size() == 0;
}

void CardPile::push(Card in_card) {
	pile.push_back(in_card);
}

Card CardPile::pop() {
	Card temp = pile.back();
	pile.pop_back();
	return temp;
}

Card CardPile::pop(int in_input_card) {
	Card temp = pile[in_input_card];
	vector<Card>::iterator Itr =pile.begin()+in_input_card;
	pile.erase(Itr);
	return temp;
}

Card CardPile::getCard(int input_num) {
	return pile[input_num];
}
