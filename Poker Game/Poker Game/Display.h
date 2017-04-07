#pragma once

#ifndef DISPLAY_H
#define DISPLAY_H

#include<string>
#include"Card.h"

using namespace std;

class Display
{
public:
	string suit(CARD);
	string symbol(int, CARD);
	Display();
	~Display();

};
#endif // !DISPLAY_H