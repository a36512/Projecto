#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define NR 100
typedef struct
{
	long int numero;
	char nome[60];		/* Palavras ligadas. Ex: Carlos_Marinho */		
	char morada[60];
	int BI_CC;
	int carta_de_conducao;		/* 0=livre	1=ocupado	*/
	int estado; 
}cliente;
typedef struct
{
	int estado;
	int numero;
	char marca[60];		/* Palavras ligadas. Ex: Carlos_Marinho */		
	char modelo;
	char cor;
	int cilindrada;
	int ano_de_aquis;
	char matric[60];
	char valor_dia;
	float combustivel;
	float Kms;
	float preco_de_aquis;		
}automovel;
typedef automovel AUTOMOVEIS[NR];
typedef struct
{
	long int ident_auto;
	char ident_cliente[60];		/* Palavras ligadas. Ex: Carlos_Marinho */		
	char data_inicio[60];
	int data_fim;
	int Km_percorridos;
	int preco_final;
	int registo_acidentes;
}aluguer;
void lerauto(AUTOMOVEIS *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("c:\\auto.txt","r")))
	{
		printf("Erro na Abertura de Leitura <Enter para Sair>");
		getch();
        exit(0);
	}
	for(n=1;n<NR;n++)
	{
		fscanf(f,"%ld\n%s\n%d\n", &((*x)[n].numero),&((*x)[n].nome),&((*x)[n].automovel));
	}
	fclose(f);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}

void mostrarauto(auto *x)
{
	int n;
	system ("cls");
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!==0) /* Como todos os carros têm um numero o zero é um carro inexistente */
		{
			printf("NUMERO=%d\nMARCA=%c\nMODELO=&c\nCOR=%c\nCILINDRADA=%d\nANO_DE_AQUIS=%d\nMATRIC=%c\nVALOR_DIA=%c\nCOMBUSTIVEL=%f\nKMS=%f\nPRECO_DE_AQUIS=%f\n\n",
			x[n].numero,x[n].marca,x[n].modelo,x[n].cor,x[n].cilindrada,x[n].ano_de_aquis,x[n].matric,x[n].valor_dia,x[n].combustivel,x[n].Kms,x[n].preco_de_aquis);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

int inserirauto(auto *x)
 {
	int n;
	long int inser;
	system ("cls");
	printf("Qual o automóvel que pretende inserir? ");
	scanf("%d",&inser);
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!=1)
		{
			x[n].numero=inser;
			printf("\n\nNOME=?");scanf("%s", x[n].nome);
			printf("\n\nNOTA=?");scanf("%d", &x[n].nota);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return(1);
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}

int eliminarauto(auto *x)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o Numero do aluno que quer Eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NR;n++)
	{
		if(x[n].numero==eli)
		{
			printf("\n\nNUMERO=%ld\nNOME=%s\nNOTA=%d\nESTADO=%d\n\n",
			x[n].numero,x[n].nome,x[n].nota,x[n].estado);
			printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();

			if (confere!='S' && confere!='s')    return(0);

			x[n].estado=0;
			printf("\n\n\nRegisto eliminado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}


void gravarauto(auto *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("c:\\auto.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
		getch();  exit(0);
	}

	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(f,"%ld\n%s\n%d\n%d\n",x[n].numero,x[n].nome,
						      x[n].nota, x[n].estado);
		}
	}
	fclose(f);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); getch();
}
void lercliente(cliente *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("c:\\cliente.txt","r")))
	{
		printf("Erro na Abertura de Leitura <Enter para Sair>");
		getch(); exit(0);
	}
	for(n=1;n<NR;n++)
	{
		fscanf(f,"%ld\n%s\n%d\n%d\n", &x[n].numero,x[n].nome,
					      &x[n].nota, &x[n].estado, &x[n].carta_de_conducao);
	}
	fclose(f);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}

