#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NR 101
typedef struct
{
        long int numero;
        char nome[60];                /* Palavras ligadas. Ex: Carlos_Marinho */                
        char morada[60];
        int BI_CC;
        int carta_de_conducao;                /* 0=livre        1=ocupado        */
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
        printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}

void mostrarauto(automovel *x)
{
        int n;
        system ("cls");
        for(n=1;n<NR;n++)
        {
                if(x[n].estado!=0) /* Como todos os carros tem um numero o zero e um carro inexistente */
                
                {
                        printf("NUMERO=%d\nMARCA=%d\nMODELO=&s\nCOR=%s\nCILINDRADA=%d\nANO_DE_AQUIS=%d\nMATRIC=%s\nVALOR_DIA=%f\nCOMBUSTIVEL=%f\nKMS=%f\nPRECO_DE_AQUIS=%f\n\n",
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
                        printf("\n\nBI_CC=?");scanf("%d", &x[n].BI_CC);
                        printf("\n\nCARTA_DE_CONDUCAO=?");scanf("%d", &x[n].carta_de_conducao);
                        printf("\n\nESTADO=?");scanf("%d", &x[n].estado);
                        x[n].estado=1;
                        printf("\n\n\nRegisto Alterar <Enter para Continuar>");
                        getch();
                        return(1);
                }
        }
        printf("ERRO! Nao foi possivel Alterar"); getch(); return(0);
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
                        printf("\n\nNUMERO=%ld\nNOME=%s\nMORADA=%s\nBI_CC=%d\nCARTA_DE_CONDUCAO=%d\nESTADO=%d\n\n",
                        &x[n].numero, &x[n].nome, &x[n].morada, &x[n].BI_CC, &x[n].carta_de_conducao, &x[n].estado);
                       
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
        printf("Qual o Numero do aluno que quer procurar? "); scanf("%ld",&proccarro);
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

void lercliente(cliente *x)
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
                fscanf(f,"%ld\n%s\n%s\n%d\n%d\n%d\n", 
                &x[n].numero, &x[n].nome, &x[n].morada, &x[n].BI_CC, &x[n].carta_de_conducao, &x[n].estado);
        }
        fclose(f);
        printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}

