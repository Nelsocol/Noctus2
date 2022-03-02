#pragma once

#include <string>
#include <list>
#include <iostream>

#include "TextFragment.h"

class NoctusParser
{
public:
	void ParseString(std::string text, std::list<TextFragment>* outList);
};
