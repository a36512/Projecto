#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NR 101
typedef struct
{
        long int numero;
        char nome[60];                /* Palavras ligadas. Ex: Carlos_Marinho */                
        char morada[60];
        int bi;
        char cc[20];                /* 0=livre        1=ocupado        */
        int estado;
}cliente;
typedef struct
{
        int estado;
        int numero;
        char marca[60];                /* Palavras ligadas. Ex: Carlos_Marinho */                
        char modelo[60];
        char cor[60];
        int cilindrada;
        int ano_de_aquis;
        char matric[60];
        float valor_dia;
        float combustivel;
        float Kms;
        float preco_de_aquis;                
}automovel;

typedef struct
{
	    int numero;
		int estado;
        long int ident_auto;
        char ident_cliente[60];                /* Palavras ligadas. Ex: Carlos_Marinho */                
        char data_inicio[10];
        char data_fim[10];
        int Km_percorridos;
        int preco_final;
        int registo_acidentes;
}aluguer;


int inserircliente(cliente *x)
{
	int n;
	long int inser;
	system ("cls");
	printf("Qual o numero do cliente que quer Inserir? ");
	scanf("%ld",&inser);
	for(n=1;n<NR;n++)
	{
		if(x[n].numero=-1)
		{
			x[n].numero=inser;
			printf("\n\nNUMERO=?");scanf("%ld", x[n].numero);
			printf("\n\nNOME=?");scanf("%c", x[n].nome);
			printf("\n\nMORADA=?");scanf("%c", &x[n].morada);
			printf("\n\nBI=?");scanf("%d", &x[n].bi);
			printf("\n\nCC=?");scanf("%c", &x[n].cc);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return(1);
			n==n++;
		    x[n].numero=-1;
			n==NR;
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}


void mostrarcliente(cliente *x)
{
        int n;
        system ("cls");
        for(n=1;n<NR;n++)
        {
                if(x[n].numero!=-1) /* Como todos os carros tem um numero o zero e um carro inexistente */
                
                {
                        printf("NUMERO=%ld\nNOME=%c\nMORADA=%c\nBI=%d\nCC=%d\nESTADO=%d\n",
                        x[n].numero, x[n].nome, x[n].morada, x[n].bi, x[n].cc, x[n].estado);
                }
                else
                {
                    n=NR;
                }
        }
        printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}


int alterarcliente(cliente *x)
{
        int n;
        long int inser;
        system ("cls");
        printf("Qual a informaçâo de cliente que deseja alterar?");
        
        scanf("%ld",&inser);
        for(n=1;n<NR;n++)
        {
                if(x[n].estado!=1)
                {
                        x[n].numero=inser;
                        printf("\n\nNUMERO=?");scanf("%ld", x[n].numero);
                        printf("\n\nNOME=?");scanf("%s", x[n].nome);
                        printf("\n\nMORADA=?");scanf("%s", &x[n].morada);
                        printf("\n\nBI=?");scanf("%d", &x[n].bi);
                        printf("\n\nCC=?");scanf("%d", &x[n].cc);
                        printf("\n\nESTADO=?");scanf("%d", &x[n].estado);
                        x[n].estado=1;
                        printf("\n\n\nRegisto Alterar <Enter para Continuar>");
                        getch();
                        return(1);
                }
        }
        printf("ERRO! Nao foi possivel Alterar"); getch(); return(0);
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
			fprintf(f,"NUMERO=%ld\nNOME=%c\nMORADA=%c\nBI=%d\nCC=%d\nESTADO=%d",
                        x[n].numero, x[n].nome, x[n].morada, x[n].bi, x[n].cc, x[n].estado);
		}
	}
	fclose(f);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); getch();
}

