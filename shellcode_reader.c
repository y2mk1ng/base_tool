#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char code[] = \
"\x00\x00\x00\x11\x71\x31"; //type in any code here inside the ""

main(){
	printf("Shellcode length: %d", strlen(code));
	__asm__("movl $0xffffffff, %eax\n\t"
		"movl %eax, %ebx\n\t"
		"movl %eax, %ecx\n\t"
		"movl %eax, %edx\n\t"
		"movl %eax, %edi\n\t"
		"movl %eax, %esi\n\t"
		"movl %eax, %ebp\n\t"
		"movw $0x672b, (code+20)\n\t"
		"call code");
	
	int (*ret)() = (int(*)())code;
	ret;
} 
