COMPILE = g++
FLAGS = -W -Wall -Werror
OBJS = Warrior.o Wizard.o Elf.o

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.exe main.cpp $(OBJS)

Warrior.o: Warrior.cpp Warrior.h Character.h
	$(COMPILE) $(FLAGS) -c Warrior.cpp

Wizard.o: Wizard.cpp Wizard.h Character.h
	$(COMPILE) $(FLAGS) -c Wizard.cpp

Elf.o: Elf.cpp Elf.h Character.h
	$(COMPILE) $(FLAGS) -c Elf.cpp

clean:
	rm -rf *.o a.exe
