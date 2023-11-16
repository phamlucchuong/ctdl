#include <SFML/Graphics.hpp>
#include <iostream>
#include "SecondaryPage.h"
#include "ThirdPage.h"
#include "FourthPage.h"

using namespace sf;
using namespace std;
const int SCRWIDTH = 585;
const int SCRHEIGHT = 900;


enum State{
    page1, page2, page3, page4
};

int main()
{

    State state = page3;

    vector<int> seats;

    RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "SFML Image Loading");

    SecondaryPage second(1);
    ThirdPage third(seats);
    FourthPage fourth;


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
                    if (state == page2)
                    {
                        second.HandleChoseDate(mousePos.x, mousePos.y);
                        second.HandleChoseCenima(mousePos.x, mousePos.y);
                        second.HandleChoseTime(mousePos.x, mousePos.y);
                        if (second.isButtonPressed(window, mousePos, 1))
                        {
                            // Chuyển đến trang 2
                            state = page3;
                        }
                        else if (second.isButtonPressed(window, mousePos, 0))
                        {
                            // Thoát chương trình
                            window.close();
                        }
                    }
                    else if (state == page3)
                    {
                        if (third.isButtonPressed(window, mousePos, 1))
                        {
                            // chuyển sang trang 4
                            state = page4;
                        }
                        else if (third.isButtonPressed(window, mousePos, 0))
                        {
                            // quay lại trang 1
                            state = page2;
                            third.seatUpdate(seats, 0);
                            seats.clear();
                            third.seatColorUpdate(seats);
                        }

                        // kiểm tra tình trạng ghế
                        int temp = third.seatSelected(window, mousePos);
                        auto it = find(seats.begin(), seats.end(), temp);
                        if (it != seats.end()) {
                            // hủy chọn nếu ghế đã được chọn trước đó
                            third.seatUpdate(seats, 0);
                            seats.erase(remove(seats.begin(), seats.end(), temp), seats.end());
                            third.seatColorUpdate(seats);
                            third.seatUpdate(seats, 1);
                            cout << '~' << third.seatName(temp) << endl;
                        }
                        else {
                            // chọn ghế nếu ghế chưa được chọn
                            if (temp != -1) {
                                third.seatUpdate(seats, 0);
                                seats.push_back(temp);
                                third.seatColorUpdate(seats);
                                third.seatUpdate(seats, 1);
                                cout << third.seatName(temp) << endl;
                            }
                        }
                    }
                    else if (state == page4) {
                        if (fourth.prevButtonIsPressed(window, mousePos)) {
                            // quay lại trang 3
                            state = page3;
                        }
                        else if (fourth.nextButtonIsPressed(window, mousePos)) {
                            // thoát khỏi chương trình
                            window.close();
                        }
                    }
                }
            }
        }


        window.clear(Color::White);
        // render page
        switch (state) {
        case page2:
            second.draw(window);
            break;
        case page3:
            third.draw(window);
            break;
        default:
            fourth.draw(window);
            break;
        }
        window.display();
    }

    return 0;
}