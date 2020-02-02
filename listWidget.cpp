#include "listWidget.hpp"
#include <stdio.h>
#include <stdlib.h>

ListWidget::ListWidget() {
	widgetList = NULL;
	sizeList = 0;
}

ListWidget::~ListWidget(){
	while(widgetList) delWidget();
	printf("listWidget deleted\n");
}

//ajoute en début de liste un widget
void ListWidget::addWidget(Widget* w) {
	Listwidget* newWidget = new Listwidget();
	newWidget->widget = w;
	newWidget->next = widgetList;
	widgetList = newWidget;
	sizeList++;
}

//supprime le widget au début de la liste, la mémoire n'est pas désallouée
void ListWidget::delWidget() {
	if(widgetList){
		Listwidget* del = widgetList;
		widgetList = widgetList->next;
		delete del;
		sizeList--;
	}
}

Listwidget* delWidgetIDInList(Listwidget* ml, int ID){
	if(!ml) return NULL;
	else if(ml->widget->getID() == ID){
		Listwidget* del = ml;
		ml = ml->next;
		delete del;
		return ml;
	}
	else {
		ml->next = delWidgetIDInList(ml->next, ID);
		return ml;
	}
}

void ListWidget::delWidgetID(int ID){
	widgetList = delWidgetIDInList(widgetList, ID);
}

int ListWidget::getSizeList(){
	return sizeList;
}

Widget* ListWidget::getWidget(int i){
	if(i < 0 || i >= sizeList) return NULL;
	Listwidget* ml = widgetList;
	for(int j = 0; j < i; j++) ml = ml->next;
	return ml->widget;
}

Widget* ListWidget::getWidgetWithID(int ID){
	Listwidget* ml = widgetList;
	for(int j = 0; j < sizeList; j++) {
		if(ml->widget->getID() != ID) ml = ml->next;
		else j = sizeList;
	}
	return ml->widget;
}
