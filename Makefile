CC=gcc
AR=ar
OBGECT_STATIC_LIB_LOOP= basicClassification.o advancedClassificationLoop.o
OBGECT_STATIC_LIB_RECURS= basicClassification.o advancedClassificationRecursion.o
OBGECT_DYNAMIC_LIB_LOOP= basicClassification.o advancedClassificationLoop.o
OBGECT_DYNAMIC_LIB_RECURS= basicClassification.o advancedClassificationRecursion.o
FLAGS=-g -Wall

all:libclassloops.a libclassrec.a libclassloops.so libclassrec.so mains maindloop maindrec
#all: loops loopd recursives recursived mains maindloop maindrec

#creat libraries
loops:libclassloops.a
libclassloops.a:$(OBGECT_STATIC_LIB_LOOP)
	$(AR) -rcs libclassloops.a $(OBGECT_STATIC_LIB_LOOP)
recursives:libclassrec.a
libclassrec.a:$(OBGECT_STATIC_LIB_RECURS)
	$(AR) -rcs libclassrec.a $(OBGECT_STATIC_LIB_RECURS)
loopd: libclassloops.so
libclassloops.so:$(OBGECT_DYNAMIC_LIB_LOOP)
	$(CC) -shared -o libclassloops.so $(OBGECT_DYNAMIC_LIB_LOOP)
recursived: libclassrec.so
libclassrec.so:$(OBGECT_DYNAMIC_LIB_RECURS)
	$(CC) -shared -o libclassrec.so $(OBGECT_DYNAMIC_LIB_RECURS)

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

#creat main
mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so 
maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm *.o *.a *.so mains maindloop maindrec
