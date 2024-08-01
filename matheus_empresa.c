#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocações de textos por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\n\tRegistro de nomes\n\n");
	printf("Digite o cpf: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abre o arquivo
	fprintf(file,"\n");
	fprintf(file,"CPF: ");
	fprintf(file,cpf); // salvo o valor da variavel
	fprintf(file,"\n");
	fclose(file); // fecha o arquivo
	
	printf("Digite o primeiro nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome e Sobrenome: ");
	fprintf(file,nome);
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);	
	
    system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r");
	  	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
		
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);	
	}
  	
	system ("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser excluido: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if (file == NULL)
	{
		system("cls");
		printf("Usuário não encontrado\n");
		system("pause");
	}
	
	if (file != NULL)
	{
		system("cls");
		printf ("usuário excluido com sucesso!\n");
		system("pause");
	}

}

int padrao()
{
	printf("\n\tEssa opção não está disponivel\n\n");
	system("pause");
}



int main()
{
	int opcao=0; //Definindo as variaveis
	int loop=1;
	char senhadm[10]= "a";
	int comparacao;
	
	printf("Login de admin\n\nDigite sua senha: ");
	scanf("%s",senhadm);
	
	comparacao = strcmp(senhadm, "admin");
	
	if(comparacao == 0)
	{
	
		for(loop=1;loop=1;) //repetição
		{
			
			system("cls"); //Limpar a tela  
			
			setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
		
			printf("Empresa de Matheus\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção desejada: "); //fim do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usuário
		
			system("cls");
		
			switch(opcao)
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
				
				case 4:
				printf("Obrigado por utilizar o nosso sistema");
				return 0;
				break;
			
				default:
				padrao();
				break;
				
			} 
		}
	}
	else
	printf("\nsenha incorreta");
}
