#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include <Color.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
//#include "Battleship.h"
#include <windows.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <cstdlib>

const int SHIP_TYPES = 5;
const int TILESIZE = 32;

struct Point {
    int x, y;
};

struct Player {
    sf::RectangleShape grid[10][10];
    sf::Texture texture;
    sf::Sprite sprite;
} player[3];

struct Ships {
    sf::String name;
    int length;

    sf::RectangleShape shape;

    Point onGrid[5];

    bool hitFlag = false;
} ships[SHIP_TYPES];

enum DIRECTION {
    HORIZONTAL, VERTICAL
};

struct PlaceShips {
    DIRECTION direction;
    Ships ships;
};

int mouseX = 0;
int mouseY = 0;

bool gameRunning = false;
bool play = true;
bool mouseClicked = false;
bool mouseInsideRect = false;
bool draggingShip1 = false;
bool draggingShip2 = false;
bool draggingShip3 = false;
bool draggingShip4 = false;
bool draggingShip5 = false;

sf::RectangleShape drawRectangle(float width = 1.0f, float height = 1.0f,
                                 sf::Vector2f position = sf::Vector2f(0, 0),
                                 const sf::Color &myFillColor = sf::Color::Green,
                                 const sf::Color &myOutlineColor = sf::Color::Black,
                                 float myOutlineThickness = -2) {
    sf::RectangleShape myRectangle;
    sf::Vector2f myRectangleSize(width, height);
    myRectangle.setSize(myRectangleSize);
    myRectangle.setPosition(position);
    myRectangle.setFillColor(myFillColor);
    myRectangle.setOutlineColor(myOutlineColor);
    myRectangle.setOutlineThickness(myOutlineThickness);
    return myRectangle;
}

void player_1(sf::RectangleShape shape1[10][10]);

void player_2(sf::RectangleShape shape2[10][10]);

