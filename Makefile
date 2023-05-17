OBJECTS = main.o Dictionary.o List.o Node.o Person.o

main: $(OBJECTS)
	g++ -o main $(OBJECTS)

main.o: main.cpp Dictionary.h List.h Node.h Person.h

Dictionary.o: Dictionary.cpp Dictionary.h List.h Node.h Person.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

Person.o: Person.cpp Person.h

clean:
	rm -f $(OBJECTS) 
