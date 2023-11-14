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
	BlockContainer m_blocks;
	TextContainer m_texts;

public:
	ThirdPage();
	~ThirdPage();
	void draw(RenderWindow& window);
	bool prevButtonIsPressed(RenderWindow& window);
	bool nextButtonIsPressed(RenderWindow& window);
	vector<int> seatSelected(RenderWindow& window);
};