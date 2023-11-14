#include <iostream>
#include <vector>
#include "FontComponent.h"
#include "I_Component.h"
using namespace std;

#pragma once
class FontContainer
{
public:
    FontContainer(string name) {
        m_name = name;
    }
    ~FontContainer(){}
    void AddFont(string fontPath) {
        shared_ptr<FontComponent> item = make_shared<FontComponent>(fontPath);
        m_components.push_back(item);
    }
private:
    string m_name;
    vector<shared_ptr<I_Component>> m_components;
};

