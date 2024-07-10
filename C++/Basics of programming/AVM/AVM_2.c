#include <stdio.h>
#include <stdlib.h>

void find_duplicates(int *input, int n) {
    int result[100][2] = {0}; // Максимум 100 чисел и их счетчики
    int result_count = 0;

    asm (
        "movl $0, %%ecx\n\t"         // ecx = 0 (счетчик результата)
        "movl $0, %%edi\n\t"         // edi = 0 (счетчик i)
        "outer_loop:\n\t"
        "cmp %%edi, %1\n\t"          // if i >= n, выход из цикла
        "jge outer_end\n\t"
        
        "movl %%edi, %%esi\n\t"      // esi = i
        "incl %%esi\n\t"             // esi = i + 1
        "movl $1, %%ebx\n\t"         // ebx = 1 (счетчик повторений)
        
        "inner_loop:\n\t"
        "cmp %%esi, %1\n\t"          // if j >= n, выход из внутреннего цикла
        "jge inner_end\n\t"
        
        "movl (%0,%%edi,4), %%eax\n\t" // eax = input[i]
        "cmpl %%eax, (%0,%%esi,4)\n\t" // сравнить input[i] и input[j]
        "jne no_match\n\t"
        
        "incl %%ebx\n\t"             // увеличить счетчик повторений
        "movl $-1, (%0,%%esi,4)\n\t" // отметить повторяющееся число как -1
        "no_match:\n\t"
        "incl %%esi\n\t"             // перейти к следующему j
        "jmp inner_loop\n\t"
        
        "inner_end:\n\t"
        "cmpl $1, %%ebx\n\t"         // если повторений больше одного
        "jle not_duplicate\n\t"
        
        "movl (%0,%%edi,4), %%eax\n\t" // eax = input[i]
        "movl %%eax, result(,%%ecx,8)\n\t" // сохранить значение в результат
        "movl %%ebx, result+4(,%%ecx,8)\n\t" // сохранить счетчик в результат
        "incl %%ecx\n\t"             // увеличить счетчик результата
        
        "not_duplicate:\n\t"
        "incl %%edi\n\t"             // перейти к следующему i
        "jmp outer_loop\n\t"
        
        "outer_end:\n\t"
        "movl %%ecx, %2\n\t"         // сохранить значение ecx в result_count
        : "=r" (result_count)
        : "r"(n), "m"(result_count), "r"(input)
        : "memory", "cc", "eax", "ebx", "ecx", "edi", "esi"
    );

    // Сохранить результаты в файл вывода
    FILE *output_file = fopen("C:/Users/HONOR/Desktop/Test_AVM/OUTPUTtxt", "w");
    if (output_file == NULL) {
        perror("Failed to open output file");
        return;
    }

    if (result_count == 0) {
        fprintf(output_file, "None\n");
    } else {
        for (int i = 0; i < result_count; i++) {
            fprintf(output_file, "%d - %d\n", result[i][0], result[i][1]);
        }
    }

    fclose(output_file);
}

int main() {
    FILE *file = fopen("C:/Users/HONOR/Desktop/Test_AVM/INPUT.txt", "r");

    if (file == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    int *input = (int *)malloc(n * sizeof(int));
    if (input == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &input[i]);
    }
    fclose(file);

    find_duplicates(input, n);

    free(input);
    return 0;
}
