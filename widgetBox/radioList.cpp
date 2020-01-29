#include "radioList.hpp"

RadioList::RadioList(sf::RenderWindow& f) : Widget(f), ListWidget(f) {
	activatedID = -1;
	type = radioList;
}

RadioList::~RadioList(){
	
}

void RadioList::addWidget(RadioButton* rb){
	ListWidget::addWidget(rb);
	if(sizeList == 1){
		activatedID = widgetList->widget->getID();
	}
}

void RadioList::delWidget(){
	ListWidget::delWidget();
}

void RadioList::delWidgetID(int ID){
	ListWidget::delWidgetID(ID);
}

int RadioList::getSizeList(){
	return sizeList;
}

RadioButton* RadioList::getWidget(int i){
	return (RadioButton*) ListWidget::getWidget(i);
}

RadioButton* RadioList::getWidgetWithID(int ID){
	return (RadioButton*) getWidgetWithID(ID);
}

int RadioList::getActivatedID(){
	return activatedID;
}

void RadioList::eventNdraw(sf::Vector2i& posClic){
	Listwidget* ml = widgetList;
	RadioButton* activatedRB = NULL;
	RadioButton* tmp = NULL;
	RadioButton* rb = NULL;
	while(ml){
		ml->widget->eventNdraw(posClic);
		tmp = (RadioButton*) ml->widget;
		if(tmp->isPushed() && tmp->getID() != activatedID){
			rb = tmp;
		}
		if(tmp->getID() == activatedID){
			activatedRB = tmp;
		}
		ml = ml->next;
	}
	if(rb){
		activatedRB->activated = false;
		activatedID = rb->getID();
	}
	else activatedRB->activated = true;
}

widgetType RadioList::getWidgetType(){
	return type;
}
