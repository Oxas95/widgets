ISFML = -I/usr/local/include
LSFML = -lsfml-graphics -lsfml-window -lsfml-system -L/usr/local/lib
RSFML = export LD_LIBRARY_PATH=/usr/local/lib &&

ficCpp = main.cpp	fenetre.cpp		widget.cpp	button.cpp
ficH   = 			fenetre.hpp 	widget.hpp	button.hpp
ficO   = main.o		fenetre.o		widget.o	button.o

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

button.o: button.cpp button.hpp widget.hpp fenetre.hpp
	g++ -c -g -Wall button.cpp button.hpp widget.hpp fenetre.hpp $(ISFML)

fenetre.o: fenetre.cpp fenetre.hpp
	g++ -c -g -Wall fenetre.cpp fenetre.hpp $(ISFML)

main.o: main.cpp fenetre.hpp
	g++ -c -g -Wall main.cpp fenetre.hpp $(ISFML)

widget.o: widget.cpp widget.hpp fenetre.hpp
	g++ -c -g -Wall widget.cpp widget.hpp fenetre.hpp $(ISFML)

clean:
	rm -fR *.o main *.gch

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