void lercliente(cliente *x)  /// função que le os clientes inseridos
{
	FILE *f;
        int n, nr;
        char nome[60];
        char morada[60], cc[60];
        int bi, est;
        if(!(f=fopen("c:\\cliente.txt","r")))
        {
                printf("Erro na Abertura de Leitura <Enter para Sair>");
                getch();
        exit(0);
        }
        for(n=0;n<NR;n++)
        {
                fscanf(f,"%d",&nr);
                if(nr != -1){  ///no caso de o valor do numero ser diferente de -1, valor estabelecido para o fim do ficheiro, 
                      x[n].numero = nr;
                      fscanf(f,"%s\n%s\n%d\n%s\n%d\n", &nome, &morada, &bi, &cc, &est);
                      strcpy(x[n].nome,nome);
                      strcpy(x[n].morada,morada);
                      x[n].bi = bi;
                      strcpy(x[n].cc,cc);
                      x[n].estado = est;
                      }
                      else 
                           break;
        }
        fclose(f);
      
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
			printf("\n\nNUMERO=?");scanf("%ld", x[n].numero);
            printf("\n\nNOME=?");scanf("%s", x[n].nome);
            printf("\n\nMORADA=?");scanf("%s", &x[n].morada);
            printf("\n\nBI=?");scanf("%d", &x[n].bi);
            printf("\n\nCC=?");scanf("%d", &x[n].cc);
            printf("\n\nESTADO=?");scanf("%d", &x[n].estado);
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

void gravarauto(automovel *x)
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
			fprintf(f,"%d\n%d\n%s\n%s\n%s\n%d\n%d\n%s\n%f\n%f\n%f\n%f\n", 
                &x[n].estado, &x[n].numero, x[n].marca, x[n].modelo, x[n].cor, &x[n].cilindrada, &x[n].ano_de_aquis, x[n].matric, &x[n].valor_dia, &x[n].combustivel, &x[n].Kms, &x[n].preco_de_aquis);
		}
	}
	fclose(f);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); getch();
}

void lerauto(automovel *x)
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
                fscanf(f,"%d\n%d\n%s\n%s\n%s\n%d\n%d\n%s\n%f\n%f\n%f\n%f\n", 
                &x[n].estado, &x[n].numero, x[n].marca, x[n].modelo, x[n].cor, &x[n].cilindrada, &x[n].ano_de_aquis, x[n].matric, &x[n].valor_dia, &x[n].combustivel, &x[n].Kms, &x[n].preco_de_aquis);
        }
        fclose(f);
     
}


void mostrarauto(automovel *x)
{
        int n;
        system ("cls");
        for(n=1;n<NR;n++)
        {
                if(x[n].estado!=0) /* Como todos os carros tem um numero o zero e um carro inexistente */
                
                {
                        printf("NUMERO=%d\nMARCA=%d\nMODELO=%s\nCOR=%s\nCILINDRADA=%d\nANO_DE_AQUIS=%d\nMATRIC=%s\nVALOR_DIA=%f\nCOMBUSTIVEL=%f\nKMS=%f\nPRECO_DE_AQUIS=%f\n\n",
                        x[n].numero, x[n].marca, x[n].modelo, x[n].cor, x[n].cilindrada, x[n].ano_de_aquis, x[n].matric, x[n].valor_dia, x[n].combustivel, x[n].Kms, x[n].preco_de_aquis);
                }
        }
        printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}


