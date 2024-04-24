#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>
#include <string.h> // biblioteca das strings
int registro()
{
	//// criação das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	////armazenando as informações que o usuário aplica no sistema
	printf("digite o cpf a ser cadastrado:\n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //copia os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); // salva o valor do arquivo
	fclose (file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	
	//////////////////////armazenamento da variavel nome
	printf("Digite o nome a ser cadastrado\n");
	scanf ("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	
	//////////////////////armazenamento da variavel sobrenome
	printf("Digite o sobrenome a ser cadastrado\n");
	scanf("%s",sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	 
	//////////////////////armazenamento da variavel cargo
	printf("Digite o cargo a ser cadastrado\n");
	scanf("%s",cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	
	///declarando as variáveis para a função reconhecer nos comandos
	char cpf[40];
	char conteudo[200];
	
	/// coletando informações do usuário 
	printf("Digite o cpf a ser consultado:\n");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets (conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");


	if(file == NULL)
	{
		printf("Esse CPF não consta no sistema.\n\n");
		system("pause");
	}
	
}

int main()
{
	setlocale (LC_ALL, "Portuguese");
	
	int opcao=0; //definindo variaveis
	int laco=1;
	
	system ("cls");
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	setlocale (LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf ("### Cartório da EBAC ###\n\n"); //inicio menu
	printf ("Escolha a opção desejada no menu:\n\n");
	printf ("\t1 - Registrar nomes\n");
	printf ("\t2 - Consultar nomes\n");
	printf ("\t3 - Deletar nomes\n\n");

	printf ("Opção: "); //fim menu

	scanf("%d", &opcao); //armazenando escolha do user
	
	system("cls");
	
	switch(opcao) //casos da variavel
	{
		case 1:
			registro();
			break;
			
		case 2:
			consulta();
			break;
		
		case 3:
			deletar();
			break;
				
			
		default:
			printf("Essa opção não está disponível\n"); 
			system("pause");
			break;
	}
	
	}
}
