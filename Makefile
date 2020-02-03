ISFML = -I/usr/local/include
LSFML = -lsfml-graphics -lsfml-window -lsfml-system -L/usr/local/lib
RSFML = export LD_LIBRARY_PATH=/usr/local/lib &&

ficCpp = main.cpp	fenetre.cpp		widget.cpp	widgetBox/buttonRect.cpp	managerGUI.cpp	widgetBox/widgetBox.cpp	widgetBox/buttonCircle.cpp	$(ficCpp2)
ficH   = 			fenetre.hpp 	widget.hpp	widgetBox/buttonRect.hpp	managerGUI.hpp	widgetBox/widgetBox.hpp	widgetBox/buttonCircle.hpp	$(ficH2)

ficCpp2	= widgetBox/textArea.cpp	widgetBox/radioButton.cpp	listWidget.cpp	widgetBox/radioList.cpp	widgetBox/radioBox.cpp	dynamicWidget/dynamicWidget.cpp	$(ficCpp3)
ficH2	= widgetBox/textArea.hpp	widgetBox/radioButton.hpp	listWidget.hpp	widgetBox/radioList.hpp	widgetBox/radioBox.hpp	dynamicWidget/dynamicWidget.hpp	$(ficH3)

ficCpp3 = dynamicWidget/deplacable.cpp
ficH3 = dynamicWidget/deplacable.hpp

default: reset main

all: reset main clear run

run:
	$(RSFML) ./main

debug:
	$(RSFML) valgrind ./main

reset:
	reset

clear:
	clear

clean:
	rm -fv *.gch widgetBox/*.gch dynamicWidget/*.gch *.o main 

install:
	chmod +x libs/install.sh
	libs/install.sh

#SFML est installé dans /usr/local

git:
	git add -A
	git commit
	git push

tar_gz: clean
	rm -fr ../projet_cpp
	rm -f ../Projet_cpp_Bazin-Lapegue-De_Jesus.tar.gz
	mkdir ../projet_cpp
	cp -r * ../projet_cpp
	tar czvf ../Projet_cpp_Bazin-Lapegue-De_Jesus.tar.gz ../projet_cpp
	rm -fr ../projet_cpp

main: clean clear
	g++ -g -Wall $(ficCpp) $(ficH) $(ISFML) $(LSFML) -o main
