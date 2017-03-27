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
}