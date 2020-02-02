#ifndef listWidget_hpp
#define listWidget_hpp

#include "fenetre.hpp"
#include "widget.hpp"

typedef struct Listwidget{
	Widget* widget;
	Listwidget* next;
} Listwidget;

class ListWidget {
	protected :
		int sizeList;
		Listwidget* widgetList;
	
	public :
		ListWidget();
		virtual ~ListWidget();
		
		virtual void addWidget(Widget* w);
		virtual void delWidget();
		virtual void delWidgetID(int ID);
		virtual int getSizeList();
		virtual Widget* getWidget(int i);
		virtual Widget* getWidgetWithID(int ID);
};

#endif //listWidget_hpp
