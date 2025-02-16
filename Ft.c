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
    char modelo[10], tamanho[2];
    float preco;
}Camiseta;

typedef struct Compra{
    int id;
    Cliente comprador;
    Camiseta *produtos;
    float total;
}Compra;

int tabela() {
    //na real é o primeiro menu, tem q rever os nomes, mas nesse tem a escolha pra q dados vc quer mexer
    int escolha;
    printf("\nNo que deseja mexer?\n1 - Clientes\n2 - Camisetas\n3 - Compras\n4 - Sair\n");
    scanf("%i", &escolha);
    return escolha;
}

int menu() {
    // aí esse é o segundo menu, q tem as ações q vc pode fazer
    int escolha;
    printf("\nBem vindo, o que deseja fazer?\n1 - Adicionar\n2 - Remover\n3 - Atualizar\n4 - Listar\n5 - Buscar\n6 - Voltar\n");
    scanf("%i", &escolha);
    return escolha;
}

void identidade(int escolha, char *tipo){
    // Esse daqui é só pra ter título mostrando em q tipo de dado vc tá mexendo
    switch(escolha){
        case 1 : strcpy(tipo, "Clientes");
            break;
        case 2 : strcpy(tipo, "Camisetas");
            break;
        case 3 : strcpy(tipo, "Compras");
            break;
    }
}

void ordenar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cl, int *n_cm, int *n_cp) {
    
}
void adicionar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cl, int *n_cm, int *n_cp) {
    switch(escolha){
        case 1 : 
            cliente[*n_cl].id=*n_cl;
            printf("Nome: ");
            fgets(cliente[*n_cl].nome, sizeof(cliente[*n_cl].nome), stdin);
            fgets(cliente[*n_cl].nome, sizeof(cliente[*n_cl].nome), stdin);
            printf("Telefone: ");
            fgets(cliente[*n_cl].telefone, sizeof(cliente[*n_cl].telefone), stdin);
            printf("Endereco: ");
            fgets(cliente[*n_cl].endereco, sizeof(cliente[*n_cl].endereco), stdin);
            /*testes de funcionameto prévio:
            printf("Nome cliente %i : %s", *n_cl, cliente[*n_cl].nome);
            printf("Telefone cliente %i : %s", *n_cl, cliente[*n_cl].telefone);
            printf("Endereco cliente %i : %s", *n_cl, cliente[*n_cl].endereco);*/
            (*n_cl)++;
            break;
        case 2 :
            printf("Nome: ");
            fgets(cliente[*n_cl].nome, sizeof(cliente[*n_cl].nome), stdin);
            fgets(cliente[*n_cl].nome, sizeof(cliente[*n_cl].nome), stdin);
            printf("Telefone: ");
            fgets(cliente[*n_cl].telefone, sizeof(cliente[*n_cl].telefone), stdin);
            printf("Endereco: ");
            fgets(cliente[*n_cl].endereco, sizeof(cliente[*n_cl].endereco), stdin); 
            n_cm++;
            break;
        case 3 : 
            n_cp++;
            break;
        
    }
        
        
    
    
}

void remover(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cl, int *n_cm, int *n_cp) {

}

void atualizar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cl, int *n_cm, int *n_cp) {

}

void listar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cl, int *n_cm, int *n_cp) {
    switch (escolha)
    {
        case 4:
            if (*n_cl == 0) {
                printf("\nNenhum cliente cadastrado.\n");
                return;
            }

            for (int i = 0; i < *n_cl - 1; i++) {
                for (int j = i + 1; j < *n_cl; j++) {
                    if (strcmp(cliente[i].nome, cliente[j].nome) > 0) {
                        Cliente temp = cliente[i];
                        cliente[i] = cliente[j];
                        cliente[j] = temp;
                    }
                }
            }

            printf("\n<===Lista de Clientes===>\n");
            for (int i = 0; i < *n_cl; i++) {
                cliente[i].nome[strcspn(cliente[i].nome, "\n")] = '\0';
                
                printf("ID: %d | Nome: %s | Telefone: %s | Endereco: %s\n", 
                    cliente[i].id, cliente[i].nome, cliente[i].telefone, cliente[i].endereco);
            }
            break;
        
        default:
            printf("\nOpcao invalida.\n");
            break;
    }
}

void buscar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cl, int *n_cm, int *n_cp) {

}

int main() {
    //ent, tem q ver esse tanto de vari´´avel, pq eu acho q deve ficar melhor se diminuir, mas n sei
    int escolha_1, escolha_2, n_cl=0, n_cm=0, n_cp=0;
    int *n1, *n2, *n3;
    n1=&n_cl;
    n2=&n_cm;
    n3=&n_cp;

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
                case 1: adicionar(cliente, camiseta, compra, escolha_1, n1, n2, n3);
                    break;
                /*case 2: remover(cliente, camiseta, compra);
                    break;
                case 3: atualizar(cliente, camiseta, compra);
                    break;*/
                case 4: listar(cliente, camiseta, compra, escolha_2, n1, n2, n3);
                    break;
                /*case 5 : buscar(cliente, camiseta, compra);
                    break;
                case 6: printf("Voltando\n");
                    break;*/
                default: printf("Por favor, ecolha um numero dentre as opcoes\n");
            }
        }while(escolha_2 != 6);
    }while(escolha_1 != 4);
    return 0;
}