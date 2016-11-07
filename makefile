all:
	gcc -c PID_test.c
	gcc -o PID_test PID_test.o

clean:
	rm PID_test.o
	rm PID_test

