#include <stdio.h>

void sort(int *input, int n) {
    asm(
        "movl $1, %%r8d\n\t"         
        "outer_cycle_begin:\n\t"
        "cmpl $0, %%r8d\n\t"         
        "je outer_cycle_end\n\t"
        "movl $0, %%r8d\n\t"         
        "movq $0, %%rsi\n\t"         
        "outer_loop:\n\t"
        "    incq %%rsi\n\t"         
        "    cmpq %%rax, %%rsi\n\t" 
        "    jge outer_loop_end\n\t"
        "    movl (%%rbx, %%rsi, 4), %%ecx\n\t"  
        "    movl -4(%%rbx, %%rsi, 4), %%edx\n\t"  
        "    cmpl %%edx, %%ecx\n\t"  
        "    jge dont_swap\n\t"
        "    xchgl %%ecx, %%edx\n\t" 
        "    movl %%ecx, (%%rbx, %%rsi, 4)\n\t"
        "    movl %%edx, -4(%%rbx, %%rsi, 4)\n\t"
        "    movl $1, %%r8d\n\t"     
        "    dont_swap:\n\t"
        "    jmp outer_loop\n\t"
        "outer_loop_end:\n\t"
        "    decq %%rax\n\t"         
        "    testl %%r8d, %%r8d\n\t" 
        "    jnz outer_cycle_begin\n\t"
        "outer_cycle_end:\n\t"
        :
        : "b"(input), "a"(n)
        : "memory", "cc", "rsi", "rcx", "rdx", "r8"
    );
}

int main() {
    int n;

    FILE *file = fopen("C:/Users/HONOR/Desktop/Test_AVM/NUMBERS.txt", "r");

    if (file == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    fscanf(file, "%d", &n);

    int input[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &input[i]);
    }
    fclose(file);

    sort(input, n);

    FILE *output_file = fopen("C:/Users/HONOR/Desktop/Test_AVM/OUT.txt", "w");
    if (output_file == NULL) {
        perror("Failed to open output file");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(output_file, "%d ", input[i]);
    }

    fclose(output_file);

    return 0;
}
