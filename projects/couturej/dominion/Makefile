CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

cardtest1: dominion.c rngs.c
	gcc -coverage -fpic dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g	
	
cardtest2:
	gcc -coverage -fpic dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g	
	
cardtest3:
	gcc -coverage -fpic dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g	
	
cardtest4:
	gcc -coverage -fpic dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g		
	
unittest1: 
	gcc -coverage -fpic dominion.c unittest1.c rngs.c -o unittest1 -lm -g
unittest2:
	gcc -coverage -fpic  dominion.c unittest2.c rngs.c -o unittest2 -lm -g

unittest3:
	gcc -coverage -fpic dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unittest4:
	gcc -coverage -fpic dominion.c unittest4.c rngs.c -o unittest4 -lm -g	


	
unittestresults.out: 
	cardtest1 &> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cardtest2 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cardtest3 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cardtest4 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	unittest1 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	unittest2 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	unittest3 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	unittest4 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	
all: playdom player testDrawCard testBuyCard badTestDrawCard unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *gcda unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4	*.gcov *.gcda *.gcno *.so *.out
