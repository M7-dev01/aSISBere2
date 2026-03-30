#include <stdio.h>

int main(){

    int expediente;
    int menu;
    int formapagamento;
    int codigo;
    int quantidade = 0, quantidadevenda = 0;
    int statusmaquina;
    int estoque[40];
    float preco[40];
    float valorlimpeza = 0, valoralimento = 0, valorpadaria = 0, valorcompra = 0, valordesconto = 0, valorrecebido = 0, pagardesconto = 0, troco = 0;
    float desconto;

    float faturamento = 0;
   
    //cadastro de quantidade de estoque dos produtos
    //limpeza
    estoque[11] = 50;
    estoque[12] = 30;
    estoque[13] = 0;
    estoque[14] = 20;
    estoque[15] = 100;
    estoque[16] = 15;
    estoque[17] = 60;
    //alimento
    estoque[21] = 10;
    estoque[22] = 15;
    estoque[23] = 10;
    estoque[24] = 5;
    estoque[25] = 20;
    estoque[26] = 6;
    estoque[27] = 15;
    //padaria
    estoque[31] = 0;
    estoque[32] = 0;
    estoque[33] = 0;
    estoque[34] = 0;
    estoque[35] = 0;
    estoque[36] = 0;
    estoque[37] = 0;
    
    //cadastro de preço dos produtos
    //limpeza
    preco[11] = 1.99;
    preco[12] = 8.99;
    preco[13] = 1.50;
    preco[14] = 15.00;
    preco[15] = 4.99;
    preco[16] = 7.99;
    preco[17] = 1.00;
    //alimento
    preco[21] = 19.99;
    preco[22] = 5.90;
    preco[23] = 4.50;
    preco[24] = 8.00;
    preco[25] = 5.00;
    preco[26] = 2.00;
    preco[27] = 5.00;
    //padaria
    preco[31] = 9.50;
    preco[32] = 12.50;
    preco[33] = 1.90;
    preco[34] = 8.50;
    preco[35] = 12.50;
    preco[36] = 2.50;
    preco[37] = 17.50;

    printf("Abrir expediente ?\n 1 - Sim\n 2 - Não\n ");
    scanf("%d", &expediente);

    while (expediente == 1){
        do
        {
            printf("======== Menu Principal ========\n");
            printf("    1 - Material de Limpeza     \n");
            printf("    2 - Venda de Alimento       \n");
            printf("    3 - Padaria                 \n");
            printf("    4 - Pagamento               \n");
            printf("    5 - Abertura de caixa       \n");
            printf("    6 - Fechamento de caixa     \n");
            printf("    7 - Sair                    \n");
            printf("================================\n");
            scanf("%d", &menu);

            switch (menu)
            {
            case 1:

                printf("=============== Menu Material de Limpeza ===============\n");
                printf("           11 - Detergente R$%.2f (%d)                   \n", preco[11], estoque[11]);
                printf("           12 - Sabão em Pó(1kg) R$%.2f (%d)             \n", preco[12], estoque[12]);
                printf("           13 - Esponja R$%.2f (%d)                      \n", preco[13], estoque[13]);
                printf("           14 - Amaciante R$%.2f (%d)                    \n", preco[14], estoque[14]);
                printf("           15 - Bucha de Pia(kit c/3) R$%.2f (%d)        \n", preco[15], estoque[15]);
                printf("           16 - Desinfetante(1Lt) R$%.2f (%d)            \n", preco[16], estoque[16]);
                printf("           17 - Sabão em Barra(Un) R$%.2f (%d)           \n", preco[17], estoque[17]);
                printf("=========================================================\n");
                scanf("%d", &codigo);
                printf("Digite a quantidade que deseja: \n");
                scanf("%d", &quantidade);

                if(estoque[codigo] == 0){
                    printf("Produto sem estoque! \n");
                }
                else if(quantidade > estoque[codigo]){
                    printf("Quantidade indisponivel! \n");
                }
                else{
                valorlimpeza += quantidade * preco[codigo];
                estoque[codigo] -= quantidade;
                printf("O valor atual dos produtos de limpeza é R$%.2f\n", valorlimpeza);
                }
                break;
            case 2:
                printf("============== Menu da Venda de Alimentos ==============\n");
                printf("          21 - Café (500g) R$%.2f (%d)                  \n", preco[21], estoque[21]);
                printf("          22 - Leite(cx) R$%.2f (%d)                    \n", preco[22], estoque[22]);
                printf("          23 - Arroz(1kg) R$%.2f (%d)                   \n", preco[23], estoque[23]);
                printf("          24 - Feijão Preto(1kg) R$%.2f (%d)            \n", preco[24], estoque[24]);
                printf("          25 - Açucar(1kg) R$%.2f (%d)                  \n", preco[25], estoque[25]);
                printf("          26 - Sal(1kg) R$%.2f (%d)                     \n", preco[26], estoque[26]);
                printf("          27 - Farinha de Trigo(1kg) R$%.2f (%d)        \n", preco[27], estoque[27]);
                printf("========================================================\n");
                scanf("%d", &codigo);

                printf("Digite a quantidade que deseja: \n");
                scanf("%d", &quantidade);

                if(estoque[codigo] == 0){
                    printf("Produto sem estoque! \n");
                }
                else if(quantidade > estoque[codigo]){
                    printf("Quantidade indisponivel! \n");
                }
                else{
                valoralimento += quantidade * preco[codigo];
                estoque[codigo] -= quantidade;
                printf("O valor atual dos alimentos é R$%.2f\n", valoralimento);
                }
                break;
            case 3:
                printf("==================== Menu da Padaria ===================\n");
                printf("            31 - Pão de Forma(pct R$%.2f (%d)           \n", preco[31], estoque[31]);
                printf("            32 - Pão Integral(pct) R$%.2f (%d)          \n", preco[32], estoque[32]);
                printf("            33 - Pão Frânces(Un) R$%.2f (%d)            \n", preco[33], estoque[33]);
                printf("            34 - Sonho(Un) R$%.2f (%d)                  \n", preco[34], estoque[34]);
                printf("            35 - Biscoito(Kg) R$%.2f (%d)               \n", preco[35], estoque[35]);
                printf("            36 - Pão Doce(Un) R$%.2f (%d)               \n", preco[36], estoque[36]);
                printf("            37 - Salgado(Un) R$%.2f (%d)                \n", preco[37], estoque[37]);
                printf("========================================================\n");
                scanf("%d", &codigo);

                printf("Digite a quantidade que deseja: \n");
                scanf("%d", &quantidade);

                if(estoque[codigo] == 0){
                    printf("Produto sem estoque! \n");
                }
                else if(quantidade > estoque[codigo]){
                    printf("Quantidade indisponivel! \n");
                }
                else{
                valorpadaria += quantidade * preco[codigo];
                estoque[codigo] -= quantidade;
                printf("O valor atual da padaria é R$%.2f\n", valorpadaria);
                }
                break;
            case 4:
                valorcompra = valorlimpeza + valoralimento + valorpadaria;
                printf("O valor total da compra é %.2f\n", valorcompra);
                
                printf("Formas de pagamento: \n1 - Dinheiro(Tem desconto) \n2 - Cartão\n");
                scanf("%d", &formapagamento);

                switch (formapagamento)
                {
                case 1:
                    if(valorcompra >= 200.00){
                        printf("Digite o percentual de desconto que deseja dar: (Ex: 0.20 para 20 porcento de desconto)\n");
                        scanf("%f", &desconto);

                        valordesconto = valorcompra - (valorcompra * desconto);
                        printf("O valor a pagar com o desconto é R$%.2f\n", valordesconto);
                    }
                    else if(valorcompra > 50.00){
                        valordesconto = valorcompra * 0.90;
                        printf("O valor a pagar com o desconto é R$%.2f\n", valordesconto);
                    }
                    else{
                        valordesconto = valorcompra * 0.95;
                        printf("O valor a pagar com o desconto é R$%.2f\n", valordesconto);
                    }

                    printf("Digite o valor recebido pelo cliente: \n");
                    scanf("%f", &valorrecebido);

                    if(valorrecebido > pagardesconto){
                        troco = valorrecebido - pagardesconto;
                        printf("O troco é R$%.2f\n", troco);
                        faturamento += pagardesconto;
                        quantidadevenda++;
                        break;
                    }
                    else{
                        printf("Venda finalizada.\n");
                        faturamento += pagardesconto;
                        quantidadevenda++;
                        break;
                    }
                    break;
                case 2:
                    printf("Digite qual o status da máquina: \n1 - Pagamento ok \n2 - Pagamento não ok\n");
                    scanf("%d", &statusmaquina);
                    break;
                default:
                    printf("Opção invalida! \n");
                    break;
                }
                break;
            default:
                printf("Opção invalida!\n");
                break;
            }

        } while (menu != 7);
        
        printf("Manter expediente aberto ?\n 1 - Sim\n 2 - Não\n ");
        scanf("%d", &expediente);
    }
    if(expediente == 2){
        printf("Encerrando expediente: \n");
        printf("Quantidade de venda %d\n", quantidadevenda);
        printf("Valor do faturamento %.2f\n", faturamento);
    }
    

    return 0;
}
//fazer loop pagamento, abertura e fechamento de caixa ainda 
