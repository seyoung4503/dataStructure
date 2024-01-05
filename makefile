# DLL.out : DLL.o main.o
# 	gcc -o DLL.out DLL.o main.o

# DLL.o : DLL.c
# 	gcc -c -o DLL.o DLL.c

# main.o : main.c
# 	gcc -c -o main.o main.c

# clean:
# 	rm *.o DLL.out


# # stack
# stack.out : ArrayStack.o main.o
# 	gcc -o stack.out ArrayStack.o main.o

# DLL.o : ArrayStack.c
# 	gcc -c -o ArrayStack.o ArrayStack.c

# main.o : main.c
# 	gcc -c -o main.o main.c

# clean:
# 	rm *.o stack.out

# # queue
# queue.out : CircularQueue.o main.o
# 	gcc -o queue.out CircularQueue.o main.o

# DLL.o : CircularQueue.c
# 	gcc -c -o CircularQueue.o CircularQueue.c

# main.o : main.c
# 	gcc -c -o main.o main.c

# clean:
# 	rm *.o queue.out


# LCRS
lcrs.out : LCRS.o main.o
	gcc -o lcrs.out LCRS.o main.o

DLL.o : LCRS.c
	gcc -c -o LCRS.o LCRS.c

main.o : main.c
	gcc -c -o main.o main.c

clean:
	rm *.o lcrs.out