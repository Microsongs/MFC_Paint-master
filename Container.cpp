#include "stdafx.h"
#include "Container.h"
#include "View.h"

Container::Container()
{
}

Container::Container(int x, int y, int sizex, int sizey, std::string title)
	:Component(x, y, sizex, sizey, title)
{

}

Container::Container(View *v) {
	m_view = v;
}

void Container::clicked() {
	debugOutput("구현 전용\n");
}


void Container::addComponent(Component* component) {
	m_list.push_back(component);
}

void Container::draw() {
	for (auto i : m_list) {
		i->draw();
	}
}

Component* Container::find(int x, int y) {
	for (auto b : m_list) {
		if (b->inside(x, y))
			return b;
	}
	return nullptr;
}

void Container::onMouseMove(MyEvent e) {
	debugOutput("이 것은 사용하지 않는 추상메서드입니다.");
}

Container::~Container()
{
}

/*

void Container::addComponent(Component* e){
	m_list.push_back(e);
	e->setContainer(this);
	reposition();
}

void Container::reposition(){
	//Do nothing by default;
}

bool Container::onMouseDown(Event e){
	for(auto b : m_list){
		if(b->onMouseDOwn(e)){
			return true;
		}
	if(inside(e.x,e.y))
		getViewInstance->setLastPressed(this));
}

bool Container::onMouseMove(Event e){
	for(auto b : m_list){
		if(b->onMouseMove(e)){	//반환값이 true이면 처리한 것
			return true;
		}
	}
}

bool Container::onMouseUp(Event e){
	for(auto b : m_list){

*/