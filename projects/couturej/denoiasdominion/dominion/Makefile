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
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g	
	
cardtest2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g	
	
cardtest3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g	
	
cardtest4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g		
	
unittest1: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g
unittest2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g

unittest3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unittest4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g	

randomtestadventurer: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestadventurer.c rngs.c -o randomtestadventurer -lm -g
				
randomtestcard1: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard1.c rngs.c -o randomtestcard1 -lm -g

randomtestcard2: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard2.c rngs.c -o randomtestcard2 -lm -g

	
cardtest1.out:
	./cardtest1 &> cardtest1.out
	gcov dominion.c >> cardtest1.out
	cat dominion.c.gcov >> cardtest1.out

cardtest2.out:
	./cardtest2 &> cardtest2.out
	gcov dominion.c >> cardtest2.out
	cat dominion.c.gcov >> cardtest2.out
	
cardtest3.out:
	./cardtest3 &> cardtest3.out
	gcov dominion.c >> cardtest3.out
	cat dominion.c.gcov >> cardtest3.out
	
cardtest4.out:
	./cardtest4 &> cardtest4.out
	gcov dominion.c >> cardtest4.out
	cat dominion.c.gcov >> cardtest4.out
	
unittest1.out:
	./unittest1 &> unittest1.out
	gcov dominion.c >> unittest1.out
	cat dominion.c.gcov >> unittest1.out

unittest2.out:
	./unittest2 &> unittest2.out
	gcov dominion.c >> unittest2.out
	cat dominion.c.gcov >> unittest2.out
	
unittest3.out:
	./unittest3 &> unittest3.out
	gcov dominion.c >> unittest3.out
	cat dominion.c.gcov >> unittest3.out
	
unittest4.out:
	./unittest4 &> unittest4.out
	gcov dominion.c >> unittest4.out
	cat dominion.c.gcov >> unittest4.out
	
randomtestadventurer.out:
	./randomtestadventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestcard1.out:
	./randomtestcard1 &> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
	
randomtestcard2.out:
	./randomtestcard1 &> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out


all: playdom player testDrawCard testBuyCard badTestDrawCard unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestadventurer randomtestcard2

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *gcda unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4	*.gcov *.gcda *.gcno *.so *.out randomtestadventurer randomtestcard1 randomtestcard2 
