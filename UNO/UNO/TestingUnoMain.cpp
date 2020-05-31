#include"BaseClassCard.h"
#include"FinalCardPile.h"
#include"FinalClassPlayer.h"
#include<iostream>
#include<ctime>
#include<string>
#include <SFML/Graphics.hpp>
using namespace std;

Player PlayerPile[4];
CardPile Pile;
CardPile* ptrPile;
Card frontcard;
int flag = 0;
bool order = 1;
int outcardnum;
Card outcard;

int flagModify(int input_flag)
{
    if (input_flag == -2) return 2;
    if (input_flag == -1) return 3;
    if (input_flag == 4) return 0;
    if (input_flag == 5) return 1;
    return input_flag;
}

void moveflag(int step)
{
    order ? flag += step : flag -= step;
    flag = flagModify(flag);
}

bool gameState()
{
    bool endgame = 0;
    for (int i = 0; i < 4; i++)
    {
        if (PlayerPile[i].cards.isEmpty())
        {
            endgame = 1;
            cout << "Player" << i + 1 << " won!!!";
            return 0;
        }
        
    }
    return 1;
}

void giveCard(int input_num) {
    PlayerPile[input_num].cards.push((*ptrPile).pop());
}

bool judgeCard()
{
    return frontcard.getColor() == PlayerPile[flag].cards.getCard(outcardnum).getColor() || frontcard.getNum() == PlayerPile[flag].cards.getCard(outcardnum).getNum() || PlayerPile[flag].cards.getCard(outcardnum).getColor() == 0;
}

void action() {
    int step = 1;
    if (outcard.getNum() == 14) {
        int temp;
        cout << "Please select the color you want to assigned to the next card.(enter the number before the color)\n";
        cout << "1.Red   2.Blue  3.Green  4.Yellow\nWARNING:any number invalid is considered as Red";
        cin >> temp;
        outcard.setColor(temp);
    }
    if (outcard.getNum() == 13) {
        for (int x = 0; x < 4; x++)giveCard(flag + 1);
    }
    if (outcard.getNum() == 12) {
        for (int x = 0; x < 2; x++)giveCard(flag + 1);
    }
    if (outcard.getNum() == 11) {
        order = !order;
    }
    if (outcard.getNum() == 10) {
        cout << "next player is passed." << endl;
        step += 1;
    }
    frontcard = outcard;
    moveflag(step);
}

int windowx = 1440;
int windowy = 840;

sf::RenderWindow window(sf::VideoMode(windowx, windowy), "Uno Game!", sf::Style::Close | sf::Style::Resize);

int guiTranx(Card input_card)
{
    int input_color = input_card.getColor();
    int input_num = input_card.getNum();

    if (input_color == 0)
    {
        return 13;
    }
    else
    {
        return input_num;
    }
}

int guiTrany(Card input_card)
{
    int input_color = input_card.getColor();
    int input_num = input_card.getNum();

    if (input_num == 13)
    {
        return 4;
    }
    if (input_num == 14)
    {
        return 0;
    }
    switch (input_color) {
    case 1:
        return 0;
    case 2:
        return 3;
    case 3:
        return 2;
    case 4:
        return 1;
    }
}

void displayOthers()
{
    int flagbefore = flagModify(flag - 1);
    int flagafter = flagModify(flag + 1);
    int flagopp = flagModify(flag + 2);
    CardPile before = PlayerPile[flagbefore].cards;
    CardPile after = PlayerPile[flagafter].cards;
    CardPile opp = PlayerPile[flagopp].cards;

    float halfx = windowx / 2 - (before.getNum() * 85 - (before.getNum() - 1) * 35) / 2;
    float halfy = windowy / 2 - 64;

    sf::RectangleShape card(sf::Vector2f(85.0f, 128.0f));
    sf::Texture cardTexture;
    cardTexture.loadFromFile("Resource/cardback.png");
    card.setTexture(&cardTexture);

    sf::Vector2u textureSize = cardTexture.getSize();

    for (float i = 0; i != float(before.getNum()); i++)
    {
        card.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));

        card.setPosition(i * 50.0f, halfy);
        window.draw(card);
    }

    for (float i = 0; i != float(after.getNum()); i++)
    {
        card.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));

        card.setPosition(windowx - 85 - i * 50.0f, halfy);
        window.draw(card);
    }

    float k = windowx / 2 - (opp.getNum() * 85 - (opp.getNum() - 1) * 35) / 2;
    for (float i = 0; i != float(opp.getNum()); i++)
    {
        card.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));

        card.setPosition(k + i * 50.0f, 0);
        window.draw(card);
    }
    sf::Font font;
    font.loadFromFile("Resource/sansation.ttf");
    string theplayer = "Player " + to_string(flag + 1);
    string beforeplayer = "Player " + to_string(flagModify(flag - 1) + 1);
    string afterplayer = "Player " + to_string(flagModify(flag + 1) + 1);
    string oppplayer = "Player " + to_string(flagModify(flag - 2) + 1);
    string showfront = "The frontcard";
    sf::Text texttheplayer(theplayer, font);
    sf::Text textbeforeplayer(beforeplayer, font);
    sf::Text textafterplayer(afterplayer, font);
    sf::Text textoppplayer(oppplayer, font);
    sf::Text text(showfront, font);
    texttheplayer.setFillColor(sf::Color(240, 255, 255, 170));
    textbeforeplayer.setFillColor(sf::Color(240, 255, 255, 170));
    textafterplayer.setFillColor(sf::Color(240, 255, 255, 170));
    textoppplayer.setFillColor(sf::Color(240, 255, 255, 170));
    text.setFillColor(sf::Color(240, 255, 255, 170));
    texttheplayer.setPosition(windowx / 2 - 85 / 2 - 10, windowy - 128 - 50);
    textbeforeplayer.setPosition(10, windowy / 2 + 128 / 2 + 10);
    textafterplayer.setPosition(windowx - 120, windowy / 2 + 128 / 2 + 10);
    textoppplayer.setPosition(windowx / 2 - 85 / 2 - 10, 138);
    text.setPosition(windowx / 2 - 85 / 2 - 45, windowy / 2 - 128/2 - 50);
    window.draw(texttheplayer);
    window.draw(textbeforeplayer);
    window.draw(textafterplayer);
    window.draw(textoppplayer);
    window.draw(text);
}

