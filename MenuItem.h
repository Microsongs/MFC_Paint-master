#pragma once
#include "Container.h"
#include "MyButton.h"
#include <list>
#include "actionListener.h"

class MenuItem : public MyButton
{
protected:
	list<actionListener*> m_listener;
public:
	//int modeChange();
	MenuItem(string title);
	void addActionListener(actionListener*);
	void clicked();
	~MenuItem();
};