int main() {

    int player1 = 1, player2 = 2;
    sf::RectangleShape shape1[10][10];
    sf::RectangleShape shape2[10][10];
    sf::RectangleShape enemy_player[5][10];

    /*============================================= Networking Base ==================================================*/

    sf::IpAddress ip = sf::IpAddress::getLocalAddress(); // Single machine (host ip - 127.0.0.1)
    sf::TcpSocket socket;
    char connectionType;

    std::cout << "Choose Connection Type - (S) for Server or (C) for Client: ";
    std::cin >> connectionType;


    socket.setBlocking(false);

    if (connectionType == 's') { // Server
        sf::TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
    } else {
        socket.connect(ip, 2000);
    }

    if (player1 && connectionType == 's') {
        player2;
        connectionType == 'c';
        player_1(shape1);
    } else if (player1 && connectionType == 'c') {
        player2;
        connectionType == 's';
        player_1(shape1);
    }

    if (player2 && connectionType == 's') {
        player1;
        connectionType == 'c';
        player_2(shape2);
    } else if (player2 && connectionType == 'c') {
        player1;
        connectionType == 's';
        player_2(shape2);
    }

    /*================================================================================================================*/

    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(900, 900, 32), "Battleship");

    socket.setBlocking(false);

    /*sf::Vector2i mousePosition;
    mousePosition = sf::Mouse::getPosition(window);*/

    sf::Vector2f prevPosition, p2Position, savePosition;
    /*
    sf::RenderWindow *w;
    w = &window;

    //sf::Sprite sp = board(10,10, 1);

    while (w->isOpen())
    {

        sf::Event event;
        while (w->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w->close();
        }

        Battleship battleship(w);
    }
    */
    sf::Texture texture;
    /*if (!texture.loadFromFile("Sprites/cross.png")) {
        return EXIT_FAILURE;
    }*/

    const sf::Texture *isWater = &texture;
    //sf::Sprite isWater(texture);

    ships[0].name = "cruiser";
    ships[0].length = 2;

    ships[1].name = "cruiser 1";
    ships[1].length = 3;

    ships[2].name = "cruiser 2";
    ships[2].length = 3;

    ships[3].name = "cruiser 3";
    ships[3].length = 4;

    ships[4].name = "battleship";
    ships[4].length = 5;

    Ships ships1[SHIP_TYPES];

    ships[0].shape = drawRectangle(64, 32, sf::Vector2f(32, 564));
    ships[1].shape = drawRectangle(96, 32, sf::Vector2f(32, 527));
    ships[2].shape = drawRectangle(96, 32, sf::Vector2f(32, 490));
    ships[3].shape = drawRectangle(128, 32, sf::Vector2f(32, 453));
    ships[4].shape = drawRectangle(160, 32, sf::Vector2f(32, 416));
    //Player player1;
    //int player1 = 1;
    sf::Font font;
    //font.loadFromFile("futuroNormal.otf");
    sf::Text title("Player", font, 20);
    title.setColor(sf::Color::Black);
    title.setPosition(150, 2);

    sf::Text enemy("Enemy", font, 20);
    enemy.setColor(sf::Color::Black);
    enemy.setPosition(550, 2);

    /*for (int i = 0; i < SHIP_TYPES; ++i) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                shape1[i][j].setSize(sf::Vector2f(32, 32));
                shape1[i][j].setOutlineColor(sf::Color::Black);
                shape1[i][j].setOutlineThickness(5.0f);
                shape1[i][j].setFillColor(sf::Color::Blue);
                shape1[i][j].setPosition(i * 32 + 20.0f, j * 32 + 30.0f);
                player[player1].grid[i][j] = shape1[i][j];
            }
        }

        *//*int x = rand() % 100;
        int y = rand() % 100;*//*
        //int r = rand()%2;
        //ships[i].shape.setPosition(x *i + 5.0f, y * i + 5.0f);
        //player[player1].grid[ships[i].onGrid[i].x][ships[i].onGrid[i].y] = ships[i].shape;
        //ships[i].shape.rotate(r);
    }*/
    /*player[player1].texture.loadFromFile("Sprites/board.png");
    player[player1].sprite.setTexture(player[player1].texture);
    player[player1].sprite.setScale(0.4,0.4);
    player[thisPlayer].sprite.setPosition(60, 60);*/

    sf::RectangleShape enemyHighlightCell = drawRectangle(32, 32);
    enemyHighlightCell.setFillColor(sf::Color::Black);
    enemyHighlightCell.setOutlineColor(sf::Color::Black);

    //int player2 = 2;
    /*for (int i = 0; i < SHIP_TYPES; ++i) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                shape2[i][j].setSize(sf::Vector2f(32, 32));
                shape2[i][j].setOutlineColor(sf::Color::Black);
                shape2[i][j].setOutlineThickness(5.0f);
                shape2[i][j].setFillColor(sf::Color::Blue);
                shape2[i][j].setPosition(i * 32 + 470.0f, j * 32 + 30.0f);
                player[player2].grid[i][j] = shape2[i][j];
            }
        }
    }*/

    /*sf::Texture texture;
    player1.texture.loadFromFile("Sprites/board.png");
    player1.sprite.setTexture(player1.texture);
    player1.sprite.setScale(0.4,0.4);
    player1.sprite.setPosition(60, 60);

    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(79, 40));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(60, 60);*/

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                    /*case sf::Event::MouseMoved:
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) )
                        {
                            savePosition.x = event.mouseMove.x;
                            savePosition.y = event.mouseMove.y;
                            ships[0].shape.setPosition(savePosition.x, savePosition.y);
                        }
                        break;*/
            }



            /*
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            /*
            if (event.type == sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mousePosition.x = event.mouseButton.x;
                mousePosition.y = event.mouseButton.y;
            }

            /*
            if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                savePosition.x = event.mouseMove.x;
                savePosition.y = event.mouseMove.y;
                //ships[0].shape.setSize(savePosition);
                ships[0].shape.setPosition(savePosition.x, savePosition.y);

                if (ships[0].name == "cruiser")
                {
                    ships[0].shape.setPosition(savePosition.x, savePosition.y);
                }
                if(ships[1].name == "cruiser 1")
                {
                    ships[1].shape.setPosition(event.mouseMove.x, event.mouseMove.y);
                }
            }
            */

            for (int i = 0; i < 5; i++)
            {
                prevPosition = ships[i].shape.getPosition();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mouseClicked = true;
                if (ships[0].shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    draggingShip1 = true;
                    savePosition.x =
                            event.mouseButton.x - ships[0].shape.getGlobalBounds().left - ships[0].shape.getOrigin().x;
                    savePosition.y =
                            event.mouseButton.y - ships[0].shape.getGlobalBounds().top - ships[0].shape.getOrigin().y;
                }

                if (ships[1].shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    draggingShip2 = true;
                    savePosition.x =
                            event.mouseButton.x - ships[1].shape.getGlobalBounds().left - ships[1].shape.getOrigin().x;
                    savePosition.y =
                            event.mouseButton.y - ships[1].shape.getGlobalBounds().top - ships[1].shape.getOrigin().y;
                }

                if (ships[2].shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    draggingShip3 = true;
                    savePosition.x =
                            event.mouseButton.x - ships[2].shape.getGlobalBounds().left - ships[2].shape.getOrigin().x;
                    savePosition.y =
                            event.mouseButton.y - ships[2].shape.getGlobalBounds().top - ships[2].shape.getOrigin().y;
                }

                if (ships[3].shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    draggingShip4 = true;
                    savePosition.x =
                            event.mouseButton.x - ships[3].shape.getGlobalBounds().left - ships[3].shape.getOrigin().x;
                    savePosition.y =
                            event.mouseButton.y - ships[3].shape.getGlobalBounds().top - ships[3].shape.getOrigin().y;
                }

                if (ships[4].shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    draggingShip5 = true;
                    savePosition.x =
                            event.mouseButton.x - ships[4].shape.getGlobalBounds().left - ships[4].shape.getOrigin().x;
                    savePosition.y =
                            event.mouseButton.y - ships[4].shape.getGlobalBounds().top - ships[4].shape.getOrigin().y;
                }
            }

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                mouseClicked = false;
                draggingShip1 = false;
                draggingShip2 = false;
                draggingShip3 = false;
                draggingShip4 = false;
                draggingShip5 = false;
            }

            if (event.type == sf::Event::MouseMoved) {
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
            }
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                ships[0].shape.rotate(90);
            }

        }

        if (draggingShip1 == true) {
            ships[0].shape.setPosition(mouseX - savePosition.x, mouseY - savePosition.y);
        }

        if (draggingShip2 == true) {
            ships[1].shape.setPosition(mouseX - savePosition.x, mouseY - savePosition.y);
        }

        if (draggingShip3 == true) {
            ships[2].shape.setPosition(mouseX - savePosition.x, mouseY - savePosition.y);
        }

        if (draggingShip4 == true) {
            ships[3].shape.setPosition(mouseX - savePosition.x, mouseY - savePosition.y);
        }

        if (draggingShip5 == true) {
            ships[4].shape.setPosition(mouseX - savePosition.x, mouseY - savePosition.y);
        }

