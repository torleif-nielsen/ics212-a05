all: hw5
hw5: driver.o iofunctions.o iofunctions.h account.h
	gcc -Wall -ansi -o hw5 driver.o iofunctions.o

driver.o: driver.c
	gcc -Wall -ansi -c driver.c

iofunctions.o: iofunctions.c
	gcc -Wall -ansi -c iofunctions.c

clean:
	rm *.o hw5
	
