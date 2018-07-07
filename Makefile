pa2: hunter.o monster.o palico.o hunterbook.o monsterbook.o palicobook.o sword.o equipment.o bmplib.o monsterhunter.o point.o champion.o
	g++ -g -pthread -std=c++11 hunter.o monster.o palico.o hunterbook.o monsterbook.o palicobook.o sword.o equipment.o bmplib.o monsterhunter.o point.o champion.o -o pa3 

hunter.o: hunter.cpp 
	g++ -std=c++11 -c hunter.cpp 

palico.o: palico.cpp 
	g++ -std=c++11 -c palico.cpp

monster.o: monster.cpp 
	g++ -std=c++11 -c monster.cpp

monsterbook.o: monsterbook.cpp 
	g++ -std=c++11 -c monsterbook.cpp

hunterbook.o: hunterbook.cpp 
	g++ -std=c++11 -c hunterbook.cpp

palicobook.o: palicobook.cpp 
	g++ -std=c++11 -c palicobook.cpp

sword.o: sword.cpp 
	g++ -std=c++11 -c sword.cpp

equipment.o: equipment.cpp 
	g++ -std=c++11 -c equipment.cpp

bmplib.o: bmplib.cpp 
	g++ -std=c++11 -c bmplib.cpp

monsterhunter.o: monsterhunter.cpp
	g++ -std=c++11 -c monsterhunter.cpp

point.o: point.cpp
	g++ -std=c++11 -c point.cpp

champion.o: champion.cpp
	g++ -std=c++11 -c champion.cpp

clean:
	rm -f hunter.o monster.o palico.o hunterbook.o monsterbook.o palicobook.o sword.o equipment.o bmplib.o monsterhunter.o point.o champion.o pa2 