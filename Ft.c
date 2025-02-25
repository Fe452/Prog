#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int TAM = 10;     // eu acho melhor trocar por #define TAM

typedef struct Cliente{
    int id;
    char nome[100], telefone[16], endereco[50];
}Cliente;

typedef struct {
    int id;
    char modelo[100], tamanho[5];
    float preco;
}Camiseta;

typedef struct Compra{
    int id;
    Cliente comprador;
    Camiseta produtos[10];
    float total;
}Compra;
//pronto
int menu_1() {
    //na real é o primeiro menu_2_2, tem q rever os nomes, mas nesse tem a escolha pra q dados vc quer mexer
    int escolha;
    printf("\nNo que deseja mexer?\n1 - Clientes\n2 - Camisetas\n3 - Compras\n4 - Sair\n");
    scanf("%i", &escolha);
    return escolha;
}
//pronto
int menu_2() {
    // aí esse é o segundo menu, q tem as ações q vc pode fazer
    int escolha;
    printf("\nBem vindo, o que deseja fazer?\n1 - Adicionar\n2 - Listar\n3 - Buscar\n4 - Voltar\n");
    scanf("%i", &escolha);
    return escolha;
}
//FAZ LOGO
int menu_3() {
    // aí esse é o segundo menu, q tem as ações q vc pode fazer
    int escolha;
    printf("\nBem vindo, o que deseja fazer?\n1 - Adicionar\n2 - Listar\n3 - Buscar\n4 - Voltar\n");
    scanf("%i", &escolha);
    return escolha;
}
//pronto
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
//pronto
void ordenar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra) {
    switch(escolha){// isso aqui vai ordernar os nomes em ordem alfabetica (bubble sort)
        case 1:
            for (int i = 0; i < *n_cliente - 1; i++){
                for (int j = i + 1; j < *n_cliente; j++){
                    if (strcmp(cliente[i].nome, cliente[j].nome) > 0){
                        Cliente temp = cliente[i];
                        cliente[i] = cliente[j];
                        cliente[j] = temp;
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < *n_camiseta - 1; i++){
                for (int j = i + 1; j < *n_camiseta; j++){
                    if (strcmp(camiseta[i].modelo, camiseta[j].modelo) > 0){
                        Camiseta temp = camiseta[i];
                        camiseta[i] = camiseta[j];
                        camiseta[j] = temp;
                    }
                }
            }
            break;
    }
    
}

void adicionar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra) {
    switch(escolha){
        case 1 : 
            cliente[*n_cliente].id=*n_cliente;
            printf("Nome: ");
            fgets(cliente[*n_cliente].nome, sizeof(cliente[*n_cliente].nome), stdin);
            cliente[*n_cliente].nome[strcspn(cliente[*n_cliente].nome, "\n")] = '\0';
            fgets(cliente[*n_cliente].nome, sizeof(cliente[*n_cliente].nome), stdin);
            cliente[*n_cliente].nome[strcspn(cliente[*n_cliente].nome, "\n")] = '\0';
            printf("Telefone: ");
            fgets(cliente[*n_cliente].telefone, sizeof(cliente[*n_cliente].telefone), stdin);
            cliente[*n_cliente].telefone[strcspn(cliente[*n_cliente].telefone, "\n")] = '\0';
            printf("Endereco: ");
            fgets(cliente[*n_cliente].endereco, sizeof(cliente[*n_cliente].endereco), stdin);
            cliente[*n_cliente].endereco[strcspn(cliente[*n_cliente].endereco, "\n")] = '\0';
            /*testes de funcionameto prévio:
            printf("Nome cliente %i : %s", *n_cliente, cliente[*n_cliente].nome);
            printf("Telefone cliente %i : %s", *n_cliente, cliente[*n_cliente].telefone);
            printf("Endereco cliente %i : %s", *n_cliente, cliente[*n_cliente].endereco);*/
            (*n_cliente)++;
            ordenar(cliente, camiseta, compra, escolha, n_cliente, n_camiseta, n_compra);
            break;
        case 2 :
            camiseta[*n_camiseta].id=*n_camiseta;
            printf("Modelo: ");
            fgets(camiseta[*n_camiseta].modelo, sizeof(camiseta[*n_camiseta].modelo), stdin);
            fgets(camiseta[*n_camiseta].modelo, sizeof(camiseta[*n_camiseta].modelo), stdin);
            printf("Tamanho: ");
            fgets(camiseta[*n_camiseta].tamanho, sizeof(camiseta[*n_camiseta].tamanho), stdin);
            camiseta[*n_camiseta].tamanho[strcspn(camiseta[*n_camiseta].tamanho, "\n")] = '\0';
            printf("Preco: ");
            scanf("%f", &camiseta[*n_camiseta].preco); 
            (*n_camiseta)++;
            ordenar(cliente, camiseta, compra, escolha, n_cliente, n_camiseta, n_compra);
            break;
        case 3 : 
            compra[*n_compra].id=*n_compra;
            printf("ID ou nome do cliente: ");
            //compra[*n_compra].comprador = 
            (*n_compra)++;
            break;
        
    }   
}

void remover(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra, char *buscaCliente) {
    switch (escolha){
        case 1: 
            for (int i = 0; i < *n_cliente; i++)
            {
                if (strcmp(cliente[i].nome, buscaCliente) == 0) {
                    printf("\nCliente ''%s'' removido\n", cliente[i].nome);
                    for(int k=0; k<*n_cliente; k++){
                        if(cliente[k].id > cliente[i].id){
                            cliente[k].id--;
                        }
                    }
                    for (int j = i; j < *n_cliente - 1; j++) {
                        cliente[j] = cliente[j + 1];  // vai deslocar os elementos pra tirar o espaço vazio
                    }
                    (*n_cliente)--;
                    return;
                }
            }
            break;
        case 2:
            for (int i = 0; i < *n_camiseta; i++)
            {
                if (strcmp(camiseta[i].modelo, buscaCliente) == 0) {
                    printf("\nCamiseta ''%s'' removido\n", camiseta[i].modelo);
                    for(int k=0; k<*n_camiseta; k++){
                        if(camiseta[k].id > camiseta[i].id){
                            cliente[k].id--;
                        }
                    }
                    for (int j = i; j < *n_camiseta - 1; j++) {
                        camiseta[j] = camiseta[j + 1];  // vai deslocar os elementos pra tirar o espaço vazio
                    }
                    (*n_camiseta)--;
                    return;
                }
            }
            break;
        case 3:
            break;

    }
    
}

void atualizar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra, char *buscaCliente) {
    switch(escolha){
        case 1:
            for (int i = 0; i < *n_cliente; i++)
            {
                if (strcmp(cliente[i].nome, buscaCliente) == 0)
                {
                    printf("\nAtualizando o cliente ''%s''\n", buscaCliente);
                    printf("Atualizando o nome: ");
                    fgets(cliente[i].nome, sizeof(cliente[i].nome), stdin);
                    cliente[i].nome[strcspn(cliente[i].nome, "\n")] = '\0';

                    printf("\nAtualizando o telefone: ");
                    fgets(cliente[i].telefone, sizeof(cliente[i].telefone), stdin);
                    cliente[i].telefone[strcspn(cliente[i].telefone, "\n")] = '\0';

                    printf("\nAtualizando o endereco: ");
                    fgets(cliente[i].endereco, sizeof(cliente[i].endereco), stdin);
                    cliente[i].endereco[strspn(cliente[i].endereco, "\n")] = '\0';

                    printf("\nCliente atualizado!");
                    return;
                }
            }
            printf("Cliente não encontrado para atualização.\n");
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

void listar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra) {
    switch (escolha){
        case 1:
            // se não tiver cliente
            if (*n_cliente == 0){
                printf("\nNenhum cliente cadastrado.\n");
                return;
            }
            
            // mostra a lista
            printf("\n<===Lista de Clientes===>\n");
            for (int i = 0; i < *n_cliente; i++) {
                cliente[i].nome[strcspn(cliente[i].nome, "\n")] = '\0';
                
                printf("ID: %d | Nome: %s | Telefone: %s | Endereco: %s\n", cliente[i].id, cliente[i].nome, cliente[i].telefone, cliente[i].endereco);
            }
            break;
        case 2:
            // se não tiver cliente
            if (*n_camiseta == 0){
                printf("\nNenhuma camiseta cadastrada.\n");
                return;
            }
            
            // mostra a lista
            printf("\n<===Lista de Camisetas===>\n");
            for (int i = 0; i < *n_camiseta; i++) {
                camiseta[i].modelo[strcspn(camiseta[i].modelo, "\n")] = '\0';
                
                printf("ID: %d | Modelo: %s | Tamanho: %s | Preco: %.2f\n", camiseta[i].id, camiseta[i].modelo, camiseta[i].tamanho, camiseta[i].preco);
            }
            break;
        
        default:
            printf("\nOpcao invalida.\n");
            break;
    }
}

void buscar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha,int *n_cliente, int *n_camiseta, int *n_compra, char *buscaCliente) {
    int buscado = 0;
    int escolha_3;

    // se não tiver cliente
    if (*n_cliente == 0){
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }      
        // aqui da pra buscar o nome
        printf("Digite o nome que voce deseja buscar:\n"); // interação
        while (getchar() != '\n'); //Isso vai limpar o buffer
        fgets(buscaCliente, 30, stdin); // digitar
        buscaCliente[strcspn(buscaCliente, "\n")] = '\0'; // tira o \n do final

        // aqui mostra o nome buscado
        for (int i = 0; i < *n_cliente; i++){
            if (strcmp(cliente[i].nome, buscaCliente) == 0)// compara com os nomes ja digitados
            {
                printf("ID: %d | Nome: %s | Telefone: %s | Endereco: %s\n", cliente[i].id, cliente[i].nome, cliente[i].telefone, cliente[i].endereco);
                buscado = 1;
            }
        }
        // mano aqui eu to querendo fazer com que ja chame a função direto, alguma ideia?
        if (buscado){
            printf("\nOque deseja fazer?\n1 - Remover\n2 - Atualizar\n3 - Voltar\n");
            scanf("%d", &escolha_3); // escolha doq fazer
            while (getchar() != '\n'); // limpa o buffer, se tiver

            if (escolha_3 == 1)
            {
                remover(cliente, camiseta, compra, escolha, n_cliente, n_camiseta, n_compra, buscaCliente); // chama função remover
            }else if (escolha_3 == 2)
            {
                atualizar(cliente, camiseta, compra, escolha, n_cliente, n_camiseta, n_compra, buscaCliente); // chama função atualizar
            }else if (escolha_3 == 3)
            {
                return;
            }else{
                printf("Digite um valor válido!");
            }
            
            
            
        }else{
            printf("Cliente nao encontrado\n");
        }
}

