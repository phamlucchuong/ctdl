#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"

class SecondaryPage
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
	SecondaryPage(int num);
	~SecondaryPage();
	void draw(RenderWindow& window);
	bool prevButtonIsPressed(RenderWindow& window);
	bool nextButtonIsPressed(RenderWindow& window);
	// void Hover();
	// void Blur();
	// int GetPressedItem() { return selectedItemIndex; }
};