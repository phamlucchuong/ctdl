#include "ThirdPage.h"


ThirdPage::ThirdPage() : m_blocks("third"), m_texts("third")
{

    string filePathIconPrev = "images/icon-prev.png";
    string filePath = "images/data/ke-kien-tao.png";

    float xPos = 40.0f;
    float yPos = 85.0f;
    float xScale = 0.55;
    float yScale = 0.55;

    float xLogoPosition = 220;
    float yLogoPosition = 20.0f;
    float xIconPrevPosition = 40.0f;
    float yIconPrevPosition = 35.0f;

    fontFilmName.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
    fontTitle.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
    fontDesc.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
    fontHeader.loadFromFile("fonts/Montserrat/Montserrat-Semibold.ttf");

    //selectedItemIndex = num;

    m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);
    m_blocks.AddBlockContainer(filePath, xPos, 113, xScale, yScale);


    //TextContainer textTest("test Text");
    // set film's name
    m_texts.AddTextContainer("Ke Kien Tao", fontFilmName, 30, Color(186, 15, 46), 220 - 15, 100);
    // set film's category
    m_texts.AddTextContainer("The loai:", fontTitle, 18, Color::Black, xLogoPosition - 15, 135);
    // set film's category content
    m_texts.AddTextContainer("Hanh dong, KHVT,...", fontDesc, 16, Color::Black, xLogoPosition - 15 + 85, 137);
    // set film's time
    m_texts.AddTextContainer("Thoi luong:", fontTitle, 18, Color::Black, xLogoPosition - 15, 160);
    // set film's time content
    m_texts.AddTextContainer("120p", fontDesc, 16, Color::Black, xLogoPosition - 15 + 110, 162);
    // set film's language
    m_texts.AddTextContainer("Ngon ngu:", fontTitle, 18, Color::Black, xLogoPosition - 15, 185);
    // set film's language content
    m_texts.AddTextContainer("Tieng Anh - Phu de Tieng Viet", fontDesc, 16, Color::Black, xLogoPosition - 15 + 105, 187);
    // set film's Rate
    m_texts.AddTextContainer("Danh gia:", fontTitle, 18, Color::Black, xLogoPosition - 15, 210);
    // set film's Rate content
    m_texts.AddTextContainer("4,6/5", fontDesc, 16, Color::Black, xLogoPosition - 15 + 100, 212);
    // set film's Date
    m_texts.AddTextContainer("Khoi Chieu:", fontTitle, 18, Color::Black, xLogoPosition - 15, 235);
    // set film's Date content
    m_texts.AddTextContainer("10/11/2023", fontDesc, 16, Color::Black, xLogoPosition - 15 + 110, 237);

    // set film's description heading

    m_texts.AddTextContainer("Mo ta phim", fontHeader, 26, Color::Black, xIconPrevPosition, 320);
    // set film's director
    m_texts.AddTextContainer("Dao dien:", fontTitle, 18, Color::Black, xIconPrevPosition, 350);
    // set film's director content
    m_texts.AddTextContainer("Huynh Thi Truc Lam", fontDesc, 16, Color::Black, xIconPrevPosition + 110, 352);
    // set film's actor
    m_texts.AddTextContainer("Dien vien long tieng:", fontTitle, 18, Color::Black, xIconPrevPosition, 375);
    // set film's actor desc
    m_texts.AddTextContainer("Brie Larson, Samuel L. Jackson, Zaw... ", fontDesc, 16, Color::Black, xIconPrevPosition + 200, 377);

    m_texts.AddTextContainer("Chon ghe", fontTitle, 25, Color::White, xIconPrevPosition + 35, 421);

    // set bg-action
    Texture bgRed;
    bgRed.loadFromFile("images/bg-red.png");
    Sprite bgAction(bgRed);
    bgAction.setScale(0.3, 0.3);
    bgAction.setPosition(xIconPrevPosition, yIconPrevPosition + 380);
    // set action'title
    Text actionTitle("Chon ngay chieu", fontTitle, 18);
    actionTitle.setFillColor(Color(255, 255, 255));
    actionTitle.move(xIconPrevPosition + 25, yIconPrevPosition + 390);

    // text component test
    // TextComponent textTest("heellooo", fontTitle, 40, 100, 100);


    //BlockContainer backGround("container");

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 380, 0.3, 0.3);
    m_blocks.AddBlockContainer("images/img-screen.png", xIconPrevPosition + 10, yIconPrevPosition + 450, 0.7, 0.7);

    /*float yPosi = yIconPrevPosition + 520.0f;
    for (int i = 0; i < 35; i++) {
        m_blocks.AddBlockContainer("images/bg-gray.png", 40 + (i % 10) * 50, yPosi + (i / 10) * 4, 0.1, 0.1);
    }*/

    for (int i = 0; i < 35; i++) {
        if (i <= 9) {
            m_blocks.AddBlockContainer("images/bg-gray.png", 40 + i * 50, yIconPrevPosition + 520, 0.1, 0.1);
        }
        else if (i <= 19) {
            m_blocks.AddBlockContainer("images/bg-gray.png", 40 + (i - 10) * 50, yIconPrevPosition + 560, 0.1, 0.1);
        }
        else if (i <= 29) {
            m_blocks.AddBlockContainer("images/bg-gray.png", 40 + (i - 20) * 50, yIconPrevPosition + 600, 0.1, 0.1);
        }
        else if (i <= 34) {
            m_blocks.AddBlockContainer("images/bg-gray.png", 40 + (i - 30) * 100, yIconPrevPosition + 640, 0.2, 0.1);
        }
    }
    m_blocks.AddBlockContainer("images/bg-gray.png", xIconPrevPosition + 20, yIconPrevPosition + 690, 0.05, 0.05);
    m_texts.AddTextContainer("Ghe chua chon", fontDesc, 15, Color::Black, xIconPrevPosition + 50, yIconPrevPosition + 690);

    m_blocks.AddBlockContainer("images/bg-red-2.png", xIconPrevPosition + 20, yIconPrevPosition + 710, 0.2, 0.16);
    m_texts.AddTextContainer("Ghe da chon", fontDesc, 15, Color::Black, xIconPrevPosition + 50, yIconPrevPosition + 710);

    m_texts.AddTextContainer("A,B,C,D", fontTitle, 15, Color::Black, xIconPrevPosition + 270, yIconPrevPosition + 710);
    m_texts.AddTextContainer("Hang ghe", fontDesc, 15, Color::Black, xIconPrevPosition + 340, yIconPrevPosition + 710);

    m_blocks.AddBlockContainer("images/bg-gray.png", xIconPrevPosition + 270, yIconPrevPosition + 690, 0.1, 0.05);
    m_texts.AddTextContainer("Ghe doi", fontDesc, 15, Color::Black, xIconPrevPosition + 340, yIconPrevPosition + 690);

    for (int i = 0; i <= 7; i++) {
        if (i < 2)
            m_texts.AddTextContainer("A", fontTitle, 18, Color::Black, 15 + i * 540, yIconPrevPosition + 525);
        else if (i < 4)
            m_texts.AddTextContainer("B", fontTitle, 18, Color::Black, 15 + (i - 2) * 540, yIconPrevPosition + 565);
        else if (i < 6)
            m_texts.AddTextContainer("C", fontTitle, 18, Color::Black, 15 + (i - 4) * 540, yIconPrevPosition + 605);
        else
            m_texts.AddTextContainer("D", fontTitle, 18, Color::Black, 15 + (i - 6) * 540, yIconPrevPosition + 650);
    }


    vector<int> v[4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) v[i].push_back(j+1);
    }
    for (int i = 1; i <= 5; i++) v[3].push_back(i);

    float yP = 560.0f;
    for (int i = 0; i < 4; i++) {
        float xP = xIconPrevPosition + 20.0f;
        for (int j = 0; j < v[i].size(); j++) {
            m_texts.AddTextContainer(to_string(v[i][j]), fontTitle, 18, Color::Black, xP, yP);
            if(i == 3) xP += 100.0f;
            else xP += 49.0f;
        }
        yP += 40.0f;
    }
        

    /*for (int i = 0; i <= 34; i++) {
        if (i == 0 || i == 10 || i == 20)
            m_texts.AddTextContainer(to_string(k), fontTitle, 18, Color::Black, xIconPrevPosition + 22, 560 + i * 4);
        else if (i == 1 || i == 11 || i == 21)
            m_texts.AddTextContainer("2", fontTitle, 18, Color::Black, xIconPrevPosition + 67, 560 + (i - 1) * 4);
        else if (i == 2 || i == 12 || i == 22)
            m_texts.AddTextContainer("3", fontTitle, 18, Color::Black, xIconPrevPosition + 116, 560 + (i - 2) * 4);
        else if (i == 3 || i == 13 || i == 23)
            m_texts.AddTextContainer("4", fontTitle, 18, Color::Black, xIconPrevPosition + 165, 560 + (i - 3) * 4);
        else if (i == 4 || i == 14 || i == 24)
            m_texts.AddTextContainer("5", fontTitle, 18, Color::Black, xIconPrevPosition + 217, 560 + (i - 4) * 4);
        else if (i == 5 || i == 15 || i == 25)
            m_texts.AddTextContainer("6", fontTitle, 18, Color::Black, xIconPrevPosition + 268, 560 + (i - 5) * 4);
        else if (i == 6 || i == 16 || i == 26)
            m_texts.AddTextContainer("7", fontTitle, 18, Color::Black, xIconPrevPosition + 320, 560 + (i - 6) * 4);
        else if (i == 7 || i == 17 || i == 27)
            m_texts.AddTextContainer("8", fontTitle, 18, Color::Black, xIconPrevPosition + 368, 560 + (i - 7) * 4);
        else if (i == 8 || i == 18 || i == 28)
            m_texts.AddTextContainer("9", fontTitle, 18, Color::Black, xIconPrevPosition + 418, 560 + (i - 8) * 4);
        else if (i == 9 || i == 19 || i == 29)
            m_texts.AddTextContainer("10", fontTitle, 18, Color::Black, xIconPrevPosition + 466, 560 + (i - 9) * 4);
        else if (i == 30)
            m_texts.AddTextContainer("1", fontTitle, 18, Color::Black, xIconPrevPosition + 42, 680 + (i - 30) * 4);
        else if (i == 31)
            m_texts.AddTextContainer("2", fontTitle, 18, Color::Black, xIconPrevPosition + 144, 680 + (i - 31) * 4);
        else if (i == 32)
            m_texts.AddTextContainer("3", fontTitle, 18, Color::Black, xIconPrevPosition + 240, 680 + (i - 32) * 4);
        else if (i == 33)
            m_texts.AddTextContainer("4", fontTitle, 18, Color::Black, xIconPrevPosition + 340, 680 + (i - 33) * 4);
        else if (i == 34)
            m_texts.AddTextContainer("5", fontTitle, 18, Color::Black, xIconPrevPosition + 445, 680 + (i - 34) * 4);
    }*/

    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 22, yIconPrevPosition + 750, 1.3, 1.3);
    m_texts.AddTextContainer("Ghe chon:", fontTitle, 22, Color::Black, xIconPrevPosition, yIconPrevPosition + 758);
    m_texts.AddTextContainer("Tam tinh:", fontTitle, 22, Color::Black, xIconPrevPosition, yIconPrevPosition + 790);
}

