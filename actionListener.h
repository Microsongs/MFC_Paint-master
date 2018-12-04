#pragma once

class myView;
class Component;

class actionListener	//inteface
{
public:
	virtual void actionPerformed(Component*) = 0;
	//virtual void actionPerformed();
};

class tButtonActionListener : public actionListener {	//구현
protected:
	myView* m_view;
public:
	tButtonActionListener(myView* v);
	void actionPerformed(Component*);
};

class menuItemActionListener : public actionListener {	//구현
private:
	myView* m_view;
public:
	menuItemActionListener(myView* v);
	void actionPerformed(Component*);
};