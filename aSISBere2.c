#include <stdio.h> //Biblioteca

float processarvenda(int *, float); //prototipo da função processar venda
float pagamento(float); //prototipo da função pagamento

int main(){
    //Variaveis
    int opmenu, codigo, estoque[40], quantidade, caixa_aberto = 0;
    float preco[40], valorlimpeza = 0, valoralimento = 0, valorpadaria = 0, valorcompra = 0, valor_caixaberto = 0;
    float faturamento = 0, valorpago;

    /*Definindo estoque e preço dos produtos de limpeza*/
    estoque[11] = 50;     preco[11] = 1.99;
    estoque[12] = 30;     preco[12] = 8.99;
    estoque[13] = 0;      preco[13] = 1.50;
    estoque[14] = 20;     preco[14] = 15.00;
    estoque[15] = 100;    preco[15] = 4.99;
    estoque[16] = 15;     preco[16] = 7.99;
    estoque[17] = 60;     preco[17] = 1.00;

    /*Definindo estoque e preço dos alimentos*/
    estoque[21] = 10;     preco[21] = 19.99;
    estoque[22] = 15;     preco[22] = 5.90;
    estoque[23] = 10;     preco[23] = 4.50;
    estoque[24] = 5;      preco[24] = 8.00;
    estoque[25] = 20;     preco[25] = 5.00;
    estoque[26] = 6;      preco[26] = 2.00;
    estoque[27] = 15;     preco[27] = 5.00;

    /*Definindo preço dos produtos da padaria*/
    preco[31] = 9.50;
    preco[32] = 12.50;
    preco[33] = 1.90;
    preco[34] = 8.50;
    preco[35] = 12.50;
    preco[36] = 2.50;
    preco[37] = 17.50;

    //Loop principal
    do
    {
        //Menu principal
        printf("\n======== Menu Principal ========\n");
        printf("    1 - Material de Limpeza     \n");
        printf("    2 - Venda de Alimento       \n");
        printf("    3 - Padaria                 \n");
        printf("    4 - Pagamento               \n");
        printf("    5 - Abertura de caixa       \n");
        printf("    6 - Fechamento de caixa     \n");
        printf("    7 - Sair                    \n");
        printf("================================\n");
        scanf("%d", &opmenu);//Le opção digitada

        switch (opmenu)
        {
        case 1:
            //Verifica se o caixa está aberto
            if(caixa_aberto != 1){
                printf("Abra o caixa primeiro!");
                break;
            }

            //Exibe menu de limpeza
            printf("=============== Menu Material de Limpeza ===============\n");
            printf("           11 - Detergente            R$%.2f (%d)        \n", preco[11], estoque[11]);
            printf("           12 - Sabão em Pó(1kg)      R$%.2f (%d)        \n", preco[12], estoque[12]);
            printf("           13 - Esponja               R$%.2f (%d)        \n", preco[13], estoque[13]);
            printf("           14 - Amaciante             R$%.2f (%d)        \n", preco[14], estoque[14]);
            printf("           15 - Bucha de Pia(kit c/3) R$%.2f (%d)        \n", preco[15], estoque[15]);
            printf("           16 - Desinfetante(1Lt)     R$%.2f (%d)        \n", preco[16], estoque[16]);
            printf("           17 - Sabão em Barra(Un)    R$%.2f (%d)        \n", preco[17], estoque[17]);
            printf("=========================================================\n");
            scanf("%d", &codigo);

            //Verifica se codigo é valido
            if(codigo >= 11 && codigo <= 17){
                // Chama função de processar a venda e soma o valor retornado no total da categoria
                valorlimpeza += processarvenda(&estoque[codigo], preco[codigo]);
            }   
            else{
                printf("Código inválido!\n");
            }
            break;
        case 2:
            if(caixa_aberto != 1){
                printf("Abra o caixa primeiro!");
                break;
            }    

            printf("=============== Menu Venda de Alimento ================\n");
            printf("           21 - Café(500g)              R$%.2f (%d)      \n", preco[21], estoque[21]);
            printf("           22 - Leite(cx)               R$%.2f (%d)      \n", preco[22], estoque[22]);
            printf("           23 - Arroz(1kg)              R$%.2f (%d)      \n", preco[23], estoque[23]);
            printf("           24 - Feijão Preto(1kg)       R$%.2f (%d)      \n", preco[24], estoque[24]);
            printf("           25 - Açucar(1kg)             R$%.2f (%d)      \n", preco[25], estoque[25]);
            printf("           26 - Sal(1kg)                R$%.2f (%d)      \n", preco[26], estoque[26]);
            printf("           27 - Farinha de Trigo(1kg)   R$%.2f (%d)      \n", preco[27], estoque[27]);
            printf("=========================================================\n");
            scanf("%d", &codigo);

            
           if(codigo >= 21 && codigo <= 27){
                valoralimento += processarvenda(&estoque[codigo], preco[codigo]);
            }   
            else{
                printf("Código inválido!\n");
            }
            break;
        case 3:
            if(caixa_aberto != 1){
                printf("Abra o caixa primeiro!");
                break;
            }

            printf("==================== Menu da Padaria ====================\n");
            printf("           31 - Pão de Forma(pct)   R$%.2f (%d)          \n", preco[31], estoque[31]);
            printf("           32 - Pão Integral(pct)   R$%.2f (%d)          \n", preco[32], estoque[32]);
            printf("           33 - Pão Francês(Un)     R$%.2f (%d)          \n", preco[33], estoque[33]);
            printf("           34 - Sonho(Un)           R$%.2f (%d)          \n", preco[34], estoque[34]);
            printf("           35 - Biscoito(kg)        R$%.2f (%d)          \n", preco[35], estoque[35]);
            printf("           36 - Pão Doce(Un)        R$%.2f (%d)          \n", preco[36], estoque[36]);
            printf("           37 - Salgado(Un)         R$%.2f (%d)          \n", preco[37], estoque[37]);
            printf("=========================================================\n");
            scanf("%d", &codigo);

            if(codigo >= 31 && codigo <= 37){
                valorpadaria += processarvenda(&estoque[codigo], preco[codigo]);
            }   
            else{
                printf("Código inválido!\n");
            }
            break;
        case 4:
            //Verifica se tem produto no carrinho
            if(valorlimpeza + valoralimento + valorpadaria == 0){
                printf("Carrinho vazio!");
                break;
            }
            else{
                //Soma total da compra
                valorcompra = valorlimpeza + valoralimento + valorpadaria;
                // Mostra valores por categoria e o total de todas as categorias
                printf("Valor por categoria:\n");
                printf("Limpeza: R$%.2f\n", valorlimpeza);
                printf("Alimento: R$%.2f\n", valoralimento);
                printf("Padaria: R$%.2f\n", valorpadaria);
                 printf("Valor total: R$%.2f\n", valorcompra);
            }

            // Chama função de pagamento
            valorpago = pagamento(valorcompra);
            // Se pagamento foi válido
            if(valorpago > 0){
                //Soma no faturamento
                faturamento += valorpago;

                //Zero o carrinho
                valorlimpeza = 0;
                valoralimento = 0;
                valorpadaria = 0;
                valorcompra = 0;
            }
            break;
        case 5:
            //Abre o caixa
            printf("Digite valor em caixa para troco:\n");
            scanf("%f", &valor_caixaberto);    

            // Atualiza estoque da padaria
            printf("Atualize o estoque da padaria:\n");
            for(int i = 31;i <= 37; i++){
                printf("Produto %d quantidade: ", i);
                scanf("%d", &estoque[i]);
            }
            //Marca que o caixa como aberto
            caixa_aberto = 1;
            break;
        case 6:
            // Mostra fechamento do caixa
            printf("=== Fechamento do caixa ===\n");
            printf("Valor inicial: R$%.2f\n", valor_caixaberto);
            printf("Faturamento: R$%.2f\n", faturamento);
            printf("Valor final em caixa: R$%.2f\n", faturamento + valor_caixaberto);
            printf("===========================");
            break;
        case 7: 
            //Encerra o programa
            printf("Saindo...\n");
            break;
        
        default:
            printf("Opção invalida!\n");
            break;
        }

    } while (opmenu != 7); //programa continua até escolher sair
    


    return 0;
}