void mostrarrent(aluguer *x)
{
        int n;
        system ("cls");
        for(n=1;n<NR;n++)
        {
                if(x[n].estado!=0) /* Como todos os carros tem um numero o zero e um carro inexistente */
                
                {
                        printf("ESTADO=%d\nIDENT_AUTO=%ld\nIDENT_CLIENTE=&s\nDATA_INICIO=%s\nDATA_FIM=%s\nKM_PERCORRIDOS=%d\nPRECO_FINAL=%d\nREGISTO_ACIDENTES=%d\n\n",
                        x[n].estado, x[n].ident_auto, x[n].ident_cliente, x[n].data_inicio, x[n].data_fim, x[n].Km_percorridos, x[n].preco_final, x[n].registo_acidentes);
                }
        }
        printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

int inserirrent(aluguer *x)
{
        int n;
        long int inser;
        system ("cls");
        
        for(n=1;n<NR;n++)
        {
                if(x[n].estado!=1)
                {
                        printf("\n\nESTADO=?");scanf("%d",x[n].numero);
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
        printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}

int main(void) /* Inicio do programa */ 
{
        char op;
        int menu_inicial;
        int menu_cliente;
        int menu_auto;
        int menu_aluguer;
        int menu_pesquisas;
        int menu_estatisticas;
        int n;
        cliente client[NR]; /* Criar um array Client do tipo cliente */
        automovel car[NR];        /*Criar um array car do tipo auto */
        aluguer rent[NR]; /* Criar um array rent do tipo aluguer */
        for(n=0;n<NR;n++)
        {        
                car[n].estado=0;   /* limpa todo o Array de registos de carros*/
                client[n].estado=0;   /* limpa todo o Array de registos de clientes */
                rent[n].estado=0;    /* Limpar todo o Array de registos de aluguer */
        }
  do
  {
	system ("cls");
   printf ("menu inicial");
   printf ("1- Cliente");
   printf ("2- Autom?veis");
   printf ("3? Aluguer");
   printf ("4- Pesquisas");
   printf ("5- Estatist?cas"); 
   printf ("6- Terminar / Sair"); 
   scanf ("%d",&menu_inicial);
                   while (menu_inicial=1)
                   {
                           system ("cls");
                           printf ("menu cliente");
                           printf ("1- listar clientes");
                           printf ("2- Novo cliente");
                           printf ("3? Alterar cliente");
                           printf ("4- Apagar cliente");
                           printf ("5- Voltar ao menu inicial"); 
                           scanf ("%d",&menu_cliente);
                           lercliente(client); break; /* chamar a fun??o lercliente para copiar todo o conteudo do ficheiro de clientes para o array client */
                                   while (menu_cliente=1)
                                   {
                                           mostrarcliente(client); break;   /* chamar a fun??o mostrarcliente que envia psrs o ecran a listagem de todos os clientes */
                                           menu_cliente==0;           
                                   }
                                   while (menu_cliente=2)
                                   {
                                           inserircliente(client); break;
                                           menu_cliente==0;
                                   }
                                   while (menu_cliente=3)
                                   {
                                         alteracliente(client); break;
                                         menu_cliente==0;
                                   }
                                   while (menu_cliente=4)
                                   {
                                           eliminarcliente(client); break;
                                           menu_cliente==0;
                                   }
                                   while (menu_cliente=5) 
                                   {
                                           menu_inicial==0;
                                           menu_cliente==0;
                                           gravarcliente(client); break;
                                   }
   
                   }        
                   while (menu_inicial=2)
                   {        
                           system ("cls");
                           printf ("menu do automovel");
                           printf ("1- listar automovel");
                           printf ("2- Novo automovel");
                           printf ("3- Alterar automovel");
                           printf ("4- Apagar automovel");
                           printf ("5- Voltar ao menu inicial"); 
                           scanf ("%d",&menu_auto);
                           lerauto(car); break;
                                   while (menu_auto=1)
                                   {
                                            mostrarauto(car); break;
                                            menu_auto==0;
                                   }
                                   while (menu_auto=2)
                                   {
                                           inserirauto(car); break;
                                           menu_auto==0;
                                   }
                                   while (menu_auto=3)
                                   {
                                         alterarauto(car); break;
                                         menu_auto==0;
                                   }
                                   while (menu_auto=4)
                                   {
                                           eliminarauto(car); break;
                                           menu_auto==0;
                                   }
                                   while (menu_auto=5) 
                                   {
                                           menu_inicial==0;
                                           gravarauto(car); break;
                                   }        
                }        
                while (menu_inicial=3)
                {        
                        system ("cls");
                        printf ("menu do aluguer");
                           printf ("1- listar aluguer");
                           printf ("2- novo aluguer");
                           printf ("3- Voltar ao menu inicial");
                           scanf ("%d",&menu_aluguer);
                                   while (menu_aluguer=1)
                                   {
                                           mostrarrent(rent); break;
                                           menu_auto==0;
                                   }
                                   while (menu_aluguer=2)
                                   {
                                           inserirrent(rent); break;
                                           menu_auto==0;
                                   }
                                   while (menu_aluguer=3)
                                   {
                                           menu_inicial==0;
                                           menu_auto==0;
                                   }
                }
                while (menu_inicial=4)
                   {
                           system ("cls");
                           printf ("menu das pesquisas");
                           printf ("1- pesquisa por cliente");
                           printf ("2- pesquisa por automovel");
                           printf ("3- pesquisa do aluguer por data");
                           printf ("4- pesquisa do aluguer por carro");
                           printf ("5- pesquisa do aluguer por cliente");
                           printf ("6- Voltar ao menu inicial");
                           scanf ("%d",&menu_pesquisas);
                                   while (menu_pesquisas=1)
                                   {
                                         pesquisacliente(client); break;
                                         menu_pesquisas==0;
                                   }
                                   while (menu_pesquisas=2)
                                   {
                                         pesquisacarro(car); break;
                                         menu_pesquisas==0;
                                   }
                                   while (menu_pesquisas=3)
                                   {
                                         pesquisarentdata(rent); break;
                                         menu_pesquisas==0;
                                   }
                                   while (menu_pesquisas=4)
                                   {
                                         pesquisarentcarro(rent); break;
                                         menu_pesquisas==0;
                                   }
                                   while (menu_pesquisas=5)
                                   {
                                         pesquisarentcliente(rent); break;
                                         menu_pesquisas==0;
                                   }
                                   while (menu_pesquisas=6)
                                   {
                                           menu_inicial==0;
                                   }
                   }
                   while (menu_inicial=5)
                   {
                           system ("cls");
                           printf  ("menu das estat?sticas");
                           printf  ("1- ve?culo com mais alugueres");
                           printf  ("2- ve?culo com mais Km's");
                           printf  ("3- ve?culo com maior n?mero de acidentes");
                           printf  ("4- m?dia das distancias percorridas");
                           printf  ("5- maior viagem em termos de distancias");
                           printf  ("6- N?mero m?dio de dias de aluguer por ve?culo");
                           printf  ("7- N?mero de dias que cada ve?culo esteve parado");
                           printf  ("8- Cliente que fez mais alugueres");
                           printf  ("9- Cliente que percorreu maior dist?ncia"); 
                           printf  ("10- Cliente com maior n?mero de acidentes");
                           printf  ("11- Voltar ao menu principal");
                           scanf ("%d",&menu_estatisticas);
                                  /* while (menu_estatisticas=1)
                                   while (menu_estatisticas=2)
                                   while (menu_estatisticas=3)
                                   while (menu_estatisticas=4)
                                   while (menu_estatisticas=5)
                                   while (menu_estatisticas=6)
                                   while (menu_estatisticas=7)
                                   while (menu_estatisticas=8)
                                   while (menu_estatisticas=9)
                                   while (menu_estatisticas=10)
                                   while (menu_estatisticas=11) */
                                           {
                                                   menu_inicial==0;
                                           }
                   }
  } while (menu_inicial=6); 
  exit(0);
}
