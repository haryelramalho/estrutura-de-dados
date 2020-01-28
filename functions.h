void doing(int* array, int size){

    system("clear");
    showArray(array, size);
    printf("\nAperte a tecla [ENTER] para continuar . . .\n");
    setbuf(stdin, NULL);
    getchar();
}

void showDetalhes(long int* detalhes, int* array, int size, float* tempo){

    system("clear");
    
    showArray(array, size);
    printf("Trocas: %lu\n", detalhes[1]);
    printf("Comparacoes: %lu\n", detalhes[0]);
    printf("Tempo: %f", (tempo[1] - tempo[0])/CLOCKS_PER_SEC);
    printf("\nAperte a tecla [ENTER] para continuar . . .\n");
    
    setbuf(stdin, NULL);
    getchar();

}

int solicitaBusca(){

    int valor;

    system("clear");

    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &valor);

    return valor;
}

void showBusca(int posicao, int valor){

    system("clear");

    printf("-------- RESULTADO BUSCA --------\n");

    if(posicao)
        printf("\nO valor %d foi encontrado na posicao %d do vetor ordenado!\n", valor, posicao);
    else
        printf("\nO valor %d nao foi encontrado no vetor!\n", valor);

    printf("\nAte logo!\n");
}
