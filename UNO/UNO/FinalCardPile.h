//Since stack lacks some essential funtion, I constructed it with vector.
//Current finished.
#ifndef FINALCARDPILE_H
#define FINALCARDPILE_H
#include"BaseClassCard.h"
#include<vector>

class CardPile {
public :
	CardPile();
	CardPile(int);
	friend std::ostream& operator<<(std::ostream&, CardPile&);
	int getNum();
	bool isEmpty();
	void push(Card);
	Card pop();
	Card pop(int);
	Card getCard(int);

private:
	std::vector<Card> pile;
};
#endif