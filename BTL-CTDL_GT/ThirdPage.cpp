#include "ThirdPage.h"


ThirdPage::ThirdPage(vector<int> seats) : m_blocks("third"), m_texts("third")
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


    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 380, 0.3, 0.3);
    m_blocks.AddBlockContainer("images/img-screen.png", xIconPrevPosition + 10, yIconPrevPosition + 450, 0.7, 0.7);


    for (int i = 0; i < 35; i++) {
        float xPos;
        float yPos;
        float xScale = 0.1;
        float yScale = 0.1;
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
        m_blocks.AddBlockContainer("images/bg-gray.png", xPos, yPos, xScale, yScale);
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

bool ThirdPage::prevButtonIsPressed(RenderWindow& window, Vector2i mousePos) {


    BlockComponent prevIcon("images/data/ke-kien-tao.png", 40.0f, 44.0f, 0.22, 0.2);

    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousePos = Mouse::getPosition(window);
        if (prevIcon.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
            return true;
        }
    }

    return false;
}


bool ThirdPage::nextButtonIsPressed(RenderWindow& window, Vector2i mousePos) {
    float xIconPrevPosition = 40.0f;
    float yIconPrevPosition = 35.0f;
    BlockComponent nextIcon("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 380, 0.3, 0.3);

    if (nextIcon.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
        return true;
    } else return false;
}


int ThirdPage::seatSelected(RenderWindow& window, Vector2i mousePos) {

    float xScale = 0.1;
    float yScale = 0.1;
    float xIconPrevPosition = 40.0f;
    float yIconPrevPosition = 35.0f;

    vector<BlockComponent> seats;

    for (int i = 0; i < 35; i++) {
        float xPos;
        float yPos;
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
        if (i > 28) yScale = 0.2;
        BlockComponent m_seat("images/bg-gray.png", xPos, yPos, xScale, yScale);
        seats.push_back(m_seat);
    }

    for (int i = 0; i < 35; i++) {
        if (seats[i].getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
            //cout << "Click on seat" << endl;
            return i;
        }
    }

    //cout << "Click outside any seat" << endl;
    return -1;
}

void ThirdPage::changeSeatColor(vector<int> seatIndex) {
    for (int i = 0; i < 35; i++) {
        float xPos;
        float yPos;
        float xSeatIndexScale = 0.7f;
        float ySeatIndexScale = 0.65f;
        float xScale = 0.1f;
        float yScale = 0.1f;
        float xIconPrevPosition = 40.0f;
        float yIconPrevPosition = 35.0f;
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
            xScale = 0.2f;
            xSeatIndexScale = 1.3f;
        }
        m_blocks.AddBlockContainer("images/bg-gray.png", xPos, yPos, xScale, yScale);
        for (int temp : seatIndex) {
            if (i == temp) {
                m_blocks.AddBlockContainer("images/bg-gray-hover.png", xPos, yPos, xSeatIndexScale, ySeatIndexScale);
            }
        }
    }
}