/*======================================================= Sending Data ===============================================*/

        sf::Packet packet, packet1, packet2; // Creates a packet.
        sf::Uint8 red, green;

        sf::Vector2i pointPos = sf::Mouse::getPosition(window);
        // Save position of each ship to the packet
        /*packet << ships[0].shape.getPosition().x << ships[0].shape.getPosition().y
               << ships[1].shape.getPosition().x << ships[1].shape.getPosition().y
               << ships[2].shape.getPosition().x << ships[2].shape.getPosition().y
               << ships[3].shape.getPosition().x << ships[3].shape.getPosition().y
               << ships[4].shape.getPosition().x << ships[4].shape.getPosition().y*/;
        for (int i = 0; i < 5; i++) {
            if (prevPosition != ships[i].shape.getPosition()){

                packet << ships[i].shape.getPosition().x << ships[i].shape.getPosition().y;
                socket.send(packet1);
            }//
            //packet << ships[i].shape.getPosition().x << ships[i].shape.getPosition().y;
        }
       // socket.send(packet); // Send  packet over



        socket.receive(packet);
        if (packet >> p2Position.x >> p2Position.y) { // Checks packet for data
            for (int i = 0; i < 5; i++) {
                ships1[i].shape.setPosition(/*p2Position*/ships[i].shape.getPosition().x, ships[i].shape.getPosition().y);
            }

            if (player1) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        sf::FloatRect gridBounds = shape2[i][j].getGlobalBounds();

                        if (gridBounds.contains((sf::Vector2f(pointPos)))) {
                            enemyHighlightCell.setPosition(shape2[i][j].getPosition());
                            window.draw(enemyHighlightCell);

                            if (event.type == sf::Event::MouseButtonPressed &&
                                event.mouseButton.button == sf::Mouse::Left) {
                                if (ships->onGrid) {
                                    ships->hitFlag = true;
                                    shape2[i][j].setFillColor(sf::Color::Red);
                                    shape2[i][j].getFillColor();
                                    //sf::Uint8 red; // ??
                                    packet1 << red;

                                } else {
                                    shape2[i][j].setFillColor(sf::Color::Yellow);
                                    //sf::Uint8 green;
                                    packet1 << green;
                                }
                            }
                        }
                    }
                }
            }

            socket.send(packet1);

            socket.receive(packet1);

            if (packet1 >> green && player2) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        sf::FloatRect gridBounds = shape1[i][j].getGlobalBounds();

                        if (gridBounds.contains((sf::Vector2f(pointPos)))) {
                            if (event.type == sf::Event::MouseButtonPressed &&
                                event.mouseButton.button == sf::Mouse::Left && ships->hitFlag == false) {

                                shape1[i][j].setFillColor(sf::Color::Yellow);
                            }
                        }
                    }
                }
            } else {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        sf::FloatRect gridBounds = shape1[i][j].getGlobalBounds();

                        if (gridBounds.contains((sf::Vector2f(pointPos)))) {
                            if (event.type == sf::Event::MouseButtonPressed &&
                                event.mouseButton.button == sf::Mouse::Left && ships->hitFlag == true) {

                                shape1[i][j].setFillColor(sf::Color::Red);
                            }
                        }
                    }
                }
            }


            if (player2) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        sf::FloatRect gridBounds = shape1[i][j].getGlobalBounds();

                        if (gridBounds.contains((sf::Vector2f(pointPos)))) {
                            enemyHighlightCell.setPosition(shape1[i][j].getPosition());
                            window.draw(enemyHighlightCell);

                            if (event.type == sf::Event::MouseButtonPressed &&
                                event.mouseButton.button == sf::Mouse::Left) {
                                if (ships->onGrid) {
                                    ships->hitFlag = true;
                                    //shape1[i][j].setFillColor(sf::Color::Red);
                                    //sf::Uint8 red; // ??
                                    packet2 << red;
                                } else {
                                    //shape1[i][j].setFillColor(sf::Color::Yellow);
                                    //sf::Uint8 green;
                                    packet2 << green;
                                }
                            }
                        }
                    }
                }
            }

            socket.send(packet2);

            socket.receive(packet2);

            if (packet2 >> green && player1) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        sf::FloatRect gridBounds = shape2[i][j].getGlobalBounds();

                        if (gridBounds.contains((sf::Vector2f(pointPos)))) {
                            if (event.type == sf::Event::MouseButtonPressed &&
                                event.mouseButton.button == sf::Mouse::Left && ships->hitFlag == false) {

                                shape2[i][j].setFillColor(sf::Color::Yellow);
                            }
                        }
                    }
                }
            } else {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        sf::FloatRect gridBounds = shape2[i][j].getGlobalBounds();

                        if (gridBounds.contains((sf::Vector2f(pointPos)))) {
                            if (event.type == sf::Event::MouseButtonPressed &&
                                event.mouseButton.button == sf::Mouse::Left && ships->hitFlag == true) {

                                shape2[i][j].setFillColor(sf::Color::Red);
                            }
                        }
                    }
                }
            }
        }



        /*====================================================================================================================*/


        window.clear(sf::Color(51, 153, 255));
        //window.draw(player[player1].sprite);
        window.draw(title);
        window.draw(enemy);


        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                window.draw(shape1[i][j]);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                window.draw(shape2[i][j]);
                sf::FloatRect gridBounds = shape2[i][j].getGlobalBounds();

                /*if (gridBounds.contains((sf::Vector2f) pointPos)) {
                    enemyHighlightCell.setPosition(shape2[i][j].getPosition());
                    window.draw(enemyHighlightCell);
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                        shape2[i][j].setTexture(isWater);
                    }
                }*/
            }
        }
        for (int i = 0; i < 5; i++) {
            window.draw(ships[i].shape);
        }

        window.display();
    }

    return EXIT_SUCCESS;
}

void player_2(sf::RectangleShape shape2[10][10]) {
    for (int i = 0; i < SHIP_TYPES; ++i) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                shape2[i][j].setSize(sf::Vector2f(32, 32));
                shape2[i][j].setOutlineColor(sf::Color::Black);
                shape2[i][j].setOutlineThickness(5.0f);
                shape2[i][j].setFillColor(sf::Color::Blue);
                shape2[i][j].setPosition(i * 32 + 470.0f, j * 32 + 30.0f);
                //player[player2].grid[i][j] = shape2[i][j];
            }
        }
    }
}

void player_1(sf::RectangleShape shape1[10][10]) {
    for (int i = 0; i < SHIP_TYPES; ++i) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                shape1[i][j].setSize(sf::Vector2f(32, 32));
                shape1[i][j].setOutlineColor(sf::Color::Black);
                shape1[i][j].setOutlineThickness(5.0f);
                shape1[i][j].setFillColor(sf::Color::Blue);
                shape1[i][j].setPosition(i * 32 + 20.0f, j * 32 + 30.0f);
                //player[player1].grid[i][j] = shape1[i][j];
            }
        }
    }
}
