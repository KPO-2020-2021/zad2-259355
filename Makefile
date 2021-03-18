

TRGDIR=.
OBJ=./obj
SRC=./src
INC=./inc
TESTS=./tests
TBIN=./tests/bin
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

# __start__: ${TRGDIR}/test_arytm_zesp
# 	${TRGDIR}/test_arytm_zesp  $(ARGS)

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/Statystyki.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/BazaTestu.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/Statystyki.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o 

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/LZespolona.hh inc/BazaTestu.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Statystyki.o: src/Statystyki.cpp 
	g++ -c ${FLAGS} -o ${OBJ}/Statystyki.o src/Statystyki.cpp

${OBJ}/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp

${OBJ}/BazaTestu.o: src/BazaTestu.cpp inc/BazaTestu.hh inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o src/BazaTestu.cpp

${OBJ}/WyrazenieZesp.o: src/WyrazenieZesp.cpp inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZesp.o src/WyrazenieZesp.cpp

${TBIN}/test_1: ${TBIN} ${OBJ}/LZespolona.o
	g++ -o ${TESTS}/bin/test_1 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test1.cpp ${OBJ}/LZespolona.o

${TBIN}/test_2: ${TBIN} ${OBJ}/LZespolona.o
	g++ -o ${TESTS}/bin/test_2 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test2.cpp ${OBJ}/LZespolona.o	

${TBIN}:
	mkdir ${TBIN}

test: ${TBIN}/test_1 ${TBIN}/test_2
	${TBIN}/test_1
	${TBIN}/test_2

run: 
	${TRGDIR}/test_arytm_zesp latwy

clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/* ${TBIN}/*