void displayPile(CardPile input_pile)
{
    sf::RectangleShape card(sf::Vector2f(85.0f, 128.0f));
    sf::Texture cardTexture;
    cardTexture.loadFromFile("Resource/cards.png");
    card.setTexture(&cardTexture);

    sf::Vector2u textureSize = cardTexture.getSize();
    textureSize.x /= 14;
    textureSize.y /= 8;

    Card displayedcard = frontcard;
    card.setTextureRect(sf::IntRect(textureSize.x * guiTranx(displayedcard), textureSize.y * guiTrany(displayedcard), textureSize.x, textureSize.y));

    card.setPosition(windowx / 2 - 85 / 2, windowy / 2 - 128 / 2);
    window.draw(card);

    float k = windowx/2 - (input_pile.getNum() * 85 - (input_pile.getNum() - 1) * 35)/2;
    for (float i = 0; i != float(input_pile.getNum()); i++)
    {
        displayedcard = input_pile.getCard(i);
        card.setTextureRect(sf::IntRect(textureSize.x * guiTranx(displayedcard), textureSize.y * guiTrany(displayedcard), textureSize.x, textureSize.y));

        card.setPosition(k + i * 50.0f, windowy - 128);
        window.draw(card);
    }
    displayOthers();
    window.display();
}

int main(int argc, char** argv[]) {
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    printf("new window width: %i new window height: %i\n", event.size.width, event.size.height);
            }
        }

        ptrPile = &Pile;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                giveCard(i);
            }
        }

        frontcard = Pile.pop();

        while (gameState())
        {
            window.clear();
            if (ptrPile->isEmpty())
            {
                ptrPile = new CardPile;
            }

            window.clear(sf::Color::Black);

            cout << "Player" << flag + 1 << "'s turn!" << endl << endl;
            cout << "The card before is; " << frontcard << endl;
            cout << PlayerPile[flag].cards << endl;
            displayPile(PlayerPile[flag].cards);
            cout << "Play a card?[y/n]";
            string a;
            cin >> a;
            if (a == "n")
            {
                cout << "pick a card" << endl;
                giveCard(flag);
                cout << "Now you have these cards: " << endl;
                cout << PlayerPile[flag].cards << endl;
                window.clear();
                displayPile(PlayerPile[flag].cards);
                cout << "Play a card?[y/n]";
                string b;
                cin >> b;
                if (b == "n")
                {
                    moveflag(1);
                }
                else
                {                        
                    cout << "which?(press it)" << endl;
                    do
                    {
                        while (true)
                        {
                            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            {
                                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                                if ((float)mousePos.y <= windowy && (float)mousePos.y >= windowy - 128)
                                {
                                    float k = windowx / 2 - (PlayerPile[flag].cards.getNum() * 85 - (PlayerPile[flag].cards.getNum() - 1) * 35) / 2;
                                    outcardnum = int((mousePos.x - k)/50);
                                    break;
                                }
                            }
                        }
                    } while (!judgeCard());
                    outcard = PlayerPile[flag].cards.pop(outcardnum);
                    action();
                }
            }
            else
            {
                cout << "which?(press it)" << endl;
                do
                {
                    while (true)
                    {
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                            if ((float)mousePos.y <= windowy && (float)mousePos.y >= windowy - 128)
                            {
                                float k = windowx / 2 - (PlayerPile[flag].cards.getNum() * 85 - (PlayerPile[flag].cards.getNum() - 1) * 35) / 2;
                                outcardnum = int((mousePos.x - k) / 50);
                                break;
                            }
                        }
                    }
                } while (!judgeCard());
                outcard = PlayerPile[flag].cards.pop(outcardnum);
                action();
            }
            cout << "****************************" << endl;
        }
        window.clear(sf::Color::Black);
    }
    system("pause");
}