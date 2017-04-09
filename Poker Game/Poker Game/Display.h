/***********************************************************************************
*
* By: Ferrin Katz      
*
***********************************************************************************/  


#pragma once

#ifndef DISPLAY_H
#define DISPLAY_H

#include<string>
#include<iostream>
#include"Card.h"

using namespace std;

class Display
{
public:
	void suit(CARD);
	void symbol(int, CARD);
	string suitToFile(CARD);
	string symbolToFile(CARD);
	Display();
	~Display();

};
#endif // !DISPLAY_H
