#include <stdio.h>

int main(){

    int expediente;
    int menu;
    int quantidade, quantidadevenda = 0;
    int estoque[40];
    float preco[40];
    float faturamento = 0;
   

    printf("Abrir expediente ?\n 1 - Sim\n 2 - Não\n ");
    scanf("%d", &expediente);

    while (expediente == 1){
        do
        {
            printf("======== Menu Principal ========\n");
            printf("=   1 - Material de Limpeza    =\n");
            printf("=   2 - Venda de Alimento      =\n");
            printf("=   3 - Padaria                =\n");
            printf("=   4 - Pagamento              =\n");
            printf("=   5 - Abertura de caixa      =\n");
            printf("=   6 - Fechamento de caixa    =\n");
            printf("=   7 - Sair                   =\n");
            printf("================================\n");
            scanf("%d", &menu);

            switch (menu)
            {
            case 1:
                
                
                printf("====== Menu Material de Limpeza ======\n");
                printf("=      11 - Detergente R$%d (%d)     =\n", );
                printf("======================================\n");
                break;
            
            default:
                break;
            }

        } while (menu != 7);
        
        printf("Manter expediente aberto ?\n 1 - Sim\n 2 - Não\n ");
        scanf("%d", &expediente);
    }
    if(expediente == 2){
        printf("Encerrando expediente: \n");
        printf("Quantidade de venda %d\n", quantidadevenda);
        printf("Valor do faturamento %d\n", faturamento);
    }
    

    return 0;
}