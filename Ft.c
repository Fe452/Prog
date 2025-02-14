#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int TAM = 10;

typedef struct Cliente{
    int id;
    char nome[20], telefone[13], endereco[30];
}Cliente;

typedef struct Camiseta{
    int id;
    char modelo[10];
    float preco;
}Camiseta;

typedef struct Compra{
    int id;
    Cliente comprador;
    Camiseta *produtos;
    float total;
}Compra;

int tabela() {
    int escolha;
    printf("\nNo que deseja mexer?\n1 - Clientes\n2 - Camisetas\n3 - Compras\n4 - Sair\n");
    scanf("%i", &escolha);
    return escolha;
}

int menu() {
    int escolha;
    printf("\nBem vindo, o que deseja fazer?\n1 - Adicionar\n2 - Remover\n3 - Atualizar\n4 - Listar\n5 - Buscar\n6 - Voltar\n");
    scanf("%i", &escolha);
    return escolha;
}

void identidade(int escolha, char *tipo){
    switch(escolha){
        case 1 : strcpy(tipo, "Clientes");
            break;
        case 2 : strcpy(tipo, "Camisetas");
            break;
        case 3 : strcpy(tipo, "Compras");
            break;
    }
}

void adicionar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int n_cl, int n_cm, int n_cp) {
    switch(escolha){
        case 1 : 
            printf("Nome: ");
            fgets();
            n_cl++;
            break;
        case 2 : 
            n_cm++;
            break;
        case 3 : 
            n_cp++;
            break;
        
    }
        
        
    
    
}



int main() {
    int escolha_1, escolha_2, n_cl=0, n_cm=0, n_cp=0;
    char *tipo;
    tipo=malloc(10*sizeof(char));
    Cliente *cliente;
    cliente=malloc(TAM*sizeof(Cliente));
    Camiseta *camiseta;
    camiseta=malloc(TAM*sizeof(Camiseta));
    Compra *compra;
    compra=malloc(TAM*sizeof(Compra));

    do{
        escolha_1 = tabela();
        if(escolha_1 == 4) break;
        identidade(escolha_1, tipo);
        do{
            printf("\n<===%s===>", tipo); 
            escolha_2 = menu();
            if(escolha_2 == 6) break;
            switch(escolha_2){
                case 1: adicionar(cliente, camiseta, compra, escolha_1, n_cl, n_cm, n_cp);
                    break;
                /*case 2: remover(cliente, camiseta, compra);
                    break;
                case 3: atualizar(cliente, camiseta, compra);
                    break;
                case 4: listar(cliente, camiseta, compra);
                    break;
                case 5 : buscar(cliente, camiseta, compra);
                    break;
                case 6: printf("Voltando\n");
                    break;*/
                default: printf("Por favor, ecolha um numero dentre as opcoes\n");
            }
        }while(escolha_2 != 6);
    }while(escolha_1 != 4);
        
    
    
    return 0;
}