int inserirauto(automovel *x)
{
        int n;
        long int inser;
        system ("cls");
        printf("Qual o automovel que pretende inserir? ");
        scanf("%d",&inser);
        for(n=1;n<NR;n++)
        {
                if(x[n].estado!=1)
                {
                        x[n].numero=inser;
                        printf("\n\nESTADO=?");scanf("%d", x[n].estado);
                        printf("\n\nNUMERO=?");scanf("%d", x[n].numero);
                        printf("\n\nMARCA=?");scanf("%s", x[n].marca);
                        printf("\n\nMODELO=?");scanf("%s", x[n].modelo);
                        printf("\n\nCOR=?");scanf("%s", x[n].cor);
                        printf("\n\nCILINDRADA=?");scanf("%d", x[n].cilindrada);
                        printf("\n\nANO_DE_AQUIS=?");scanf("%d", x[n].ano_de_aquis);
                        printf("\n\nMATRIC=?");scanf("%s", x[n].matric);
                        printf("\n\nVALOR_DIA=?");scanf("%f", x[n].valor_dia);
                        printf("\n\nCOMBUSTIVEL=?");scanf("%f", x[n].combustivel);
                        printf("\n\nKMS=?");scanf("%f", x[n].Kms);
                        printf("\n\nPRECO_DE_AQUIS=?");scanf("%f", x[n].preco_de_aquis);
                        x[n].estado=1;
                        printf("\n\n\nRegisto Inserido <Enter para Continuar>");
                        getch();
                        return(1);
                }
        }
        printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}


int eliminarauto(automovel *x)
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
			printf("\n\nESTADO=?");scanf("%d", x[n].estado);
            printf("\n\nNUMERO=?");scanf("%d", x[n].numero);
            printf("\n\nMARCA=?");scanf("%s", x[n].marca);
            printf("\n\nMODELO=?");scanf("%s", x[n].modelo);
            printf("\n\nCOR=?");scanf("%s", x[n].cor);
            printf("\n\nCILINDRADA=?");scanf("%d", x[n].cilindrada);
            printf("\n\nANO_DE_AQUIS=?");scanf("%d", x[n].ano_de_aquis);
            printf("\n\nMATRIC=?");scanf("%s", x[n].matric);
            printf("\n\nVALOR_DIA=?");scanf("%f", x[n].valor_dia);
            printf("\n\nCOMBUSTIVEL=?");scanf("%f", x[n].combustivel);
            printf("\n\nKMS=?");scanf("%f", x[n].Kms);
            printf("\n\nPRECO_DE_AQUIS=?");scanf("%f", x[n].preco_de_aquis);
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



int alterarauto(automovel *x)
 {
        int n;
        long int inser;
        system ("cls");
        printf("Qual o automovel que pretende inserir? ");
        scanf("%ld",&inser);
        for(n=1;n<NR;n++)
        {
                if(x[n].estado!=1)
                {
                        x[n].numero=inser;
                        printf("\n\nESTADO=?");scanf("%d", x[n].estado);
                        printf("\n\nNUMERO=?");scanf("%d", x[n].numero);
                        printf("\n\nMARCA=?");scanf("%s", x[n].marca);
                        printf("\n\nMODELO=?");scanf("%s", x[n].modelo);
                        printf("\n\nCOR=?");scanf("%s", x[n].cor);
                        printf("\n\nCILINDRADA=?");scanf("%d", x[n].cilindrada);
                        printf("\n\nANO_DE_AQUIS=?");scanf("%d", x[n].ano_de_aquis);
                        printf("\n\nMATRIC=?");scanf("%s", x[n].matric);
                        printf("\n\nVALOR_DIA=?");scanf("%f", x[n].valor_dia);
                        printf("\n\nCOMBUSTIVEL=?");scanf("%f", x[n].combustivel);
                        printf("\n\nKMS=?");scanf("%f", x[n].Kms);
                        printf("\n\nPRECO_DE_AQUIS=?");scanf("%f", x[n].preco_de_aquis);
                        x[n].estado=1;
                        printf("\n\n\nRegisto Inserido <Enter para Continuar>");
                        getch();
                        return(1);
                }
        }
        printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}


int pesquisacliente(cliente *x)
{
        char confere;
        int n;
        long int procuracli;
        system("cls");
        printf("Qual a informacao do cliente que quer procurar? "); scanf("%ld",&procuracli);
        for(n=1;n<NR;n++)
        {
                if(x[n].numero==procuracli)
                {
                        printf("\n\nNUMERO=%ld\nNOME=%s\nMORADA=%s\nBI=%d\nCC=%d\nESTADO=%d\n\n",
                        &x[n].numero, &x[n].nome, &x[n].morada, &x[n].bi, &x[n].cc, &x[n].estado);
                       
                }
        }
      return(0);
}


