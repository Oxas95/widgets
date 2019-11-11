ISFML = -I/usr/local/include
LSFML = -lsfml-graphics -lsfml-window -lsfml-system -L/usr/local/lib
RSFML = export LD_LIBRARY_PATH=/usr/local/lib &&

ficCpp = main.cpp	fenetre.cpp		widget.cpp	widgetBox/buttonRect.cpp	managerGUI.cpp	widgetBox/widgetBox.cpp	widgetBox/buttonCircle.cpp	
ficH   = 			fenetre.hpp 	widget.hpp	widgetBox/buttonRect.hpp	managerGUI.hpp	widgetBox/widgetBox.hpp	widgetBox/buttonCircle.hpp	
ficO   = main.o		fenetre.o		widget.o	buttonRect.o				managerGUI.o	widgetBox.o				buttonCircle.o				

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

main: $(ficO)
	g++ -g -Wall $(ficO) $(LSFML) -o main
	rm -f *.gch

buttonCircle.o: widgetBox/buttonCircle.cpp widgetBox/buttonCircle.hpp widget.hpp widgetBox/widgetBox.hpp
	g++ -c -g -Wall widgetBox/buttonCircle.cpp widgetBox/buttonCircle.hpp widget.hpp widgetBox/widgetBox.hpp $(ISFML)

buttonRect.o: widgetBox/buttonRect.cpp widgetBox/buttonRect.hpp widget.hpp widgetBox/widgetBox.hpp
	g++ -c -g -Wall widgetBox/buttonRect.cpp widgetBox/buttonRect.hpp widget.hpp widgetBox/widgetBox.hpp $(ISFML)

fenetre.o: fenetre.cpp fenetre.hpp
	g++ -c -g -Wall fenetre.cpp fenetre.hpp $(ISFML)

main.o: main.cpp fenetre.hpp
	g++ -c -g -Wall main.cpp fenetre.hpp $(ISFML)

managerGUI.o: managerGUI.cpp managerGUI.hpp widget.hpp
	g++ -c -g -Wall managerGUI.cpp managerGUI.hpp widget.hpp $(ISFML)

widget.o: widget.cpp widget.hpp
	g++ -c -g -Wall widget.cpp widget.hpp $(ISFML)

widgetBox.o: widgetBox/widgetBox.cpp widgetBox/widgetBox.hpp widget.hpp
	g++ -c -g -Wall widgetBox/widgetBox.cpp widgetBox/widgetBox.hpp widget.hpp $(ISFML)

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

main2:
	g++ -g -Wall $(ficCpp) $(ficH) $(ISFML) $(LSFML) -o main
