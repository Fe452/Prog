#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int TAM = 10;

typedef struct Cliente{
    int id;
    char nome[100], telefone[16], endereco[50];
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
            cliente[*n_cl].nome[strcspn(cliente[*n_cl].nome, "\n")] = '\0';
            fgets(cliente[*n_cl].nome, sizeof(cliente[*n_cl].nome), stdin);
            cliente[*n_cl].nome[strcspn(cliente[*n_cl].nome, "\n")] = '\0';
            printf("Telefone: ");
            fgets(cliente[*n_cl].telefone, sizeof(cliente[*n_cl].telefone), stdin);
            cliente[*n_cl].telefone[strcspn(cliente[*n_cl].telefone, "\n")] = '\0';
            printf("Endereco: ");
            fgets(cliente[*n_cl].endereco, sizeof(cliente[*n_cl].endereco), stdin);
            cliente[*n_cl].endereco[strcspn(cliente[*n_cl].endereco, "\n")] = '\0';
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

void remover(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cl, int *n_cm, int *n_cp, char *buscaCliente) {

    for (int i = 0; i < *n_cl; i++)
    {
        if (strcmp(cliente[i].nome, buscaCliente) == 0) {
            printf("\nCliente ''%s'' removido\n", cliente[i].nome);
            for (int j = i; j < *n_cl - 1; j++) {
                cliente[j] = cliente[j + 1];  // vai deslocar os elementos pra tirar o espaço vazio
            }
            (*n_cl)--;
            return;
        }
    } 
}

void atualizar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cl, int *n_cm, int *n_cp, char *buscaCliente) {
    for (int i = 0; i < *n_cl; i++)
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
}

void listar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cl, int *n_cm, int *n_cp) {
    switch (escolha){
        case 4:
            // se não tiver cliente
            if (*n_cl == 0){
                printf("\nNenhum cliente cadastrado.\n");
                return;
            }
            // isso aqui vai ordernar os nomes em ordem alfabetica (bubble sort)
            for (int i = 0; i < *n_cl - 1; i++){
                for (int j = i + 1; j < *n_cl; j++){
                    if (strcmp(cliente[i].nome, cliente[j].nome) > 0){
                        Cliente temp = cliente[i];
                        cliente[i] = cliente[j];
                        cliente[j] = temp;
                    }
                }
            }
            // mostra a lista
            printf("\n<===Lista de Clientes===>\n");
            for (int i = 0; i < *n_cl; i++) {
                cliente[i].nome[strcspn(cliente[i].nome, "\n")] = '\0';
                
                printf("ID: %d | Nome: %s | Telefone: %s | Endereco: %s\n", cliente[i].id, cliente[i].nome, cliente[i].telefone, cliente[i].endereco);
            }
            break;
        
        default:
            printf("\nOpcao invalida.\n");
            break;
    }
}

void buscar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha,int *n_cl, int *n_cm, int *n_cp, char *buscaCliente) {
    int buscado = 0;
    int escolha_3;

    // se não tiver cliente
    if (*n_cl == 0){
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }      
        // aqui da pra buscar o nome
        printf("Digite o nome que voce deseja buscar:\n"); // interação
        while (getchar() != '\n'); //Isso vai limpar o buffer
        fgets(buscaCliente, 30, stdin); // digitar
        buscaCliente[strcspn(buscaCliente, "\n")] = '\0'; // tira o \n do final

        // aqui mostra o nome buscado
        for (int i = 0; i < *n_cl; i++){
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
                remover(cliente, camiseta, compra, escolha, n_cl, n_cm, n_cp, buscaCliente); // chama função remover
            }else if (escolha_3 == 2)
            {
                atualizar(cliente, camiseta, compra, escolha, n_cl, n_cm, n_cp, buscaCliente); // chama função atualizar
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
    int escolha_1, escolha_2, escolha_3, n_cl=0, n_cm=0, n_cp=0;
    int *n1, *n2, *n3;
    char busca[30];
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
                case 5 : buscar(cliente, camiseta, compra, escolha_2, n1, n2, n3, busca);
                    break;
                /*case 6: printf("Voltando\n");
                    break;*/
                default: printf("Por favor, ecolha um numero dentre as opcoes\n");
            }
        }while(escolha_2 != 6);
    }while(escolha_1 != 4);
    
    
    return 0;
}