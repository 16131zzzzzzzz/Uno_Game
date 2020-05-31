//current finished;
#ifndef BASECLASSCARD_H
#define BASECLASSCARD_H

#include<iostream>
#include<string>

class Card {
public:
	Card(int = 0, int = 0);
	friend std::ostream& operator<< (std::ostream&, const Card&);
	std::string Translate()const;
	int getColor()const;
	int getNum()const;
	void setColor(int);
protected:
	int protected_card_color;//Ranging [0,4] 
	int protected_card_num;//Ranging [0,14]
};

#endif