ThirdPage::~ThirdPage(){}

void ThirdPage::draw(RenderWindow& window)
{
    m_blocks.Render(window);
    m_texts.Render(window);
}

bool ThirdPage::prevButtonIsPressed(RenderWindow& window) {


    BlockComponent prevIcon("images/data/ke-kien-tao.png", 40.0f, 44.0f, 0.22, 0.2);

    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousePos = Mouse::getPosition(window);
        if (prevIcon.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
            return true;
        }
    }

    return false;
}


bool ThirdPage::nextButtonIsPressed(RenderWindow& window) {
    float xIconPrevPosition = 40.0f;
    float yIconPrevPosition = 35.0f;
    BlockComponent nextIcon("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 380, 0.3, 0.3);

    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousePos = Mouse::getPosition(window);
        if (nextIcon.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
            return true;
        }
    }
    return false;
}

struct Seat {
    BlockComponent block;
    bool isSelected;
    Seat() : block("images/bg-gray.png", 0.0f, 0.0f, 0.1, 0.1), isSelected(false) {}
};

//vector<int> ThirdPage::seatSelected(RenderWindow& window) {
//    
//    float xScale = 0.1;
//    float yScale = 0.1;
//    float xPos;
//    float yPos;
//    float xIconPrevPosition = 40.0f;
//    float yIconPrevPosition = 35.0f;
//
//    vector<Seat> seats;
//
//    for (int i = 0; i < 35; i++) {
//        if (i <= 9) {
//            xPos = 40 + i * 50;
//            yPos = yIconPrevPosition + 520;
//        }
//        else if (i <= 19) {
//            xPos = 40 + (i - 10) * 50;
//            yPos = yIconPrevPosition + 560;
//        }
//        else if (i <= 29) {
//            xPos = 40 + (i - 20) * 50;
//            yPos = yIconPrevPosition + 600;
//        }
//        else if (i <= 34) {
//            xPos = 40 + (i - 30) * 100;
//            yPos = yIconPrevPosition + 640;
//            xScale = 0.2;
//        }
//        Seat m_seat;
//        m_seat.block = BlockComponent("images/bg-gray.png", xPos, yPos, xScale, yScale);
//        seats.push_back(m_seat);
//    }
//
//    
//
//    if (Mouse::isButtonPressed(Mouse::Left)) {
//        Vector2i mousePos = Mouse::getPosition(window);
//        for (Seat& seat : seats)
//        {
//            if (seat.block.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
//            {
//                // Đổi màu ghế và cập nhật trạng thái isSelected
//                if (seat.isSelected) {
//                    /*seat.block.setFillColor(Color::White);*/
//                    seat.isSelected = false;
//                    // Xóa ghế ra khỏi dữ liệu nếu bị hủy chọn
//                }
//                else {
//                    //seat.block.setColor(sf::Color::Red);
//                    seat.isSelected = true;
//                    // Lưu ghế vào dữ liệu khi được chọn
//                }
//                break;  // Dừng kiểm tra khi đã tìm thấy ghế
//            }
//        }
//    }
//
//    vector<int> index;
//    for (int i = 0; i < 35; i++) {
//        if (seats[i].isSelected) index.push_back(i);
//    }
//
//    return index;
//}



