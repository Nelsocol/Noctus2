#include "NoctusParser.h"

void NoctusParser::ParseString(std::string text, std::list<TextFragment>* outList) 
{
	TextFragment* fragment = new TextFragment(text);
	outList->push_back(*fragment);
}