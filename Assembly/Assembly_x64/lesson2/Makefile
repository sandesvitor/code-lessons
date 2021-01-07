runme: main.cpp asm.o
	g++ main.cpp asm.o -o runme	

asm.o: asm.asm
	as asm.asm -o asm.o

clean:
	rm runme asm.o