vector<int> ThirdPage::seatSelected(RenderWindow& window) {
    float xScale = 0.1;
    float yScale = 0.1;
    float xIconPrevPosition = 40.0f;
    float yIconPrevPosition = 35.0f;

    vector<Seat> seats;

    for (int i = 0; i < 35; i++) {
        float xPos, yPos;
        if (i <= 9) {
            xPos = 40 + i * 50;
            yPos = yIconPrevPosition + 520;
        }
        else if (i <= 19) {
            xPos = 40 + (i - 10) * 50;
            yPos = yIconPrevPosition + 560;
        }
        else if (i <= 29) {
            xPos = 40 + (i - 20) * 50;
            yPos = yIconPrevPosition + 600;
        }
        else if (i <= 34) {
            xPos = 40 + (i - 30) * 100;
            yPos = yIconPrevPosition + 640;
            xScale = 0.2;
        }
        Seat m_seat;
        m_seat.block = BlockComponent("images/bg-gray.png", xPos, yPos, xScale, yScale);
        seats.push_back(m_seat);
    }

    static bool mousePressed = false;

    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (!mousePressed) {
            mousePressed = true;

            Vector2i mousePos = Mouse::getPosition(window);
            for (Seat& seat : seats) {
                if (seat.block.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    seat.isSelected = !seat.isSelected;
                    break;
                }
            }
        }
    }
    else {
        mousePressed = false;
    }

    vector<int> index;
    for (int i = 0; i < 35; i++) {
        if (seats[i].isSelected) index.push_back(i);
    }

    return index;
}
