fib: fib.c
	gcc -o fib fib.c
	chmod +x fib
clean:
	rm fib

test: fib
	bash test.sh