void mostrarcliente(cliente *x)
{
	int n;
	system ("cls");
	for(n=1;n<NR;n++)
	{
		if(x[n].nome!=="")
		{
			printf("NUMERO=%ld\nNOME=%s\nNOTA=%d\nESTADO=%d\n\n",
			x[n].numero,x[n].nome,x[n].nota, x[n].estado);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

int inserircliente(cliente *x)
{
	int n;
	long int inser;
	system ("cls");
	printf("Qual o Numero do aluno que quer Inserir? ");
	scanf("%ld",&inser);
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!=1)
		{
			x[n].numero=inser;
			printf("\n\nNOME=?");scanf("%s", x[n].nome);
			printf("\n\nNOTA=?");scanf("%d", &x[n].nota);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return(1);
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}

int eliminarcliente(cliente *x)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual a informação de cliente que quer Eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NR;n++)
	{
		if(x[n].numero==eli)
		{
			printf("\n\nNUMERO=%ld\nNOME=%s\nNOTA=%d\nESTADO=%d\n\n",
			x[n].numero,x[n].nome,x[n].nota,x[n].estado);
			printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();

			if (confere!='S' && confere!='s')    return(0);

			x[n].estado=0;
			printf("\n\n\nRegisto eliminado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}


void gravarcliente(cliente *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("c:\\cliente.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
		getch();  exit(0);
	}

	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(f,"%ld\n%s\n%d\n%d\n",x[n].numero,x[n].nome,
						      x[n].nota, x[n].estado);
		}
	}
	fclose(f);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); getch();
}
void lerrent(rent *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("c:\\cliente.txt","r")))
	{
		printf("Erro na Abertura de Leitura <Enter para Sair>");
		getch(); exit(0);
	}
	for(n=1;n<NR;n++)
	{
		fscanf(f,"%ld\n%s\n%d\n%d\n", &x[n].numero,x[n].nome,
					      &x[n].nota, &x[n].estado);
	}
	fclose(f);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}

