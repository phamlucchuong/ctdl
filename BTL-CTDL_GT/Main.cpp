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


int main()
{

    State state = page1;
    vector<int> index;

    RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "SFML Image Loading");

    SecondaryPage second(1);
    ThirdPage third;

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
                        if (third.nextButtonIsPressed(window))
                        {
                            // Kết thúc chương trình
                            window.close();
                        }
                        else if (third.prevButtonIsPressed(window))
                        {
                            // Quay lại trang 1
                            state = page1;
                        }

                        index = third.seatSelected(window);
                        for (int x : index) {
                            cout << x << ' ';
                        }

                    }
                }
            }
            


            /*if (event.type == sf::Event::MouseMoved && event.type != sf::Event::MouseLeft)
            {
                int mouseX = event.mouseMove.x;
                int mouseY = event.mouseMove.y;
                std::cout << "Mouse X: " << mouseX << " Mouse Y: " << mouseY << std::endl;
            }*/


        }


        window.clear(Color::White);
        if (state == page1) {
            second.draw(window);
        }
        else if (state == page2) {
            third.draw(window);
        }
        window.display();
    }

    return 0;
}