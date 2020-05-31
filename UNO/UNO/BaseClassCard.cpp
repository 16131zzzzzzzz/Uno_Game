#include<iostream>
#include<string>
#include"BaseClassCard.h"

using namespace std;

Card::Card(int input_cc, int input_cn) {
    if (input_cc < 5 && input_cc >= 0)  protected_card_color = input_cc;
    else protected_card_color = 0;
    if (input_cn < 15 && input_cn >= 0)protected_card_num = input_cn;
    else protected_card_num = 0;
}

 std::ostream& operator<<(std::ostream&output, const Card&card)
 {
     output << card.Translate();
     return output;
 }

 string Card::Translate()const {
     string temp;
     switch (protected_card_color) {
     case 0:
         temp += "Black ";
         break;
     case 1:
         temp += "Red ";
         break;
     case 2:
         temp += "Blue ";
         break;
     case 3:
         temp += "Green ";
         break;
     case 4:
         temp += "Yellow ";
         break;
     default:
         cout << "an invalid card number.";
     }
     switch (protected_card_num) {
     case 0:
         temp += '0';
         break;
     case 1:
         temp += '1';
         break;
     case 2:
         temp += '2';
         break;
     case 3:
         temp += '3';
         break;
     case 4:
         temp += '4';
         break;
     case 5:
         temp += '5';
         break;
     case 6:
         temp += '6';
         break;
     case 7 :
         temp += '7';
         break;
     case 8:
         temp += '8';
         break;
     case 9:
         temp += '9';
         break;
     case 10:
         temp += "STOP";
         break;
     case 11:
         temp += "Reverse";
         break;
     case 12:
         temp += "Two more cards!";
         break;
     case 13:
         temp += "trump card:Four more cards!";
         break;
     case 14:
         temp += "trump card: Color assigning.";
         break;
     default:
         temp += "CENSORED";
         break;
     }
     return temp;
 }

 int Card::getColor()const {
     return protected_card_color;
 }

 int Card::getNum()const {
     return protected_card_num;
 }

 void Card::setColor(int in_color) {
     if (in_color < 2 || in_color>5)protected_card_color = 1;
     else protected_card_color = in_color;
 }
