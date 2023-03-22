#include<stdio.h> // #include<iostream>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
using namespace std;

/*Cadastrar códigos e preços de itens*/

	int main(){

		setlocale(LC_ALL, "portuguese");
		
		bool quitMenu = false, tamanhoEscolhido = false, metodoEscolhido = false, insercaoModoTeste = false;
		int opcaoDefinirTamanho, idProdutoParaProcurar, tamanho, opcaoMenu, modoInsercao, idProdutoParaDeletar;
		
		srand(time(NULL));
		
		while (!tamanhoEscolhido) {
			printf("\n[DEFINIR TAMANHO DO VETOR]\n\n1 = Modo Padrão | 2 = Modo Teste\n\nEscolha: ");
			scanf("%d", &opcaoDefinirTamanho);
			
			switch (opcaoDefinirTamanho) {
				
				case 1:
					printf("\nDefinir quantidade de itens [Entre 1 e 200]: ");
					scanf("%d", &tamanho);
					
					if (tamanho < 1 || tamanho > 200) {
						printf("\nENTRADA INVÁLIDA\n");
					} else {
						tamanhoEscolhido = true;
					}
					break;
				
				case 2:
					tamanho = rand() % 200 + 1; //Números Pseudo-randômicos entre 1 e 200
					printf("\nDEBUG: tamanho = %d\n", + tamanho);
					tamanhoEscolhido = true;
					break;
				
				default:
					printf("\nENTRADA INVÁLIDA\n");
					
			}
			
		}
		
		int idProduto[tamanho];
		float precoProduto[tamanho];
		
		while (!metodoEscolhido) {
			printf("\n[MODO DE INSERÇÃO DE VALORES]\n\n1 = Modo Manual | 2 = Modo Teste\n\nEscolha: ");
			scanf("%d", &modoInsercao);
			
			switch (modoInsercao) {
				
				case 1:
					metodoEscolhido = true;
					break;
				
				case 2:
					insercaoModoTeste = true;
					metodoEscolhido = true;
					break;
				
				default:
					printf("\nENTRADA INVÁLIDA\n");
				
			}
			
		}
				
		if (!insercaoModoTeste) {
			
			for (int i = 0; i < tamanho; i++) {
				printf("\nInsira código do item %d [100000 - 999999]: ", (i + 1));
				scanf("%d", &idProduto[i]);
				
				printf("Insira preço do item %d [0,99 - 5000,00]: ", (i + 1));
				scanf("%f", &precoProduto[i]);
				
				if ( (idProduto[i] < 100000 || idProduto[i] > 999999) || (precoProduto[i] < 0.99 || precoProduto[i] > 5000) ) {
					printf("\nENTRADA INVÁLIDA. DIGITE NOVAMENTE\n");
					i--;
				}
				
			}
			
		} else {
			
			for (int i = 0; i < tamanho; i++) {
				idProduto[i] = rand() % 900000 + 100000; //Números Pseudo-randômicos entre 100000 e 999999
				precoProduto[i] = rand() % 5000 + 1; //Números Pseudo-randômicos entre 1 e 5000
				printf("\nDEBUG: idProduto[%d] = %d | precoProduto[%d] = %.2f\n", i, idProduto[i], i, precoProduto[i]);
			}
		}
		
		//Ordenar por código do produto
		for (int i = 0; i < tamanho; i++) {
			
			for (int j = i + 1; j < tamanho; j++) {
				
				if (idProduto[i] > idProduto[j]) {
					int aux = idProduto[i];
					idProduto[i] = idProduto[j];
					idProduto[j] = aux;
					
					float auxFloat = precoProduto[i];
					precoProduto[i] = precoProduto[j];
					precoProduto[j] = auxFloat;
			    }
			}
		}
		
		while (!quitMenu) {
			
			printf("\n[ESCOLHA]");
			printf("\n\n1 - Procurar um ID de item | 2 - Sair do menu | 3 - Mostrar ID e preço de todos os itens | 4 - Deletar IDs\n\ninput: ");
			scanf("%d", &opcaoMenu);
			
			bool indiceEncontrado = false, idDeletado = false;
			int inicio = 0, fim = tamanho - 1;
			
			switch (opcaoMenu) {
				
				case 1:
					printf("\nInsira um ID de item para procurar: ");
					scanf("%d", &idProdutoParaProcurar);
					
					while (inicio <= fim) {
						int meio = (inicio + fim) / 2;
						
						if (idProdutoParaProcurar == idProduto[meio]) {
							printf("\nCódigo %d encontrado na posição #%d!\n", idProdutoParaProcurar, meio);
							printf("\n---------INFORMAÇÕES----------------------------\n");
							printf("\nID do item: %d | Preço do item: R$%.2f\n", idProduto[meio], precoProduto[meio]);
							printf("\n------------------------------------------------\n");
							indiceEncontrado = true;
							break;
							
						} else if (idProdutoParaProcurar < idProduto[meio]) {
							fim = meio - 1;
						} else if (idProdutoParaProcurar > idProduto[meio]) {
							inicio = meio + 1;
						}
												
					}
					
					if (!indiceEncontrado) {
						printf("\nCódigo %d não encontrado\n", idProdutoParaProcurar);
					}
					
					break;
				
				case 2:
					printf("\n[SAINDO DO MENU]");
					quitMenu = true;
					break;
				
				case 3:
					printf("\n---------Imprimindo------------------------------\n\n");
					
					for(int i = 0; i < tamanho; i++) {
						printf("\nID do Item[%d] = %d | Preço do Item[%d] = R$%.2f\n", i, idProduto[i], i, precoProduto[i]);
					}
					
					printf("\n---------Finalizando processo----------------------\n");
					
					break;
					
				case 4:
					printf("\nInsira ID para Deletar: ");
					scanf("%d", &idProdutoParaDeletar);
					
					while (inicio <= fim) {
						int meio = (inicio + fim) / 2;
						
						if (idProdutoParaDeletar == idProduto[meio]) {
							printf("\nCódigo %d encontrado na posição #%d!\n", idProdutoParaDeletar, meio);
									                	
		                    for (int j = meio; j < (tamanho - 1); j++) {
		                        idProduto[j] = idProduto[j + 1];
		                        precoProduto[j] = precoProduto[j + 1];
		                    }
		                    
		                    printf("\nCódigo %d deletado com sucesso!\n", idProdutoParaDeletar);
		                    tamanho = tamanho - 1;
		                    idDeletado = true;
		                    break;
							
						} else if (idProdutoParaDeletar < idProduto[meio]) {
							fim = meio - 1;
						} else if (idProdutoParaDeletar > idProduto[meio]) {
							inicio = meio + 1;
						}
												
					}
					
					if (!idDeletado) {
						printf("\nCódigo %d não encontrado\n", idProdutoParaDeletar);
					}
	        	
					break;	
				
				default:
					printf("\nENTRADA INVÁLIDA\n");
					
			}
			
		}		

		printf("\n\n");
    	system("pause");

	return 0;
}
