#include <SFML/Graphics.hpp>
#include <iostream>
#include "SecondaryPage.h"
#include "ThirdPage.h"

using namespace sf;
using namespace std;
const int SCRWIDTH = 585;
const int SCRHEIGHT = 900;


enum State{
    page1, page2
};

void announce(int seatIndex) {
    switch (seatIndex / 10) {
    case 0:
        cout << "A";
        break;
    case 1:
        cout << "B";
        break;
    case 2:
        cout << "C";
        break;
    default:
        cout << "D";
        break;
    }
    if (seatIndex != 9) cout << '0' << (seatIndex + 1) % 10;
    else cout << "10";
}


int main()
{

    State state = page2;

    vector<int> seats;

    RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "SFML Image Loading");

    SecondaryPage second(1);
    ThirdPage third(seats);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
                cout << "Handling event closed" << endl;
                exit(EXIT_SUCCESS);
            }



            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    Vector2i mousePos = Mouse::getPosition(window);
                    // Kiểm tra trạng thái trang và xử lý sự kiện
                    if (state == page1)
                    {
                        if (second.nextButtonIsPressed(window))
                        {
                            // Chuyển đến trang 2
                            state = page2;
                        }
                        else if (second.prevButtonIsPressed(window))
                        {
                            // Thoát chương trình
                            window.close();
                        }
                    }
                    else if (state == page2)
                    {
                        if (third.nextButtonIsPressed(window, mousePos))
                        {
                            // Kết thúc chương trình
                            if (!seats.empty()) {
                                for (int temp : seats) {
                                    announce(temp);
                                    cout << ' ';
                                }
                            }
                            window.close();
                        }
                        else if (third.prevButtonIsPressed(window, mousePos))
                        {
                            // quay lại trang 1
                            state = page1;
                        }

                        // kiểm tra tình trạng ghế
                        int temp = third.seatSelected(window, mousePos);
                        auto it = find(seats.begin(), seats.end(), temp);
                        if (it != seats.end()) {
                            // hủy chọn nếu ghế đã được chọn trước đó
                            seats.erase(remove(seats.begin(), seats.end(), temp), seats.end());
                            third.changeSeatColor(seats);
                            cout << '~';
                            announce(temp);
                            cout << endl;
                        }
                        else {
                            // chọn ghế nếu ghế chưa được chọn
                            if (temp != -1) {
                                seats.push_back(temp);
                                third.changeSeatColor(seats);
                                announce(temp);
                                cout << endl;
                            }
                        }
                    }
                }
            }
        }


        window.clear(Color::White);
        // render page
        switch (state) {
        case page1:
            second.draw(window);
            break;
        case page2:
            third.draw(window);
            break;
        }
        window.display();
    }

    return 0;
}