#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"

class ThirdPage
{
private:
	int selectedItemIndex;
	Font font;
	Font fontFilmName;
	Font fontTitle;
	Font fontDesc;
	Font fontHeader;
	Text menu[50];
	vector<int> seatIndex;
	BlockContainer m_blocks;
	TextContainer m_texts;

public:
	ThirdPage(vector<int> seats);
	~ThirdPage();
	void draw(RenderWindow& window);
	bool prevButtonIsPressed(RenderWindow& window, Vector2i mousePos);
	bool nextButtonIsPressed(RenderWindow& window, Vector2i mousePos);
	int seatSelected(RenderWindow& window, Vector2i mousePos);
	void changeSeatColor(vector<int> seatIndex);
	void eraseSeatColor(int seatErase);
};