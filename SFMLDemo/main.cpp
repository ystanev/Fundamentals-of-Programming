////#include <SFML/Graphics.hpp>
////#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//int main() {
//    sf::IpAddress ip = sf::IpAddress::getLocalAddress(); // IP Add. of the local machine
//    sf::TcpSocket socket; // Creates Socket object
//    char connectionType, mode;
//    char buffer[2000]; // Stores the Data to be sent
//    size_t received;
//    string text = "Connected to ";
//
//    cout << "Choose Connection Type - (S) for Server or (C) for Client: ";
//    cin >> connectionType;
//
//    // Connection Type
//
//    if (connectionType == 's'){ // Server
//        sf::TcpListener listener;
//        listener.listen(2000); // Listen to port #
//        listener.accept(socket);
//        text += "Server.";
//        mode = 's'; // Send mode
//    }
//    else if (connectionType == 'c'){ // Client
//        socket.connect(ip, 2000);
//        text += "Client.";
//        mode = 'r'; // Receive mode
//    }
//
//    socket.send(text.c_str(), text.length() + 1); // Sending Data
//
//    socket.receive(buffer, sizeof(buffer), received); // Receiving Data
//
//    cout << buffer << endl;
//
//    bool done = false;
//
//    while(!done){
//        if (mode == 's'){
//            getline(cin, text);
//            socket.send(text.c_str(), text.length() + 1);
//            mode = 'r';
//        }
//        else if (mode == 'r'){
//            socket.receive(buffer, sizeof(buffer), received);
//            if (received > 0){
//                cout << "Received: " << buffer << endl;
//                mode = 's';
//            }
//        }
//    }
//
//    system("PAUSE");
//
//    return 0;
//}

/*
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
//#include <string>
#include <iostream>

using namespace std;

int main(){
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    char connectionType;

    cout << "Choose Connection Type - (S) for Server or (C) for Client: ";
    cin >> connectionType;

    if (connectionType == 's'){ // Server
        sf::TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
    }
    else
        socket.connect(ip, 2000);

    sf::RectangleShape rect1, rect2;

    rect1.setSize(sf::Vector2f(20, 20));
    rect2.setSize(sf::Vector2f(20, 20));

    rect1.setFillColor(sf::Color::Red);
    rect2.setFillColor(sf::Color::Blue);

    sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "Packets"); // Creates a window

    sf::Vector2f prevPosition, p2Position;

    socket.setBlocking(false);

    bool update = false;

    while(Window.isOpen()){
        sf::Event Event;
        while(Window.pollEvent(Event)){
            if(Event.type == sf::Event::Closed || Event.key.code == sf::Keyboard::Escape)
                Window.close();
            else if (Event.type == sf::Event::GainedFocus)
                update = true;
            else if (Event.type == sf::Event::LostFocus)
                update = false;
        }

        prevPosition = rect1.getPosition(); // Gets the previous position of the Red Square

        if(update){ // Only active window takes input
            //Moves the Red Square in the Window Space
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Because sf::Keyboard has global scope, input is triggered for both windows
                rect1.move(1.0f, 0.0f); // The distance the square is moved by
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                rect1.move(-1.0f, 0.0f);
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                rect1.move(0.0f, -1.0f);
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                rect1.move(0.0f, 1.0f);
        }

        sf::Packet packet; // Created a packet

        if (prevPosition != rect1.getPosition()){
            packet << rect1.getPosition().x << rect1.getPosition().y; // Puts data into the packet
            socket.send(packet); // Sends packet
        }

        socket.receive(packet);
        if (packet >> p2Position.x >> p2Position.y) // Check for data in the packet. Same order as data was put into the packet
            rect2.setPosition(p2Position);

        Window.draw(rect1);
        Window.draw(rect2);

        Window.display();
        Window.clear();
    }

    system("PAUSE");

    return  0;
}*/

/*================================================================================================================================================================================================================================================================
                                                                                                          Battle Ship Game with Networking
================================================================================================================================================================================================================================================================*/

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*=================================================================================================================Data Settings=================================================================================================================================*/
const int BOARD_WIDTH = 15;
const int BOARD_HEIGHT = 10;
const int SHIP_TYPES = 5;

const char isWATER = 247; //ASCII Character Code
const char isHIT = 'X';
const char isSHIP = 'S';
const char isMISS = '0';
int thisPlayer = 1;

struct POINT {
    //A location on the grid defined
    //by X(horizontal) Y(vertical) coordinates
    int X;
    int Y;
};