int pesquisacarro(automovel *x)
{
        char confere;
        int n;
        long int proccarro;
        system("cls");
        printf("Qual o automovel que quer procurar? "); scanf("%ld",&proccarro);
        for(n=1;n<NR;n++)
        {
                if(x[n].numero==proccarro)
                {
                        printf("\n\nNUMERO=%d\nMARCA=%c\nMODELO=&c\nCOR=%c\nCILINDRADA=%d\nANO_DE_AQUIS=%d\nMATRIC=%c\nVALOR_DIA=%c\nCOMBUSTIVEL=%f\nKMS=%f\nPRECO_DE_AQUIS=%f\n\n",
                        x[n].numero,x[n].marca,x[n].modelo,x[n].cor,x[n].cilindrada,x[n].ano_de_aquis,x[n].matric,x[n].valor_dia,x[n].combustivel,x[n].Kms,x[n].preco_de_aquis);
                       
                }
        }
        return(0);
}

void lerrent(aluguer *x)  /// função para ler aluguer
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
		fscanf(f,"%d\n%d\n%ld\n%c\n%c\n%c\n%d\n%d\n%d", &x[n].numero, &x[n].estado, &x[n].ident_auto,
					      &x[n].ident_cliente, &x[n].data_inicio, &x[n].data_fim, &x[n].Km_percorridos, &x[n].preco_final, &x[n].registo_acidentes);
	}
	fclose(f);

}

void mostrarrent(aluguer *x) ///função que mostra o aluguer
{
        int n;
        system ("cls");
        for(n=1;n<NR;n++)
        {
                if(x[n].estado!=0) /// Como todos os carros tem um numero o zero e um carro inexistente
                
                {
                        printf("ESTADO=%d\nIDENT_AUTO=%ld\nIDENT_CLIENTE=&s\nDATA_INICIO=%s\nDATA_FIM=%s\nKM_PERCORRIDOS=%d\nPRECO_FINAL=%d\nREGISTO_ACIDENTES=%d\n\n",
                        x[n].estado, x[n].ident_auto, x[n].ident_cliente, x[n].data_inicio, x[n].data_fim, x[n].Km_percorridos, x[n].preco_final, x[n].registo_acidentes);
                }
        }
        printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}


int inserirrent(aluguer *x)  ///função que define a inserção do aluguer
{
        int n;
        long int inser;
        system ("cls");
        
        for(n=1;n<NR;n++)   ///ciclo for precore o array x da posição 0 ate NR o valor maximo do array
        {
                if(x[n].estado!=1)
                {
                        printf("\n\nESTADO=?");scanf("%d",x[n].numero);   ///envia uma mensagem ao utilizador que vai ler um valor
                        printf("\n\nESTADO=?");scanf("%d", x[n].estado);
                        printf("\n\nIDENT_AUTO=?");scanf("%ld", x[n].ident_auto);
                        printf("\n\nIDENT_CLIENTE=?");scanf("%s", x[n].ident_cliente);
                        printf("\n\nDATA_INICIO=?");scanf("%s", x[n].data_inicio);
                        printf("\n\nDATA_FIM=?");scanf("%s", x[n].data_fim);
                        printf("\n\nKM_PERCORRIDOS=?");scanf("%d", x[n].Km_percorridos);
                        printf("\n\nPRECO_FINAL=?");scanf("%d", x[n].preco_final);
                        printf("\n\nREGISTO_ACIDENTES=?");scanf("%d", x[n].registo_acidentes);
                        x[n].estado=1;
                        printf("\n\n\nRegisto Inserido <Enter para Continuar>");
                        getch();
                        return(1);
                }
        }
        printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);  ///mensagem de erro, getch faz uma pausa para o utilizador ver a mensagem, return retorna o valor da função
}



