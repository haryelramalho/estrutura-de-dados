/*
    Metodo: BubbleSort
*/

void bubbleSort(int *array, int size, long int *detalhes){

	int aux = 0;

	for(int i = 0; i < size-1; i++){ //laco maior que percorre todo o vetor, posicao a posicao
		for(int j = 0; j < size-1; j++){ //laco que seleciona a posicao do indice e as compara com as posicoes a sua direita ate que o maior seja colocado como o ultimo indice do vetor
			detalhes[0]++;
			if(array[j] > array[j+1]){ //se a posicao atual for maior que a proxima, a proxima será copiada para a atual e a proxima recebera a atual.
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
				detalhes[1]++;
			}
		}
	}
}

/*
    Metodo: SelectionSort
*/

void selectionSort(int *array, int size, long int *detalhes){

    int menor, troca;

    for(int i = 0; i < size-1; i++){ // laço que faz a comparação para todas as posições
        menor = i; //considerando o menor valor na posição em que o laço esta
        for(int j = i+1; j < size; j++){ //procura o menor elemento em relação a i por todo o vetor
            detalhes[0]++;
            if(array[j] < array[menor]){
                menor = j; //se encontrar um menor, atualiza o indice, o novo menor será o elemento encontrado, no caso j.
            }
        }
        if(i != menor){ //testa se o valor do menor foi alterado, se o i foi substituido pelo j 
            troca = array[i];
            array[i] = array[menor];
            array[menor] = troca; //troca os valores da posicao atual para a posicao menor
            detalhes[1]++;
        }
    }
}

/*
    Metodo: GnomeSort
*/

void gnomeSort(int *array, int size, long int *detalhes){
   
   int i, aux;

   for(int i = 1; i < size;){ //percorre o vetor comparando se o que esta guardado no indice anterior é menor que o próximo índice 
       if(array[i-1] <= array[i]){
           ++i;
           detalhes[0]++;
       }
       else{ //caso o valor anterior seja maior que o próximo, será trocado.
           detalhes[1]++;
           aux = array[i];
           array[i] = array[i-1];
           array[i-1] = aux;
           --i;
           if(i == 0)
               i = 1;
       }
   }
}

/*
    Metodo: InsertionSort
*/

void insertionSort(int *array, int size, long int *detalhes){

    int i, j, aux;

    for(i = 1; i < size; i++){ //percorre todo o vetor
        aux = array[i]; //atribui com o valor referente ao indice atual
        j = i - 1; //joga vai receber o indice anterior 
        detalhes[0]++; 

        while(j >= 0 && array[j] > aux){ //enquanto o indice j for maior ou igual a 0 e o valor dessa posicao for maior que auxiliar
            array[j+1] = array[j]; //esse laco copia todas as posições que são maiores que a posicao atual e insere na posição certa
            j = j - 1;
            detalhes[0]++;
            detalhes[1]++;
        }
        array[j + 1] = aux; //insereve o valor atual na posicao correta
    }
}

/*
    Metodo: ShellSort
    Este metodo consiste em pegar uma variavel h=n/2, onde n eh o tamanho do vetor e iremos fazer as comparacoes de por exemplo, da posicao e da posicao que esta 4 em seguida dela. Ou seja, comparamos array[0] com array[4], array[1] com array[5] etc
    Apos cada interacao dividimos h novamente por 2, ate o h ser igual a um. Nesse momento ele passa por todas as posicoes.
*/

void shellSort(int *array, int size, long int *detalhes){

    int i = (size - 1)/2;
    int chave, k, aux;

    while(i != 0){
        do{
            chave = 1;
            for(k = 0; k < size - i; ++k){
                detalhes[0]++;
                if(array[k] > array[k + i]){
                    aux = array[k];
                    array[k] = array[k + 1];
                    array[k + i] = aux;
                    chave = 0;
                    detalhes[1]++;
                }
            }
        }while(chave == 0);
        i = i/2;
    }
}

/*
    Metodo: QuickSort
*/

void quickSort(int *array, int inicio, int fim, unsigned long int *detalhes){

    int i, j, pivo, aux;

    i = inicio;
    j = fim-1;
    pivo = array[(inicio + fim) / 2]; //define o pivo como o elemento do meio
  
    while(i <= j){ // laco continua até quando a direita for menor que a esquerda, esse é o sinal indicativo que todo o vetor foi percorrido e as trocas foram feitas
        while(array[i] < pivo && i < fim){ //anda com a esquerda até achar um elemento que seja maior que o pivo
            detalhes[0]++;
            i++;
        }
        while(array[j] > pivo && j > inicio){ //anda com a direita até achar um valor que seja menor que o pivo
            detalhes[0]++;
            j--;
        }
        if(i <= j){ //compara as posições ao final dos laços
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            detalhes[1]++;
            i++;
            j--;
        }
    }
    if(j > inicio) //chama a funcao para a parte da esquerda repetindo todo o processo descrito acima
        quickSort(array, inicio, j+1, detalhes);
    if(i < fim){ //chama a funcao para a parte da direita repetindo todo o processo descrito acima
        quickSort(array, i, fim, detalhes);
    }
}

void merge(int *array, int inicio, int meio, int fim, long int *detalhes){

    int *vetAux, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio; //vetor a ser combinado
    p2 = meio + 1; //vetor a ser combinado
    vetAux = (int *) malloc(tamanho * sizeof(int)); //aloca vetor que irá receber os dados das comparações entre p1 e p2 

    if(vetAux != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(array[p1] < array[p2]){  //verifica quem é menor entre p1 e p2 para inserir no vetor auxiliar nesse bloco (IF/ELSE)
                    detalhes[0]++;
                    vetAux[i] = array[p1++];
                    detalhes[1]++;
                }
                else{
                    detalhes[0]++;
                    vetAux[i] = array[p2++];
                    detalhes[1]++;
                }

                if(p1 > meio) //Verifica se algum dos vetores acabou, caso tenham acabado, modificam a variavel fim para que o if chegue ai fim. *OTIMIZAÇÃO*
                    fim = 1;
                if(p2 > fim)
                    fim2 = 1;
            } else { //copia o que nao acabou para o vetor auxiliar
                if(!fim1){
                    vetAux[i] = array[p1++];
                    detalhes[1]++;
                }
                else{
                    vetAux[i] = array[p2++];
                    detalhes[1]++;
                }
            }
        } 
        for(j = 0, k = inicio; j < tamanho; j++, k++){ //copia os dados do auxiliar para o vetor original
            array[k] = vetAux[j];
        }
            
    }
    free(vetAux); //libera o auxiliar
}

void mergeSort(int *array, int inicio, int fim, long int *detalhes){
    int meio;
    if(inicio < fim){
        meio = floor((fim + inicio)/2);
        mergeSort(array, inicio, meio, detalhes); //chama funcao pra metade da esquerda
        mergeSort(array, meio+1, fim, detalhes); //chama funcao para metade da direita
        merge(array, inicio, meio, fim, detalhes); //combina as duas metades de forma ordenada
    }
}









