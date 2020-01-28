int menu_vetores(){

    int opcao;

    printf("-------- GERAR VETOR --------\n\n");
    printf("1 - Vetor Ordenado Crescente\n");
    printf("2 - Vetor Ordenado Decrescente\n");
    printf("3 - Vetor de numeros aleatorios\n");
    printf("4 - Vetor de numeros aleatorios sem repeticao\n");
    printf("0 - SAIR\n\n:");
    
    scanf("%d", &opcao);

    return opcao;
}

int menu_tamanho(){

    int opcao;

    printf("-------- TAMANHO DO VETOR --------\n\n");
    printf("1- 10\n");
    printf("2- 100\n");
    printf("3- 1.000\n");
    printf("4- 10.000\n");
    printf("5- 100.000\n");
    printf("0 - SAIR\n\n:");

    scanf("%d", &opcao);

    return opcao;
}

int menu_ordenacao(){
    
    int opcao;

    printf("-------- ORDENACAO --------\n");
    printf("1 - SelectionSort\n");
    printf("2 - QuickSort\n");
    printf("3 - MergeSort\n4 - GnomeSort\n");
    printf("5 - InsertionSort\n");
    printf("6 - ShellSort\n");
    printf("7 - BubbleSort\n");
    printf("0 - SAIR\n\n:");

    scanf("%d", &opcao);

    return opcao;
}

int menu_busca(){

    int opcao;

    printf("-------- BUSCA --------\n");
    printf("1 - Busca Binaria\n");
    printf("2 - Busca Sequencial\n");
    printf("0 - SAIR\n\n:");

    scanf("%d", &opcao);

    return opcao;
}