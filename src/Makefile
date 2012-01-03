all: ccnd main
ccnd: 
	gcc ccnd.c -o bin/ccnd -lpthread

main: 
	gcc main.c ccn.c -o bin/main -lpthread

clean:
	rm -rf bin/*

