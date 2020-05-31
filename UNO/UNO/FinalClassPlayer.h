#ifndef FINALCLASSPLAYER_H
#define FINALCLASSPLAYER_H

#include<string>
#include<iostream>
#include"FinalCardPile.h"

class Player final {
public:
	Player();
	Player(std::string);
	friend std::ostream& operator<<(std::ostream&, const Player&);
	void getCards();
	CardPile cards;
private:
	std::string name;
};

#endif