void mostrarrent(rent *x)
{
	int n;
	system ("cls");
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			printf("NUMERO=%ld\nNOME=%s\nNOTA=%d\nESTADO=%d\n\n",
			x[n].numero,x[n].nome,x[n].nota, x[n].estado);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

int inserirrent(rent *x)
{
	int n;
	long int inser;
	system ("cls");
	printf("Qual o Numero do aluno que quer Inserir? ");
	scanf("%ld",&inser);
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!=1)
		{
			x[n].numero=inser;
			printf("\n\nNOME=?");scanf("%s", x[n].nome);
			printf("\n\nNOTA=?");scanf("%d", &x[n].nota);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return(1);
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}void gravarrent(rent *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("c:\\rent.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
		getch();  exit(0);
	}

	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(f,"%ld\n%s\n%d\n%d\n",x[n].numero,x[n].nome,
						      x[n].nota, x[n].estado);
		}
	}
	fclose(f);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); getch();
}
{
void main(void) /* Inicio do programa */ 
{
	char op; /* */
	int menu_inicial;
	int n;
	cliente client[NR]; /* Criar um array Client do tipo cliente */
	auto car[NR];	/*Criar um array car do tipo auto */
	aluguer rent[NR]; /* Criar um array rent do tipo aluguer */
	for(n=0;n<NR;n++)
	{	
		car[n].estado=0;   /* limpa todo o Array de registos de carros*/
		client[n].estado=0;   /* limpa todo o Array de registos de clientes */
		rent[n].estado=0;    /* Limpar todo o Array de registos de aluguer */
	}
  do
  {
	cls;
   printf ("menu inicial");
   printf ("1- Cliente");
   printf ("2- Automóveis");
   printf ("3­ Aluguer");
   printf ("4- Pesquisas");
   printf ("5- Estatistícas"); 
   printf ("6- Terminar / Sair"); 
   scanf (menu_inicial);
   		while menu_inicial=1
   		{
   			cls;
   			printf ("menu cliente");
   			printf ("1- listar clientes");
   			printf ("2- Novo cliente");
   			printf ("3­ Alterar cliente");
   			printf ("4- Apagar cliente");
   			printf ("5- Voltar ao menu inicial"); 
   			scanf (menu_cliente);
   			lercliente(client); break;  /* chamar a função lercliente para copiar todo o conteudo do ficheiro de clientes para o array client */
   				while menu_cliente=1
   				{
   					mostrarcliente(client); break;   /* chamar a função mostrarcliente que envia psrs o ecran a listagem de todos os clientes */
   					menu_cliente==0;	   
   				}
   				while menu cliente=2
   				{
   					inserircliente(client); break;
   					menu_cliente==0;
   				}
   				while menu cliente=3
   				while menu cliente=4
   				{
   					eliminarcliente(client); break;
   					menu_cliente==0;
   				}
   				while menu cliente=5 
   				{
   					menu_inicial==0;
   					menu_cliente==0;
   					gravarcliente(client); break;
   				}
   
   		}	
   		while menu_inicial=2
   		{	
   			cls
   			printf ("menu do automóvel");
   			printf ("1- listar automóvel");
   			printf ("2- Novo automóvel");
   			printf ("3­ Alterar automóvel");
   			printf ("4- Apagar automóvel");
   			printf ("5- Voltar ao menu inicial"); 
   			scanf (menu_auto);
   			lerauto(car); break;
   				while menu_auto=1
   				{
   					 mostrarauto(car); break;
   					 menu_auto==0;
   				}
   				while menu_auto=2
   				{
   					inserirauto(car); break;
   					menu_auto==0;
   				}
   				while menu_auto=3
   				while menu_auto=4
   				{
   					eliminarauto(car); break;
   					menu_auto==0;
   				}
   				while menu_auto=5 
   				{
   					menu_inicial==0;
   					gravarauto(car); break;
   				}	
		}	
		while menu_inicial=3
		{	
			cls;
			printf ("menu do aluguer");
   			printf ("1- listar aluguer");
   			printf ("2- novo aluguer");
   			printf ("3- Voltar ao menu inicial");
   			scanf (menu_aluguer);
   				while menu_aluguer=1
   				{
   					mostrarrent(rent); break;
   					menu_auto==0;
   				}
   				while menu_aluguer=2
   				{
   					inserirrent(rent); break;
   					menu_auto==0;
   				}
   				while menu_aluguer=3
   				{
   					menu_inicial==0;
   					menu_auto==0;
   				}
		}
		while menu_inicial=4
   		{
			cls;
   			printf ("menu das pesquisas");
   			printf ("1- pesquisa por cliente");
   			printf ("2- pesquisa por automóvel");
   			printf ("3- pesquisa do aluguer por data");
   			printf ("4- pesquisa do aluguer por carro");
   			printf ("5- pesquisa do aluguer por cliente");
   			printf ("6- Voltar ao menu inicial");
			scanf (menu_pesquisas);
   				while menu_pesquisas=1
   				while menu_pesquisas=2
   				while menu_pesquisas=3
   				while menu_pesquisas=4
   				while menu_pesquisas=5 
   				while menu_pesquisas=6
   				{
   					menu_inicial==0;
   				}
   		}
   		while menu_inicial=5
   		{
   			cls;
   			printf  ("menu das estatísticas");
   			printf  ("1- veículo com mais alugueres");
   			printf  ("2- veículo com mais Km's");
   			printf  ("3- veículo com maior número de acidentes");
   			printf  ("4- média das distancias percorridas");
   			printf  ("5- maior viagem em termos de distancias");
   			printf  ("6- Número médio de dias de aluguer por veículo");
   			printf  ("7- Número de dias que cada veículo esteve parado");
   			printf  ("8- Cliente que fez mais alugueres");
   			printf  ("9- Cliente que percorreu maior distância"); 
   			printf  ("10- Cliente com maior número de acidentes");
   			printf  ("11- Voltar ao menu principal");
   			scanf (menu_estatisticas);
   				while menu_estatisticas=1
   				while menu_estatisticas=2
   				while menu_estatisticas=3
   				while menu_estatisticas=4
   				while menu_estatisticas=5 
   				while menu_estatisticas=6
   				while menu_estatisticas=7
   				while menu_estatisticas=8
   				while menu_estatisticas=9
   				while menu_estatisticas=10
   				while menu_estatisticas=11 
   					{
   						menu_inicial==0;
   					}
   		}
  } while (menu_inicial=6) 
  exit(0);
}
  
		
		 
		 
			 
			 