/*int Mexer(int escolha, char *mexer) {
    // Isso aqui eu acho que vai dar pra mexer nos nomes kkk
    switch(escolha){
        case 1 : strcpy(mexer, "Remover"); return 1;
        case 2 : strcpy(mexer, "Atualizar"); return 2;
        case 3 : strcpy(mexer, "Sair"); return 3;
    }
    return 0;
}*/

int main() {
    //ent, tem q ver esse tanto de varíavel, pq eu acho q deve ficar melhor se diminuir, mas n sei
    int escolha_1, escolha_2, escolha_3, n_cliente=0, n_camiseta=0, n_compra=0;
    int *n1, *n2, *n3;
    char busca[30];
    n1=&n_cliente;
    n2=&n_camiseta;
    n3=&n_compra;

    char *tipo;
    tipo=malloc(10*sizeof(char));
    Cliente *cliente;
    cliente=malloc(TAM*sizeof(Cliente));
    if(cliente==NULL) return 1;
    Camiseta *camiseta;
    camiseta=malloc(TAM*sizeof(Camiseta));
    if(camiseta==NULL) return 1;
    Compra *compra;
    compra=malloc(TAM*sizeof(Compra));
    if(compra==NULL) return 1;

    do{
        escolha_1 = menu_1();
        if(escolha_1 == 4) break;
        identidade(escolha_1, tipo);
        do{
            printf("\n<===%s===>", tipo); 
            escolha_2 = menu_2();
            if(escolha_2 == 4) break;
            switch(escolha_2){
                case 1: adicionar(cliente, camiseta, compra, escolha_1, n1, n2, n3);
                    break;
                case 2: listar(cliente, camiseta, compra, escolha_1, n1, n2, n3);
                    break;
                case 3 : buscar(cliente, camiseta, compra, escolha_1, n1, n2, n3, busca);
                    break;
                default: printf("Por favor, ecolha um numero dentre as opcoes\n");
            }
        }while(escolha_2 != 4);
    }while(escolha_1 != 4);
    
    
    return 0;
}