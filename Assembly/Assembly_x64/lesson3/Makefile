runme: main.cpp asmNASM.o asmGAS.o
	g++ main.cpp asmNASM.o asmGAS.o -o runme

asmNASM.o: asmNASM.asm
	nasm -f elf64 asmNASM.asm -o asmNASM.o

asmGAS.o: asmGAS.asm
	as asmGAS.asm -o asmGAS.o

clean:
	rm asmNASM.o asmGAS.o runme