struct SHIP {
    //Ship name
    string name;
    //Total points on the grid
    int length;
    //Coordinates of those points
    POINT onGrid[5]; //0-4 max length of biggest ship
    //Whether or not those points are a "hit"
    bool hitFlag[5];
} ship[SHIP_TYPES];

struct PLAYER {
    char grid[BOARD_WIDTH][BOARD_HEIGHT];
} player[3]; //Ignore player 0, just using player's 1 & 2

enum DIRECTION {
    HORIZONTAL, VERTICAL
};
struct PLACESHIPS {
    DIRECTION direction;
    SHIP shipType;
};

bool gameRunning = false;
/*==============================================================================================================================================================================================================================================================*/

/*================================================================================================================Functions Prototypes==========================================================================================================================*/
void LoadShips();

void ResetBoard();

void DrawBoard(int);

PLACESHIPS UserInputShipPlacement();

bool UserInputAttack(int &, int &, int);

bool GameOverCheck(int);

void ShipPlacement();

/*===============================================================================================================================================================================================================================================================*/

int main() {
/*================================================================================================================Networking Base================================================================================================================================*/
    sf::IpAddress ip = sf::IpAddress::getLocalAddress(); // Single machine (host ip - 127.0.0.1)
    sf::TcpSocket socket;
    char connectionType;

    cout << "Choose Connection Type - (S) for Server or (C) for Client: ";
    cin >> connectionType;


    socket.setBlocking(false);

    if (connectionType == 's') { // Server
        sf::TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
    } else
        socket.connect(ip, 2000);
/*===============================================================================================================================================================================================================================================================*/


/*====================================================================================================================GAME=======================================================================================================================================*/
    LoadShips();
    ResetBoard();

    sf::Packet packet_1; // Created a packet
    //PLACESHIPS aShip;

    bool test = false;
    packet_1 << test; // Place holder
    socket.send(packet_1);

    socket.receive(packet_1);
    if (packet_1 >> test) {
        cout << packet_1;
    }

/*========================================================================================================="PLACE SHIPS" Phase of the Game=======================================================================================================================*/
    //Loop through each player...
    /*for (int aplyr = 1; aplyr < 3; ++aplyr) {
        //Loop through each ship type to place
        for (int thisShip = 0; thisShip < SHIP_TYPES; ++thisShip) {
            //Display gameboard for player
            //system("cls");
            DrawBoard(aplyr);
            //Give instructions
            cout << "\n";
            cout << "INSTRUCTIONS (Player " << aplyr << ")\n\n";
            cout << "You are about to place your ships.  Format should be:\n";
            cout << "Facing (0:Horizontal,1:Vertical), X (top-row) coords, Y (left-side) coords\n";
            cout << "Example: 0 7 2    This would place a ship beginning at X:7 Y:2 going horizontal\n\n";
            cout << "Ship to place: " << ship[thisShip].name << " which has a length of "
                 << ship[thisShip].length << "\n";
            cout << "Where do you want it placed? ";


            //Get input from user and loop until good data is returned

            aShip.shipType.onGrid[0].X = -1;
            while (aShip.shipType.onGrid[0].X == -1) {
                aShip = UserInputShipPlacement();
            }

            //Combine user data with "this ship" data
            aShip.shipType.length = ship[thisShip].length;
            aShip.shipType.name = ship[thisShip].name;

            //Add the FIRST grid point to the current player's game board
            player[aplyr].grid[aShip.shipType.onGrid[0].X][aShip.shipType.onGrid[0].Y] = isSHIP;

            //Determine ALL grid points based on length and direction
            for (int i = 1; i < aShip.shipType.length; ++i) {
                if (aShip.direction == HORIZONTAL) {
                    aShip.shipType.onGrid[i].X = aShip.shipType.onGrid[i - 1].X + 1;
                    aShip.shipType.onGrid[i].Y = aShip.shipType.onGrid[i - 1].Y;
                }
                if (aShip.direction == VERTICAL) {
                    aShip.shipType.onGrid[i].Y = aShip.shipType.onGrid[i - 1].Y + 1;
                    aShip.shipType.onGrid[i].X = aShip.shipType.onGrid[i - 1].X;
                }

                //Add the REMAINING grid points to our current players game board
                player[aplyr].grid[aShip.shipType.onGrid[i].X][aShip.shipType.onGrid[i].Y] = isSHIP;
            }
            //Loop back through each ship type
        }
        //Loop back through each player

    }*/
/*===============================================================================================================================================================================================================================================================*/
    //Ready to play the game
    gameRunning = true;

/*============================================================================================================Choosing the Players===============================================================================================================================*/
    //int thisPlayer = 1;
    do {
        //Because we are ATTACKING now, the
        //opposite players board is the display board
        int enemyPlayer;

        if (thisPlayer == 1 && connectionType == 's') {
            enemyPlayer = 2;
            connectionType == 'c';
            ShipPlacement();
            //packet_1 << connectionType;

        }
        else if (thisPlayer == 1 && connectionType == 'c') {
            enemyPlayer = 2;
            connectionType == 's';
            ShipPlacement();
            //packet_1 << connectionType;
        }

        if (thisPlayer == 2 && connectionType == 's') {
            enemyPlayer = 1;
            connectionType == 'c';
            ShipPlacement();
            //packet_1 << connectionType;
        }
        else if (thisPlayer == 2 && connectionType == 'c') {
            enemyPlayer = 1;
            connectionType == 's';
            ShipPlacement();
            //packet_1 << connectionType;
        }

        //system("cls");
        DrawBoard(enemyPlayer);
/*==============================================================================================================================================================================================================================================================*/

/*=======================================================================================================Sending Data Over the Network===========================================================================================================================*/
        sf::Packet packet_2; // Created a packet

        //Get attack coords from this player
        bool goodInput = false;
        int x, y;
        while (goodInput == false) {
            goodInput = UserInputAttack(x, y, thisPlayer); // Player enters the attack coordinates. Has to be send over network as a packet.
        }

        packet_2 << goodInput; // Puts coordinates into the packet.
        socket.send(packet_2); // Sends packet

        socket.receive(packet_2); // Client recieves the packet with data
        if (packet_2 >> goodInput) { // Check for data in the packet. Same order as data was put into the packet
            //Check board; if a ship is there, set as HIT.. otherwise MISS
            if (player[enemyPlayer].grid[x][y] == isSHIP) player[enemyPlayer].grid[x][y] = isHIT;
            if (player[enemyPlayer].grid[x][y] == isWATER) player[enemyPlayer].grid[x][y] = isMISS;
        }
/*==============================================================================================================================================================================================================================================================*/
        //Check to see if the game is over
        //If 0 is returned, nobody has won yet
        int aWin = GameOverCheck(enemyPlayer);
        if (aWin != 0) {
            gameRunning = false;
            break;
        }
        //Alternate between each player as we loop back around
        thisPlayer = (thisPlayer == 1) ? 2 : 1;
    } while (gameRunning);

    //system("cls");
    cout << "\n\nCONGRATULATIONS!!!  PLAYER " << thisPlayer << " HAS WON THE GAME!\n\n\n\n";

    system("pause");
    return 0;
}

