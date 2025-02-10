#include<quantum_shell.h>

int main()
{
    char input[INPUT_LEN] = {0};

    do {
        fgets(input, INPUT_LEN, stdin);

    }while(strcmp(input, EXIT_CMD));
}
