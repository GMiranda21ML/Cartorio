#include <stdio.h> //biblioteca de comunica��o do usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�os de memoria
#include <locale.h> //biblioteca de loca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registrar() {
	char arquivo[50];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[50];
	
	printf("Voc� escolheu o registro de nomes!\n\n");
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings tipo x = y, dar o nome?
	
	FILE *file; //chamando a fun��o FILE para criar um arquivo 
	file = fopen(arquivo, "w"); //abre um arquivo novo com o "w"
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza a informa��o no arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
		
	system("pause");
}


int consultar() {
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Voc� escolheu consultar nomes!\n\n");
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" de ler o arquivo com o nome do cpf

	if (file == NULL) {
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}	
	
	while (fgets(conteudo, 200, file) != NULL) { //fgets = busca, escrevendo na variavel conteudo ate 200 char no file for diferente de nulo
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
}


int deletar() {
	char cpf[40];
	
	printf("Voc� escolheu deletar nomes!\n\n");
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s", cpf);

	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL) {
		printf("N�o foi possivel deletar o arquivo, n�o localizado!\n");
		
	} else {
		printf("Arquivo deletado com sucesso!\n");
	}
	
	
	
	
	
	system("pause");
}


int main() {
	
	//definindo variaveis
	int opcao = 0; 
	int x = 1;
	
	while(1) {
		
		system("cls"); //limpar terminal
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n"); //\t � tipo um tab
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t0 - Encerrar o programa\n\n");
		printf("Digite sua op��o: "); //fim do menu
		scanf("%d", &opcao); //armazena a escolha do usuario
		
		system("cls"); 
		
		switch (opcao) { //inicio da sele��o
			case 0:
				printf("Saindo do programa...\n\n");
				printf("Esse Software � de Gabriel Miranda Mucarbel de Lima!\n");
				return 0;
			case 1:
				registrar(opcao);
				break;
				
			case 2:
				consultar();
				break;
				
			case 3:
				deletar();
				break;
					
			default:
				printf("Op��o invalida!\n\n");
				system("pause");
				break;		
		} //fim da sele��o
		
	}
	
	// printf("Esse Software � de Gabriel Miranda Mucarbel de Lima!\n");
	
	return 0;

	
	
}

