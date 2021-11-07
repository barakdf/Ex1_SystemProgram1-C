CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB_REC=advancedClassificationRecursion.o
OBJECTS_LIB_LOOP=advancedClassificationLoop.o
FLAGS= -Wall -g
LDLIBS= -lm

all: libclassloops.a libclassloops.so libclassrec.a libclassrec.so maindrec maindloop mains

recursives: libclassrec.a

recursived: libclassrec.so

loops: libclassloops.a

loopd: libclassloops.so

# Executives -->

mains: $(OBJECTS_MAIN)  libclassrec.a
	$(CC) $(FLAGS) -o mains  $(OBJECTS_MAIN) libclassrec.a $(LDLIBS)

maindloop: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindloop  $(OBJECTS_MAIN) ./libclassloops.so $(LDLIBS)

maindrec: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindrec  $(OBJECTS_MAIN) ./libclassrec.so $(LDLIBS)

# Libraries -->

libclassrec.so: $(OBJECTS_MAIN) $(OBJECTS_LIB_REC) basicClassification.o
	$(CC) -shared  -o libclassrec.so $(OBJECTS_MAIN) $(OBJECTS_LIB_REC) basicClassification.o $(LDLIBS)

libclassrec.a: $(OBJECTS_LIB_REC) basicClassification.o
	$(AR) -rcs libclassrec.a $(OBJECTS_LIB_REC) basicClassification.o

libclassloops.so: $(OBJECTS_MAIN) $(OBJECTS_LIB_LOOP) basicClassification.o
	$(CC) -shared  -o libclassloops.so $(OBJECTS_MAIN) $(OBJECTS_LIB_LOOP) basicClassification.o $(LDLIBS)

libclassloops.a: $(OBJECTS_LIB_LOOP) basicClassification.o
	$(AR) -rcs libclassloops.a  $(OBJECTS_LIB_LOOP) basicClassification.o

# Compile ".c" files -->

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c 

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

# Clean & All -->

.PHONY: clean all

clean:
	rm -f *.o *.a *.so maindrec maindloop mains