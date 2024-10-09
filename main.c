#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define MAX_ORDERS 50

typedef struct {
    int orderNumber;
    int dishNumber;
    int dishQuantity;
    int drinkNumber;
    int drinkQuantity;
} Order;

void displayMenu() {
    printf("\nMenu:\n");
    printf("Dishes\t\tDrinks\n");
    printf("1. Parmesan Filet\t1. Soda\n");
    printf("2. Executive Beef Filet\t2. Juice\n");
    printf("3. Executive Chicken Filet\t3. Water\n");
}

void placeOrder(Order orders[], int *totalOrders) {
    displayMenu();

    printf("\nPlace Order:\n");

    printf("Order Number: ");
    scanf("%d", &orders[*totalOrders].orderNumber);

    printf("Requested Dish Number: ");
    scanf("%d", &orders[*totalOrders].dishNumber);

    printf("Requested Dish Quantity: ");
    scanf("%d", &orders[*totalOrders].dishQuantity);

    printf("Drink Number: ");
    scanf("%d", &orders[*totalOrders].drinkNumber);

    printf("Drink Quantity: ");
    scanf("%d", &orders[*totalOrders].drinkQuantity);

    (*totalOrders)++;

    printf("\nOrder successfully placed!\n");
}

void viewOrders(Order orders[], int totalOrders) {
    printf("\nView Orders:\n");
    printf("--------------------------------------------------------------\n");
    printf("| Order Number | Dish | Quantity | Drink | Quantity |\n");
    printf("--------------------------------------------------------------\n");

    int totalDishes = 0, totalDrinks = 0;

    for (int i = 0; i < totalOrders; i++) {
        printf("| %-13d | %-4d | %-8d | %-5d | %-8d |\n", 
               orders[i].orderNumber,
               orders[i].dishNumber, orders[i].dishQuantity,
               orders[i].drinkNumber, orders[i].drinkQuantity);

        totalDishes += orders[i].dishQuantity;
        totalDrinks += orders[i].drinkQuantity;
    }

    printf("--------------------------------------------------------------\n");
    printf("Total Orders: %d\n", totalOrders);
    printf("Average Dishes per Order: %.2f\n", (float)totalDishes / totalOrders);
    printf("Average Drinks per Order: %.2f\n", (float)totalDrinks / totalOrders);
}