int main(void) /// Inicio do programa, inicio de declaração de variaveis inteiras 
{
        char op;
        int menu_inicial; /// inicio de declaração de variaveis inteiras
        int menu_cliente;
        int menu_auto;
        int menu_aluguer;
        int menu_pesquisas;
        int menu_estatisticas;
        int n;  /// fim de declaração de variaveis inteiras
        cliente client[NR]; /// Criar um array Client do tipo cliente
        automovel car[NR];        ///Criar um array car do tipo auto
        aluguer rent[NR]; /// Cria um array rent do tipo aluguer
        for(n=0;n<NR;n++)
        {        
                car[n].estado=0;   /// limpa todo o Array de registos de carros
                client[n].estado=0;   /// limpa todo o Array de registos de clientes
                rent[n].estado=0;    /// Limpar todo o Array de registos de aluguer
        }
  do
  {
	system ("cls");
   printf ("menu inicial\n");
   printf ("1- Cliente\n");
   printf ("2- Automoveis\n");
   printf ("3- Aluguer\n");
   printf ("4- Pesquisas\n");
   printf ("5- Estatisticas\n"); 
   printf ("6- Terminar / Sair\n"); 
   scanf ("%d",&menu_inicial);
                   while (menu_inicial==1)
                   {
                           system ("cls");
                           printf ("menu cliente\n");
                           printf ("1- listar clientes\n");
                           printf ("2- Novo cliente\n");
                           printf ("3- Alterar cliente\n");
                           printf ("4- Apagar cliente\n");
                           printf ("5- Voltar ao menu inicial\n"); 
                           scanf ("%d",&menu_cliente);
                           lercliente(client);  /// chamar a fun??o lercliente para copiar todo o conteudo do ficheiro de clientes para o array client
                                   while (menu_cliente==1)
                                   {
                                           mostrarcliente(client);    /// chama a fun??o mostrarcliente que envia psrs o ecran a listagem de todos os clientes
                                           menu_cliente==0;           
                                   }
                                   while (menu_cliente==2)
                                   {
                                           inserircliente(client); 
                                           menu_cliente==0;
                                   }
                                   while (menu_cliente==3)
                                   {
                                         alterarcliente(client); 
                                         menu_cliente==0;
                                   }
                                   while (menu_cliente==4)
                                   {
                                           eliminarcliente(client);
                                           menu_cliente==0;
                                   }
                                   if (menu_cliente==5) 
                                   {
                                           menu_inicial==0;
                                           menu_cliente==0;
                                           gravarcliente(client); break;
                                   }
   
                   }        
                   while (menu_inicial==2)
                   {        
                           system ("cls");
                           printf ("menu do automovel\n");
                           printf ("1- listar automovel\n");
                           printf ("2- Novo automovel\n");
                           printf ("3- Alterar automovel\n");
                           printf ("4- Apagar automovel\n");
                           printf ("5- Voltar ao menu inicial\n"); 
                           scanf ("%d",&menu_auto);
                           lerauto(car); break;
                                   while (menu_auto==1)
                                   {
                                            mostrarauto(car); break;
                                            menu_auto==0;
                                   }
                                   while (menu_auto==2)
                                   {
                                           inserirauto(car); break;
                                           menu_auto==0;
                                   }
                                   while (menu_auto==3)
                                   {
                                         alterarauto(car); break;
                                         menu_auto==0;
                                   }
                                   while (menu_auto==4)
                                   {
                                           eliminarauto(car); break;
                                           menu_auto==0;
                                   }
                                   if (menu_auto==5) 
                                   {
                                           menu_inicial==0;
                                           menu_auto==0;
                                           gravarauto(car); break;
                                   }        
                }        
                while (menu_inicial==3)
                {        
                        system ("cls");
                        printf ("menu do aluguer\n");
                           printf ("1- listar aluguer\n");
                           printf ("2- novo aluguer\n");
                           printf ("3- Voltar ao menu inicial\n");
                           scanf ("%d",&menu_aluguer);
                           lerrent(rent); break;
                                   while (menu_aluguer==1)
                                   {
                                           mostrarrent(rent); break;
                                           menu_auto==0;
                                   }
                                   while (menu_aluguer==2)
                                   {
                                           inserirrent(rent); break;
                                           menu_auto==0;
                                   }
                                   if (menu_aluguer==3)
                                   {
                                           menu_inicial==0;
                                           menu_aluguer==0;
                                   }
                }
                while (menu_inicial==4)
                   {
                           system ("cls");
                           printf ("menu das pesquisas\n");
                           printf ("1- pesquisa por cliente\n");
                           printf ("2- pesquisa por automovel\n");
                           printf ("3- pesquisa do aluguer por data\n");
                           printf ("4- pesquisa do aluguer por carro\n");
                           printf ("5- pesquisa do aluguer por cliente\n");
                           printf ("6- Voltar ao menu inicial\n");
                           scanf ("%d",&menu_pesquisas);
                                   while (menu_pesquisas==1)
                                   {
                                         pesquisacliente(client); break;
                                         menu_pesquisas==0;
                                   }
                                   while (menu_pesquisas==2)
                                   {
                                         pesquisacarro(car); break;
                                         menu_pesquisas==0;
                                   }
                                   /*while (menu_pesquisas==3)
                                   {
                                         pesquisarentdata(rent); break;
                                         menu_pesquisas==0;
                                   }
                                   while (menu_pesquisas==4)
                                   {
                                         pesquisarentcarro(rent); break;
                                         menu_pesquisas==0;
                                   }
                                   while (menu_pesquisas==5)
                                   {
                                         pesquisarentcliente(rent); break;
                                         menu_pesquisas==0;
                                   }*/
                                   if (menu_pesquisas==6)
                                   {
                                           menu_inicial==0;
                                           menu_pesquisas==0;
                                   }
                   }
                   while (menu_inicial==5)  ///rotina de apresentação do menu estatisticas
                   {
                           system ("cls");  ///Limpa o ecra e apresenta o menu estatisticas                                       
                           printf  ("menu das estatisticas\n");
                           printf  ("1- veiculo com mais alugueres\n");
                           printf  ("2- veiculo com mais Km's\n");
                           printf  ("3- veiculo com maior numero de acidentes\n");
                           printf  ("4- media das distancias percorridas\n");
                           printf  ("5- maior viagem em termos de distancias\n");
                           printf  ("6- Numero medio de dias de aluguer por veiculo\n");
                           printf  ("7- Numero de dias que cada veiculo esteve parado\n");
                           printf  ("8- Cliente que fez mais alugueres\n");
                           printf  ("9- Cliente que percorreu maior distancia\n"); 
                           printf  ("10- Cliente com maior numero de acidentes\n");
                           printf  ("11- Voltar ao menu principal\n");  /// fim da apresentação do menu
                           scanf ("%d",&menu_estatisticas); ///le a variavel do menu de estatisticas
                                  /* while (menu_estatisticas=1)
                                   while (menu_estatisticas=2)
                                   while (menu_estatisticas=3)
                                   while (menu_estatisticas=4)
                                   while (menu_estatisticas=5)
                                   while (menu_estatisticas=6)
                                   while (menu_estatisticas=7)
                                   while (menu_estatisticas=8)
                                   while (menu_estatisticas=9)
                                   while (menu_estatisticas=10)*/
                                   if (menu_estatisticas=11)    ///compara o valor do menu estatisticas a 11
                                           {
                                                   menu_inicial==0;  ///sai da rotina do menu inicial
                                                   menu_estatisticas==0; ///sai da rotina do menu de estasticas
                                           }
                   }
   }
   while (menu_inicial!=6); ///Variavel de controlo de fim de programa
  { 
  exit(0); ///Fim de programa, encerra ou termina o programa
}
}