//Função de processar a venda (diminui o estoque e calcula valor)
float processarvenda(int *estoqueitem, float precoitem){
    
    int quantidade;
    float totalitem;

    //Verifica se tem estoque
    if(*estoqueitem == 0){
        printf("Sem estoque!");
        return 0;
    }

    printf("Digite a quantidade que deseja: \n");
    scanf("%d", &quantidade);

    // Verifica se há quantidade suficiente
    if(quantidade > *estoqueitem){
        printf("Estoque insuficiente\n");
        return 0;
    }

    *estoqueitem -= quantidade; // Atualiza estoque

    totalitem = quantidade * precoitem; // Calcula total
    return totalitem; // Retorna valor da compra
}

//Função pagamento 
float pagamento(float total){
    int oppagamento, statusmaquina;
    float desconto = 0, valordesconto, recebido;

    // Escolha forma de pagamento
    printf("Forma de pagamento:\n");
    printf("1 - Dinheiro\n");
    printf("2 - Cartão\n");
    scanf("%d", &oppagamento);

    //Aplica desconto de acordo com o valor da compra
    if(oppagamento == 1){
        if(total <= 50){
            desconto = 0.05;
        }
        else if(total > 50 && total < 200){
            desconto = 0.10;
        }
        else{
            printf("Digite porcentagem de desconto: (ex: 3 para 3 porcento)\n");
            scanf("%f", &desconto);
            desconto = desconto / 100;
        }
        valordesconto = total - (total * desconto); // Calcula valor com desconto
        printf("Valor com o desconto R$%.2f\n", valordesconto);
        printf("Digite valor recebido: ");
        scanf("%f", &recebido);
        // Verifica se valor é suficiente
        if(recebido < valordesconto){
            printf("Valor insuficinente!\n");
            return 0;
        }
        printf("Troco: R$%.2f", recebido - valordesconto);
        return valordesconto; // Retorna valor pago para somar na variavel faturamento
    }
    else{
        //Pagamento no cartão
        printf("Digite status da maquina:\n");
        printf("1 - Sim\n0 - Não\n");
        scanf("%d", &statusmaquina);
        if(statusmaquina == 1){
            return total; // Retorna valor sem desconto para somar na variavel faturamento
        }
        else{
            return 0; // Pagamento não realizado (erro no pagamento)
        }
    }

}
