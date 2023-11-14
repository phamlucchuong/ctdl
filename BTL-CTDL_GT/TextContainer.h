#include <iostream>
#include <vector>
#include "TextComponent.h"
#include "I_Component.h"
using namespace std;
#pragma once
class TextContainer
{
private:
    string m_name;
    vector<shared_ptr<I_Component>> m_components;

public:
    TextContainer(string name);
    ~TextContainer() {}
    void AddTextContainer(string text, Font &font, unsigned int size, Color color, float xPosotion, float yPosotion);
    void Render(RenderWindow &ref);
};