/*=============================================================================================================Functions Definitions=============================================================================================================================*/
bool GameOverCheck(int enemyPLAYER) {
    bool winner = true;
    //Loop through enemy board
    for (int w = 0; w < BOARD_WIDTH; ++w) {
        for (int h = 0; h < BOARD_HEIGHT; ++h) {
            //If any ships remain, game is NOT over
            if (player[enemyPLAYER].grid[w][h] = isSHIP) {
                winner = false;
                return winner;
            }
        }
    }
    //If we get here, somebody won, game over!
    return winner;
}

bool UserInputAttack(int &x, int &y, int theplayer) {
    cout << "\nPLAYER " << theplayer << ", ENTER COORDINATES TO ATTACK: ";
    bool goodInput = false;
    cin >> x >> y;
    if (x < 0 || x >= BOARD_WIDTH) return goodInput;
    if (y < 0 || y >= BOARD_HEIGHT) return goodInput;
    goodInput = true;
    return goodInput;
}

PLACESHIPS UserInputShipPlacement() {
    int d, x, y;
    PLACESHIPS tmp;
    //Using this as a bad return
    tmp.shipType.onGrid[0].X = -1;
    //Get 3 integers from user
    cin >> d >> x >> y;
    if (d != 0 && d != 1) return tmp;
    if (x < 0 || x >= BOARD_WIDTH) return tmp;
    if (y < 0 || y >= BOARD_HEIGHT) return tmp;
    //Good data
    tmp.direction = (DIRECTION) d;
    tmp.shipType.onGrid[0].X = x;
    tmp.shipType.onGrid[0].Y = y;
    return tmp;
}

void LoadShips() {
    //Sets the default data for the ships
    //we plan to include in the game
    //IMPORTANT!! > MUST MATCH SHIP_TYPES -Default=5 (0-4)
    ship[0].name = "Cruiser";
    ship[0].length = 2;
    ship[1].name = "Frigate";
    ship[1].length = 3;
    ship[2].name = "Submarine";
    ship[2].length = 3;
    ship[3].name = "Escort";
    ship[3].length = 4;
    ship[4].name = "Battleship";
    ship[4].length = 5;
}

