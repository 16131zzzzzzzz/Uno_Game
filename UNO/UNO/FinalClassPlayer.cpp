#include"FinalClassPlayer.h"
#include"FinalCardPile.h"
#include<iostream>
#include<string>
using namespace std;

Player::Player() :name("ZHJ"), cards(7) {
}

Player::Player(string in_name) : name(in_name), cards(7) {
}

ostream& operator<<(ostream& in_output,const Player& in_player){
	in_output << in_player.name << endl;
	return in_output;
	}

void Player::getCards() {
	cout << cards;
}