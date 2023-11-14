#include <iostream>
#include "I_Component.h"
using namespace std;

#pragma once
class FontComponent : public I_Component
{
public:
	FontComponent(string fontpath) {
		fontType.loadFromFile(fontpath);
	}
	~FontComponent() {};
private:
	Font fontType;
};