void ResetBoard() {
    //Loop through each player
    for (int plyr = 1; plyr < 3; ++plyr) {
        //For each grid point, set contents to 'water'
        for (int w = 0; w < BOARD_WIDTH; ++w) {
            for (int h = 0; h < BOARD_HEIGHT; ++h) {
                player[plyr].grid[w][h] = isWATER;
            }
        }
        //Loop back to next player
    }
}

void DrawBoard(int thisPlayer) {
    //Draws the board for a player (thisPlayer)
    cout << "PLAYER " << thisPlayer << "'s GAME BOARD\n";
    cout << "----------------------\n";

    //Loop through top row (board_width) and number columns
    cout << "   ";
    for (int w = 0; w < BOARD_WIDTH; ++w) {
        if (w < 10)
            //Numbers only 1 character long, add two spaces after
            cout << w << "  ";
        else if (w >= 10)
            //Numbers 2 characters long, add only 1 space after
            cout << w << " ";
    }
    cout << "\n";

    //Loop through each grid point and display to console
    for (int h = 0; h < BOARD_HEIGHT; ++h) {
        for (int w = 0; w < BOARD_WIDTH; ++w) {

            //If this is the FIRST (left) grid point, number the grid first
            if (w == 0) cout << h << " ";
            //If h was 1 character long, add an extra space to keep numbers lined up
            if (w < 10 && w == 0) cout << " ";
            //Display contents of this grid (if game isn't running yet, we are placing ships
            //so display the ships
            if (gameRunning == false) cout << player[thisPlayer].grid[w][h] << "  ";
            //Don't show ships, BUT show damage if it's hit
            if (gameRunning == true && player[thisPlayer].grid[w][h] != isSHIP) {
                cout << player[thisPlayer].grid[w][h] << "  ";
            }
            else if (gameRunning == true && player[thisPlayer].grid[w][h] == isSHIP) { cout << isWATER << "  "; }
            //If we have reached the border.. line feed
            if (w == BOARD_WIDTH - 1) cout << "\n";
        }
    }
}

void ShipPlacement() {
    PLACESHIPS aShip;

    //"PLACE SHIPS" phase of game
    //Loop through each player...
    for (int aplyr = 1; aplyr < 3; ++aplyr) {
        //Loop through each ship type to place
        for (int thisShip = 0; thisShip < SHIP_TYPES; ++thisShip) {
            //Display gameboard for player
            //system("cls");
            DrawBoard(aplyr);
            //Give instructions
            cout << "\n";
            cout << "INSTRUCTIONS (Player " << aplyr << ")\n\n";
            cout << "You are about to place your ships.  Format should be:\n";
            cout << "Facing (0:Horizontal,1:Vertical), X (top-row) coords, Y (left-side) coords\n";
            cout << "Example: 0 7 2    This would place a ship beginning at X:7 Y:2 going horizontal\n\n";
            cout << "Ship to place: " << ship[thisShip].name << " which has a length of "
                 << ship[thisShip].length << "\n";
            cout << "Where do you want it placed? ";

            //Get input from user and loop until good data is returned

            aShip.shipType.onGrid[0].X = -1;
            while (aShip.shipType.onGrid[0].X == -1) {
                aShip = UserInputShipPlacement();
            }

            //Combine user data with "this ship" data
            aShip.shipType.length = ship[thisShip].length;
            aShip.shipType.name = ship[thisShip].name;

            //Add the FIRST grid point to the current player's game board
            player[aplyr].grid[aShip.shipType.onGrid[0].X][aShip.shipType.onGrid[0].Y] = isSHIP;

            //Determine ALL grid points based on length and direction
            for (int i = 1; i < aShip.shipType.length; ++i) {
                if (aShip.direction == HORIZONTAL) {
                    aShip.shipType.onGrid[i].X = aShip.shipType.onGrid[i - 1].X + 1;
                    aShip.shipType.onGrid[i].Y = aShip.shipType.onGrid[i - 1].Y;
                }
                if (aShip.direction == VERTICAL) {
                    aShip.shipType.onGrid[i].Y = aShip.shipType.onGrid[i - 1].Y + 1;
                    aShip.shipType.onGrid[i].X = aShip.shipType.onGrid[i - 1].X;
                }

                //Add the REMAINING grid points to our current players game board
                player[aplyr].grid[aShip.shipType.onGrid[i].X][aShip.shipType.onGrid[i].Y] = isSHIP;
            }
            //Loop back through each ship type
        }
        //Loop back through each player
    }
}
/*===============================================================================================================================================================================================================================================================*/
