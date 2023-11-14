#include "setFont.h"
setFontType::setFontType(string fontType) {
	if (fontType == "Bold") {
		this->font.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
	}
	else if (fontType == "Regular") {
		this->font.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
	}
	else if (fontType == "Medium") {
		this->font.loadFromFile("fonts/Montserrat/Montserrat-Medium.ttf");
	}
	else if (fontType == "Light") {
		this->font.loadFromFile("fonts/Montserrat/Montserrat-Light.ttf");
	}
}
Font setFontType::getFont() {
	return font;
}