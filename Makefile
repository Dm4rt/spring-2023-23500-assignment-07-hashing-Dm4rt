OBJECTS = main.o Dictionary.o List.o Node.o Person.o
TEST_OBJECTS = tests.o Dictionary.o List.o Node.o Person.o

main: $(OBJECTS)
	g++ -o main $(OBJECTS)

tests: $(TEST_OBJECTS)
	g++ -o tests $(TEST_OBJECTS)
main.o: main.cpp Dictionary.h List.h Node.h Person.h

tests.o: tests.cpp Dictionary.h List.h Node.h Person.h

Dictionary.o: Dictionary.cpp Dictionary.h List.h Node.h Person.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

Person.o: Person.cpp Person.h

clean:
	rm -f $(OBJECTS) 
