#include <stdio.h>
#include <stdlib.h>

//Estrutura e Funções para pilha dinâmica
//Estrutura da pilha
typedef struct No {
    int valor;
    struct No *anterior;
} No;

typedef struct {
    No *topo;
    int tamanho;
} Pilha;
//Funções para manipulação da pilha 
//Criar pilha
Pilha* criaPilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}
//Liberar pilha 
void liberaPilha(Pilha *p) {
    No *temp;
    while (p->topo != NULL) {
        temp = p->topo;
        p->topo = p->topo->anterior;
        free(temp);
    }
    free(p);
}
//Verificar se a pilha está vazia 
int estahVaziaPilha(Pilha *p) {
    return (p->topo == NULL);
}
//Empilhar elemento
void empilhar(Pilha *p, int valor) {
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->anterior = p->topo;
    p->topo = novoNo;
    p->tamanho++;
}
//Desempilhar elemento 
int desempilhar(Pilha *p, int *valor) {
    if (estahVaziaPilha(p)) return 0;
    No *temp = p->topo;
    *valor = temp->valor;
    p->topo = temp->anterior;
    free(temp);
    p->tamanho--;
    return 1;
}
//Estrutura e funções para fila dinâmica
//Estrutura da fila
typedef struct NoFila {
    int valor;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *final;
    int tamanho;
} Fila;
//Funções para manipulação da Fila
//Criar fila
Fila* criaFila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->inicio = f->final = NULL;
    f->tamanho = 0;
    return f;
}
//Liberar fila
void liberaFila(Fila *f) {
    NoFila *temp;
    while (f->inicio != NULL) {
        temp = f->inicio;
        f->inicio = f->inicio->proximo;
        free(temp);
    }
    free(f);
}
//Verificar se a fila está vazia
int estahVaziaFila(Fila *f) {
    return (f->inicio == NULL);
}
//Enfileirar elemento 
void enfileirar(Fila *f, int valor) {
    NoFila *novoNo = (NoFila*) malloc(sizeof(NoFila));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    if (f->final != NULL) f->final->proximo = novoNo;
    f->final = novoNo;
    if (f->inicio == NULL) f->inicio = novoNo;
    f->tamanho++;
}
//Desenfileirar elemento
int desenfileirar(Fila *f, int *valor) {
    if (estahVaziaFila(f)) return 0;
    NoFila *temp = f->inicio;
    *valor = temp->valor;
    f->inicio = temp->proximo;
    if (f->inicio == NULL) f->final = NULL;
    free(temp);
    f->tamanho--;
    return 1;
}


//Programa principal
int main() {
    //Variaveis controle 
    int controle = 0, qtd_pilha = 0, qtd_fila = 0; 
    int aux, num;
    //Cria a pilha
    Pilha *p = criaPilha();
    //Cria a fila
    Fila *f = criaFila();
    while(controle == 0){
        printf("\nMENU\n\n(1)PILHA\n(2)FILA\n(4)SAIR DO PROGRAMA\nSELECIONE UMA OPÇÃO: ");
        scanf("%d",&controle);
        if (controle  != 4 && controle  != 2 && controle  != 1) {
            printf("\nOPÇÃO INVÁLIDA... TENTE NOVAMENTE!\n");
            controle = 0;
        }
        while (controle == 1){
            printf("\nSELECIONOU PILHA\n(1)EMPILHAR\n(2)DESEMPILHAR\n(3)DESEMPILHAR TODOS\n(4)SAIR PARA O MENU\nSELECIONE A OPÇÃO: ");
            scanf("%d",&aux);
            if(aux == 1){
                printf("\nEMPILHAR O NUMERO: ");
                scanf("%d",&num);
                //Empilhar
                empilhar(p, num);
                printf("\nNUMERO %d EMPILHADO\n",num);
                qtd_pilha++;
            }else if(aux == 2){
                if(qtd_pilha > 0){
                    printf("\nDESEMPILHANDO...\n");
                    qtd_pilha--;
                    //Desempilhar
                    desempilhar(p, &num);
                    printf("\nDESEMPILHADO DA PILHA: %d\n",num);
                }else{
                    printf("\nERRO AO DESEMPILHAR...PILHA VAZIA\n");
                }
            }else if(aux == 3){
                if(qtd_pilha > 0){
                    printf("\nDESEMPILHANDO TODOS...\n");
                    qtd_pilha = 0;
                    //Desempilha até acabar a pilha
                    while (desempilhar(p, &num)) {
                    printf("\nDESEMPILHADO DA PILHA: %d\n", num);
                    }
                     
                }else{
                    printf("\nERRO AO DESEMPILHAR TODOS...PILHA VAZIA\n");
                }
            }else if(aux == 4){
                printf("\nVOLTANDO PARA O MENU...\n");
                controle = 0;
            }else{
                printf("\nOPÇÃO INVÁLIDA...TENTE NOVAMENTE\n");
            }
        } 
        while (controle == 2){
            printf("\nSELECIONOU FILA\n(1)ENFILEIRAR\n(2)DESINFILEIRAR\n(3)DESINFILEIRAR TODOS\n(4)SAIR PARA O MENU\nSELECIONE A OPÇÃO: ");
            scanf("%d",&aux);
            
            if(aux == 1){
                printf("\nEFILEIRAR O NUMERO: ");
                scanf("%d",&num);
                //Enfileirar
                enfileirar(f, num);
                printf("\nNUMERO %d EFILEIRADO\n",num);
                qtd_fila++;
                
            }else if(aux == 2){
                if(qtd_fila > 0){
                    printf("\nDESENFILEIRANDO...\n");
                    qtd_fila--;
                    //Desenfileirar
                    desenfileirar(f, &num);
                    printf("DESENFILEIRADO DA FILA: %d\n",num);
                }else{
                    printf("\nERRO AO DESENFILEIRAR...FILA VAZIA\n");
                }

            }else if(aux == 3){
                if (qtd_fila > 0){
                    printf("\nDESENFILEIRANDO TODOS...\n");
                    qtd_fila = 0;
                    //Desenfileira até acabar a fila
                    while (desenfileirar(f, &num)) {
                        printf("DESENFILEIRANDO: %d\n", num);
                    }   
                    
                }else{
                    printf("\nERRO AO DESENFILEIRAR TODOS...FILA VAZIA\n");
                }
                

                }else if(aux == 4){
                    printf("\nVOLTANDO PARA O MENU...\n");
                    controle = 0;
            }else{
                printf("\nOPÇÃO INVÁLIDA...TENTE NOVAMENTE\n");
            
                
            }
        } 
        while (controle ==4){
            //Libera memoria alocada da pilha
            liberaPilha(p); 
            //Libera memoria alocada da fila
            liberaFila(f);
            printf("\nOBRIGADO POR USAR O MEU PROGRAMA DE ESTUDOS EM C++ DE FILA E PILHA\n");
            return 0;
        } 
    }
}


