libraryMethod.out : libraryMethod.o main.o
    gcc -o libraryMethod.out libraryMethod.o main.o
    
libraryMethod.o : libraryMethod.c
    gcc -c -o libraryMethod.o libraryMethod.c
    
main.o : main.c
    gcc -c -o main.o main.c
    
clean:
    rm *.o libraryMethod.out