void searchOrder(Order orders[], int totalOrders, int orderNumberSearch) {
    printf("\nSearch Order:\n");

    int found = 0;

    for (int i = 0; i < totalOrders; i++) {
        if (orders[i].orderNumber == orderNumberSearch) {
            printf("Order found:\n");
            printf("Order Number: %d\n", orders[i].orderNumber);
            printf("Requested Dish Number: %d\n", orders[i].dishNumber);
            printf("Requested Dish Quantity: %d\n", orders[i].dishQuantity);
            printf("Drink Number: %d\n", orders[i].drinkNumber);
            printf("Drink Quantity: %d\n", orders[i].drinkQuantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Order not found!\n");
    }
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    Order orders[MAX_ORDERS];
    int totalOrders = 0;
    int option;

    do {
        printf("\nMain Menu:\n");
        printf("1. Place Order\n");
        printf("2. View Orders\n");
        printf("3. Search Order\n");
        printf("4. Exit Program\n");

        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                placeOrder(orders, &totalOrders);
                break;
            case 2:
                viewOrders(orders, totalOrders);
                break;
            case 3: {
                int orderNumberSearch;
                printf("Enter the order number to search: ");
                scanf("%d", &orderNumberSearch);
                searchOrder(orders, totalOrders, orderNumberSearch);
                break;
            }
            case 4:
                printf("\nExiting the program. Thank you!\n");
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while (option != 4);

    return 0;
}

// VERSÃO EM PT - BR
/* #include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define MAX_PEDIDOS 50

typedef struct {
    int numeroPedido;
    int numeroPrato;
    int quantidadePrato;
    int numeroBebida;
    int quantidadeBebida;
} Pedido;

void exibirCardapio() {
    printf("\nCardapio:\n");
    printf("Pratos\t\tBebidas\n");
    printf("1. Filé a parmegiana\t1. Refrigerante\n");
    printf("2. Executivo com filé de boi\t2. Suco\n");
    printf("3. Executivo com filé de frango\t3. Água\n");
}

void realizarPedido(Pedido pedidos[], int *totalPedidos) {
    exibirCardapio();

    printf("\nRealizar Pedido:\n");

    printf("Numero do Pedido: ");
    scanf("%d", &pedidos[*totalPedidos].numeroPedido);

    printf("Numero do Prato Solicitado: ");
    scanf("%d", &pedidos[*totalPedidos].numeroPrato);

    printf("Quantidade do Prato Solicitado: ");
    scanf("%d", &pedidos[*totalPedidos].quantidadePrato);

    printf("Numero da Bebida: ");
    scanf("%d", &pedidos[*totalPedidos].numeroBebida);

    printf("Quantidade da Bebida: ");
    scanf("%d", &pedidos[*totalPedidos].quantidadeBebida);

    (*totalPedidos)++;

    printf("\nPedido realizado com sucesso!\n");
}

void visualizarPedidos(Pedido pedidos[], int totalPedidos) {
    printf("\nVisualizar Pedidos:\n");
    printf("--------------------------------------------------------------\n");
    printf("| Numero do Pedido | Prato | Quantidade | Bebida | Quantidade |\n");
    printf("--------------------------------------------------------------\n");

    int totalPratos = 0, totalBebidas = 0;

    for (int i = 0; i < totalPedidos; i++) {
        printf("| %-17d | %-5d | %-10d | %-5d | %-10d |\n", pedidos[i].numeroPedido,
               pedidos[i].numeroPrato, pedidos[i].quantidadePrato,
               pedidos[i].numeroBebida, pedidos[i].quantidadeBebida);

        totalPratos += pedidos[i].quantidadePrato;
        totalBebidas += pedidos[i].quantidadeBebida;
    }

    printf("--------------------------------------------------------------\n");
    printf("Total de Pedidos: %d\n", totalPedidos);
    printf("Média de Pratos por Pedido: %.2f\n", (float)totalPratos / totalPedidos);
    printf("Média de Bebidas por Pedido: %.2f\n", (float)totalBebidas / totalPedidos);
}

void buscarPedido(Pedido pedidos[], int totalPedidos, int numeroPedidoBusca) {
    printf("\nBuscar Pedido:\n");

    int encontrado = 0;

    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].numeroPedido == numeroPedidoBusca) {
            printf("Pedido encontrado:\n");
            printf("Numero do Pedido: %d\n", pedidos[i].numeroPedido);
            printf("Numero do Prato Solicitado: %d\n", pedidos[i].numeroPrato);
            printf("Quantidade do Prato Solicitado: %d\n", pedidos[i].quantidadePrato);
            printf("Numero da Bebida: %d\n", pedidos[i].numeroBebida);
            printf("Quantidade da Bebida: %d\n", pedidos[i].quantidadeBebida);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Pedido nao encontrado!\n");
    }
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    Pedido pedidos[MAX_PEDIDOS];
    int totalPedidos = 0;
    int opcao;

    do {
        printf("\nMenu Inicial:\n");
        printf("1. Realizar Pedido\n");
        printf("2. Visualizar Pedidos\n");
        printf("3. Buscar Pedido\n");
        printf("4. Encerrar Programa\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                realizarPedido(pedidos, &totalPedidos);
                break;
            case 2:
                visualizarPedidos(pedidos, totalPedidos);
                break;
            case 3: {
                int numeroPedidoBusca;
                printf("Digite o numero do pedido a ser buscado: ");
                scanf("%d", &numeroPedidoBusca);
                buscarPedido(pedidos, totalPedidos, numeroPedidoBusca);
                break;
            }
            case 4:
                printf("\nEncerrando o programa. Obrigado!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
} */
