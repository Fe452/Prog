#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct {
    int id;
    char nome[100], telefone[16], endereco[50];
} Cliente;

typedef struct {
    int id;
    char modelo[100], tamanho[5];
    float preco;
} Camiseta;

typedef struct {
    int id;
    Cliente comprador;
    Camiseta produtos[10];
    float total;
} Compra;

int menu_1() {
    int escolha;
    printf("\nNo que deseja mexer?\n1 - Clientes\n2 - Camisetas\n3 - Compras\n4 - Sair\n");
    scanf("%i", &escolha);
    return escolha;
}

int menu_2() {
    int escolha;
    printf("\nBem vindo, o que deseja fazer?\n1 - Adicionar\n2 - Listar\n3 - Buscar\n4 - Voltar\n");
    scanf("%i", &escolha);
    return escolha;
}

void identidade(int escolha, char *tipo) {
    switch (escolha) {
        case 1: strcpy(tipo, "Clientes"); break;
        case 2: strcpy(tipo, "Camisetas"); break;
        case 3: strcpy(tipo, "Compras"); break;
    }
}

void ordenar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra) {
    switch (escolha) {
        case 1:
            for (int i = 0; i < *n_cliente - 1; i++) {
                for (int j = i + 1; j < *n_cliente; j++) {
                    if (strcmp(cliente[i].nome, cliente[j].nome) > 0) {
                        Cliente temp = cliente[i];
                        cliente[i] = cliente[j];
                        cliente[j] = temp;
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < *n_camiseta - 1; i++) {
                for (int j = i + 1; j < *n_camiseta; j++) {
                    if (camiseta[i].preco > camiseta[j].preco) {
                        Camiseta temp = camiseta[i];
                        camiseta[i] = camiseta[j];
                        camiseta[j] = temp;
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < *n_compra - 1; i++) {
                for (int j = i + 1; j < *n_compra; j++) {
                    if (strcmp(compra[i].comprador.nome, compra[j].comprador.nome) > 0) {
                        Compra temp = compra[i];
                        compra[i] = compra[j];
                        compra[j] = temp;
                    }
                }
            }
            break;
    }
}

void adicionar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra, char *buscaCliente, int *quemCompra) {
    switch (escolha) {
        case 1:
            cliente[*n_cliente].id = *n_cliente;
            printf("Nome: ");
            getchar(); 
            fgets(cliente[*n_cliente].nome, sizeof(cliente[*n_cliente].nome), stdin);
            cliente[*n_cliente].nome[strcspn(cliente[*n_cliente].nome, "\n")] = '\0';
            printf("Telefone: ");
            fgets(cliente[*n_cliente].telefone, sizeof(cliente[*n_cliente].telefone), stdin);
            cliente[*n_cliente].telefone[strcspn(cliente[*n_cliente].telefone, "\n")] = '\0';
            printf("Endereco: ");
            fgets(cliente[*n_cliente].endereco, sizeof(cliente[*n_cliente].endereco), stdin);
            cliente[*n_cliente].endereco[strcspn(cliente[*n_cliente].endereco, "\n")] = '\0';
            (*n_cliente)++;
            ordenar(cliente, camiseta, compra, escolha, n_cliente, n_camiseta, n_compra);
            break;
        case 2:
            camiseta[*n_camiseta].id = *n_camiseta;
            printf("Modelo: ");
            getchar(); 
            fgets(camiseta[*n_camiseta].modelo, sizeof(camiseta[*n_camiseta].modelo), stdin);
            camiseta[*n_camiseta].modelo[strcspn(camiseta[*n_camiseta].modelo, "\n")] = '\0';
            printf("Tamanho: ");
            fgets(camiseta[*n_camiseta].tamanho, sizeof(camiseta[*n_camiseta].tamanho), stdin);
            camiseta[*n_camiseta].tamanho[strcspn(camiseta[*n_camiseta].tamanho, "\n")] = '\0';
            printf("Preco: ");
            scanf("%f", &camiseta[*n_camiseta].preco);
            (*n_camiseta)++;
            ordenar(cliente, camiseta, compra, escolha, n_cliente, n_camiseta, n_compra);
            break;
        case 3:
            if (*n_cliente == 0) {
                printf("Nenhum cliente cadastrado.\n");
                return;
            }
            if (*n_camiseta == 0) {
                printf("Nenhuma camiseta cadastrada.\n");
                return;
            }

            compra[*n_compra].id = *n_compra;
            printf("1- Id ou 2- Nome do cliente: ");
            int opcao;
            scanf("%d", &opcao);
            getchar(); 

            if (opcao == 1) {
                printf("Digite o Id do cliente: ");
                scanf("%d", quemCompra);
                getchar(); 

                int encontrado = 0;
                for (int i = 0; i < *n_cliente; i++) {
                    if (cliente[i].id == *quemCompra) {
                        compra[*n_compra].comprador = cliente[i];
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Cliente nao encontrado.\n");
                    return;
                }
            } else if (opcao == 2) {
                printf("Digite o Nome do cliente: ");
                fgets(buscaCliente, 100, stdin);
                buscaCliente[strcspn(buscaCliente, "\n")] = '\0';

                int encontrado = 0;
                for (int i = 0; i < *n_cliente; i++) {
                    if (strcmp(cliente[i].nome, buscaCliente) == 0) {
                        compra[*n_compra].comprador = cliente[i];
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Cliente nao encontrado.\n");
                    return;
                }
            } else {
                printf("Opcao invalida.\n");
                return;
            }

            printf("Quantas camisetas deseja comprar? ");
            int quantidade;
            scanf("%d", &quantidade);
            getchar(); 

            if (quantidade > 10) {
                printf("So e possivel comprar ate 10 camisetas por compra.\n");
                return;
            }
            float total = 0;
            for (int i = 0; i < quantidade; i++) {
                printf("Digite o ID da camiseta %d: ", i + 1);
                int idCamiseta;
                scanf("%d", &idCamiseta);
                getchar(); 

                int encontrado = 0;
                for (int j = 0; j < *n_camiseta; j++) {
                    if (camiseta[j].id == idCamiseta) {
                        compra[*n_compra].produtos[i] = camiseta[j];
                        total += camiseta[j].preco;
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Camiseta nao encontrada.\n");
                    return;
                }
            }
            compra[*n_compra].total = total;
            printf("Total da compra armazenado: %.2f\n", compra[*n_compra].total);
            (*n_compra)++;
            break;
    }
}

void remover(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra, char *buscaCliente) {
    switch (escolha) {
        case 1:
            for (int i = 0; i < *n_cliente; i++) {
                if (strcmp(cliente[i].nome, buscaCliente) == 0) {
                    printf("\nCliente '%s' removido\n", cliente[i].nome);
                    for(int k=0; k<*n_cliente; k++){
                        if(cliente[k].id > cliente[i].id){
                            cliente[k].id--;
                        }
                    }
                    for (int k = i; k < *n_cliente - 1; k++) {
                        cliente[k] = cliente[k + 1];  
                    }
                    (*n_cliente)--;
                    return;
                }
            }
            
            break;
        case 2:
            for (int i = 0; i < *n_camiseta; i++) {
                if (strcmp(camiseta[i].modelo, buscaCliente) == 0) {
                    printf("\nCamiseta '%s' removida\n", camiseta[i].modelo);
                    for(int k=0; k<*n_camiseta; k++){
                        if(camiseta[k].id > camiseta[i].id){
                            camiseta[k].id--;
                        }
                    }
                    for (int k = i; k < *n_camiseta - 1; k++) {
                        camiseta[k] = camiseta[k + 1];  
                    }
                    (*n_camiseta)--;
                    return;
                }
            }
            
            break;
    }
}

void atualizar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra, char *buscaCliente) {
    switch (escolha) {
        case 1:
            for (int i = 0; i < *n_cliente; i++) {
                if (strcmp(cliente[i].nome, buscaCliente) == 0) {
                    printf("\nAtualizando o cliente '%s'\n", buscaCliente);
                    printf("Atualizando o nome: ");
                    fgets(cliente[i].nome, sizeof(cliente[i].nome), stdin);
                    cliente[i].nome[strcspn(cliente[i].nome, "\n")] = '\0';

                    printf("Atualizando o telefone: ");
                    fgets(cliente[i].telefone, sizeof(cliente[i].telefone), stdin);
                    cliente[i].telefone[strcspn(cliente[i].telefone, "\n")] = '\0';

                    printf("Atualizando o endereco: ");
                    fgets(cliente[i].endereco, sizeof(cliente[i].endereco), stdin);
                    cliente[i].endereco[strcspn(cliente[i].endereco, "\n")] = '\0';

                    printf("Cliente atualizado!\n");
                    return;
                }
            }
            printf("Cliente não encontrado para atualização.\n");
            break;
        case 2:
            for (int i = 0; i < *n_camiseta; i++) {
                if (strcmp(camiseta[i].modelo, buscaCliente) == 0) {
                    printf("\nAtualizando a camiseta '%s'\n", buscaCliente);
                    printf("Atualizando o modelo: ");
                    fgets(camiseta[i].modelo, sizeof(camiseta[i].modelo), stdin);
                    camiseta[i].modelo[strcspn(camiseta[i].modelo, "\n")] = '\0';

                    printf("Atualizando o tamanho: ");
                    fgets(camiseta[i].tamanho, sizeof(camiseta[i].tamanho), stdin);
                    camiseta[i].tamanho[strcspn(camiseta[i].tamanho, "\n")] = '\0';

                    printf("Atualizando o preco: ");
                    scanf("%f", &camiseta[i].preco);
                    printf("Camiseta atualizada!\n");
                    return;
                }
            }
            printf("Camiseta não encontrada para atualização.\n");
            break;
    }
}

void listar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra) {
    switch (escolha) {
        case 1:
            if (*n_cliente == 0) {
                printf("\nNenhum cliente cadastrado.\n");
                return;
            }
            printf("\n<===Lista de Clientes===>\n");
            for (int i = 0; i < *n_cliente; i++) {
                printf("ID: %d | Nome: %s | Telefone: %s | Endereco: %s\n", cliente[i].id, cliente[i].nome, cliente[i].telefone, cliente[i].endereco);
            }
            break;
        case 2:
            if (*n_camiseta == 0) {
                printf("\nNenhuma camiseta cadastrada.\n");
                return;
            }
            printf("\n<===Lista de Camisetas===>\n");
            for (int i = 0; i < *n_camiseta; i++) {
                printf("ID: %d | Modelo: %s | Tamanho: %s | Preco: %.2f\n", camiseta[i].id, camiseta[i].modelo, camiseta[i].tamanho, camiseta[i].preco);
            }
            break;
        case 3:
            if (*n_compra == 0) {
                printf("\nNenhuma compra cadastrada.\n");
                return;
            }
            printf("\n<===Lista de Compras===>\n");
            for (int i = 0; i < *n_compra; i++) {
                printf("ID: %d | Comprador: %s | Total: %.2f | Produtos: ", compra[i].id, compra[i].comprador.nome, compra[i].total);
                for (int j = 0; j < sizeof(compra[i].produtos)/sizeof(Camiseta); j++) { 
                    if (strlen(compra[i].produtos[j].modelo) > 0) { 
                        printf("%d: %s ",j+1, compra[i].produtos[j].modelo);
                    }
                }
                printf("\n");
            break;
        default:
            printf("\nOpcao invalida.\n");
            break;
    }
}
}

void buscar(Cliente *cliente, Camiseta *camiseta, Compra *compra, int escolha, int *n_cliente, int *n_camiseta, int *n_compra, char *buscaCliente) {
    int buscado = 0;
    switch (escolha) {
        case 1:
            if (*n_cliente == 0) {
                printf("\nNenhum cliente cadastrado.\n");
                return;
            }
            printf("Digite o nome que voce deseja buscar:\n");
            getchar(); 
            fgets(buscaCliente, 30, stdin);
            buscaCliente[strcspn(buscaCliente, "\n")] = '\0';

            for (int i = 0; i < *n_cliente; i++) {
                if (strcmp(cliente[i].nome, buscaCliente) == 0) {
                    printf("ID: %d | Nome: %s | Telefone: %s | Endereco: %s\n", cliente[i].id, cliente[i].nome, cliente[i].telefone, cliente[i].endereco);
                    buscado = 1;
                }
            }
            if (buscado) {
                printf("\nO que deseja fazer?\n1 - Remover\n2 - Atualizar\n3 - Voltar\n");
                int escolha_3;
                scanf("%d", &escolha_3);
                getchar();

                if (escolha_3 == 1) {
                    remover(cliente, camiseta, compra, escolha, n_cliente, n_camiseta, n_compra, buscaCliente);
                } else if (escolha_3 == 2) {
                    atualizar(cliente, camiseta, compra, escolha, n_cliente, n_camiseta, n_compra, buscaCliente);
                }
            } else {
                printf("Cliente nao encontrado\n");
            }
            break;
        case 2:
            if (*n_camiseta == 0) {
                printf("\nNenhuma camiseta cadastrada.\n");
                return;
            }
            printf("Digite a camiseta que voce deseja buscar:\n");
            getchar();
            fgets(buscaCliente, 30, stdin);
            buscaCliente[strcspn(buscaCliente, "\n")] = '\0';

            for (int i = 0; i < *n_camiseta; i++) {
                if (strcmp(camiseta[i].modelo, buscaCliente) == 0) {
                    printf("ID: %d | Modelo: %s | Tamanho: %s | Preco: %.2f\n", camiseta[i].id, camiseta[i].modelo, camiseta[i].tamanho, camiseta[i].preco);
                    buscado = 1;
                }
            }
            if (buscado) {
                printf("\nO que deseja fazer?\n1 - Remover\n2 - Atualizar\n3 - Voltar\n");
                int escolha_3;
                scanf("%d", &escolha_3);
                getchar();

                if (escolha_3 == 1) {
                    remover(cliente, camiseta, compra, escolha, n_cliente, n_camiseta, n_compra, buscaCliente);
                } else if (escolha_3 == 2) {
                    atualizar(cliente, camiseta, compra, escolha, n_cliente, n_camiseta, n_compra, buscaCliente);
                }
            } else {
                printf("Camiseta nao encontrada\n");
            }
            break;
        case 3:
            if (*n_compra == 0) {
                printf("\nNenhuma compra registrada.\n");
                return;
            }
            printf("Digite o nome do comprador que voce deseja buscar:\n");
            getchar(); 
            fgets(buscaCliente, 30, stdin);
            buscaCliente[strcspn(buscaCliente, "\n")] = '\0';

            for (int i = 0; i < *n_compra; i++) {
                if (strcmp(compra[i].comprador.nome, buscaCliente) == 0) {
                    printf("ID: %d | Comprador: %s | Total: %.2f | Produtos: ", compra[i].id, compra[i].comprador.nome, compra[i].total);
                    for (int j = 0; j < sizeof(compra[i].produtos)/sizeof(Camiseta); j++) { 
                        if (strlen(compra[i].produtos[j].modelo) > 0) { 
                            printf("%d: %s ",j+1, compra[i].produtos[j].modelo);
                        }
                    }
                    buscado = 1;
                }
            }
            if (!buscado) {
                printf("Compra nao registrada\n");
            }
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
}

void resgatarbin(Cliente *cliente, int *n_cliente) {
    FILE *bin = fopen("clientes.bin", "rb");
    if (bin == NULL) return;

    fseek(bin, 0, SEEK_END);
    long size = ftell(bin);
    rewind(bin);

    *n_cliente = size / sizeof(Cliente);
    if (*n_cliente > TAM) *n_cliente = TAM;

    fread(cliente, sizeof(Cliente), *n_cliente, bin);
    fclose(bin);
}

void salvarbin(Cliente *cliente, int n_cliente) {
    FILE *bin = fopen("clientes.bin", "wb");
    if (bin == NULL) {
        perror("Erro ao salvar clientes");
        return;
    }
    fwrite(cliente, sizeof(Cliente), n_cliente, bin);
    fclose(bin);
}

void resgatarbin_2(Camiseta *camiseta, int *n_camiseta) {
    FILE *bin = fopen("camisetas.bin", "rb");
    if (bin == NULL) return;

    fseek(bin, 0, SEEK_END);
    long size = ftell(bin);
    rewind(bin);

    *n_camiseta = size / sizeof(Camiseta);
    if (*n_camiseta > TAM) *n_camiseta = TAM;

    fread(camiseta, sizeof(Camiseta), *n_camiseta, bin);
    fclose(bin);
}

void salvarbin_2(Camiseta *camiseta, int n_camiseta) {
    FILE *bin = fopen("camisetas.bin", "wb");
    if (bin == NULL) {
        perror("Erro ao salvar camisetas");
        return;
    }
    fwrite(camiseta, sizeof(Camiseta), n_camiseta, bin);
    fclose(bin);
}

void resgatarbin_3(Compra *compra, int *n_compra) {
    FILE *bin = fopen("compras.bin", "rb");
    if (bin == NULL) return;

    fseek(bin, 0, SEEK_END);
    long size = ftell(bin);
    rewind(bin);

    *n_compra = size / sizeof(Compra);
    if (*n_compra > TAM) *n_compra = TAM;

    fread(compra, sizeof(Compra), *n_compra, bin);
    fclose(bin);
}

void salvarbin_3(Compra *compra, int n_compra) {
    FILE *bin = fopen("compras.bin", "wb");
    if (bin == NULL) {
        perror("Erro ao salvar compras");
        return;
    }
    fwrite(compra, sizeof(Compra), n_compra, bin);
    fclose(bin);
}

void salvar_txt(Cliente *cliente, int n_cliente, Camiseta *camiseta, int n_camiseta, Compra *compra, int n_compra) {
    FILE *txt = fopen("dados_cadastrados.txt", "w");
    if (txt == NULL) {
        perror("Erro ao criar arquivo de texto");
        return;
    }

    fprintf(txt, "<=== Lista de Clientes ===>\n");
    for (int i = 0; i < n_cliente; i++) {
        fprintf(txt, "ID: %d | Nome: %s | Telefone: %s | Endereco: %s\n", cliente[i].id, cliente[i].nome, cliente[i].telefone, cliente[i].endereco);
    }

    fprintf(txt, "\n<=== Lista de Camisetas ===>\n");
    for (int i = 0; i < n_camiseta; i++) {
        fprintf(txt, "ID: %d | Modelo: %s | Tamanho: %s | Preco: %.2f\n", camiseta[i].id, camiseta[i].modelo, camiseta[i].tamanho, camiseta[i].preco);
    }

    fprintf(txt, "\n<=== Lista de Compras ===>\n");
    for (int i = 0; i < n_compra; i++) {
        fprintf(txt, "ID: %d | Comprador: %s | Total: %.2f | Produtos: ", compra[i].id, compra[i].comprador.nome, compra[i].total);
        for (int j = 0; j < sizeof(compra[i].produtos)/sizeof(Camiseta); j++) { 
            if (strlen(compra[i].produtos[j].modelo) > 0) { 
                fprintf(txt,"%d: %s ",j+1, compra[i].produtos[j].modelo);
            }
        }
    }

    fclose(txt);
}

int main() {
    int escolha_1, escolha_2, n_cliente = 0, n_camiseta = 0, n_compra = 0;
    int quemCompra;
    char busca_cliente[100];

    Cliente *cliente = malloc(TAM * sizeof(Cliente));
    if (cliente == NULL) return 1;
    Camiseta *camiseta = malloc(TAM * sizeof(Camiseta));
    if (camiseta == NULL) return 1;
    Compra *compra = malloc(TAM * sizeof(Compra));
    if (compra == NULL) return 1;

    char tipo[10];

    resgatarbin(cliente, &n_cliente);
    resgatarbin_2(camiseta, &n_camiseta);
    resgatarbin_3(compra, &n_compra);
    do {
        escolha_1 = menu_1();
        if (escolha_1 == 4) break;
        identidade(escolha_1, tipo);
        do {
            printf("\n<===%s===>", tipo);
            escolha_2 = menu_2();
            if (escolha_2 == 4) break;
            switch (escolha_2) {
                case 1: adicionar(cliente, camiseta, compra, escolha_1, &n_cliente, &n_camiseta, &n_compra, busca_cliente, &quemCompra); break;
                case 2: listar(cliente, camiseta, compra, escolha_1, &n_cliente, &n_camiseta, &n_compra); break;
                case 3: buscar(cliente, camiseta, compra, escolha_1, &n_cliente, &n_camiseta, &n_compra, busca_cliente); break;
                default: printf("Por favor, escolha um numero dentre as opcoes\n");
            }
        } while (escolha_2 != 4);
    } while (escolha_1 != 4);

    salvarbin(cliente, n_cliente);
    salvarbin_2(camiseta, n_camiseta);
    salvarbin_3(compra, n_compra);

    salvar_txt(cliente, n_cliente, camiseta, n_camiseta, compra, n_compra);

    free(cliente);
    free(camiseta);
    free(compra);
    
    return 0;
}