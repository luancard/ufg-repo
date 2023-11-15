#include <stdio.h>

#define STR_LEN 100
#define MAXTAM 500


typedef struct TipoPessoa {

  char Nome[STR_LEN];
  char Genero[STR_LEN];
  char Raca[STR_LEN];
  char Estado_Civil[STR_LEN];
  char Escolaridade[STR_LEN];
  char Cargo[STR_LEN];

  float Salario;

  int Birthday_D;
  int Birthday_M;
  int Birthday_Y;

  unsigned long long int Phone_Num;

  
  unsigned long long int W_CODE;
  

} TipoPessoa;
/* ------------------------------------------------------- A L O C A Ç Ã O   E S T Á T I C A ------------------------------------------------------- */

typedef int Apontador;

typedef struct Data_Base{

  TipoPessoa Pessoa[MAXTAM];
  Apontador First, Last;

}Data_Base;


/* ------------------------------------------------------- A L O C A Ç Ã O   D I N Â M I C A ------------------------------------------------------- */

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula{

  TipoPessoa Pessoa;
  TipoApontador Next;

}TipoCelula;

typedef struct DataBase{

  TipoApontador DBFirst, DBLast;

}DataBase;

/* ********************************************************************* FUNÇÕES ********************************************************************* */

void startListDB(DataBase *Lista);                                     //Inicializa a lista alocada dinamicamente.

void insereFunDB(DataBase *Lista, TipoPessoa Pessoa);                  //Insere um funcionário na lista dinâmica.
void insereFunDB_NOPRINT(DataBase *Lista, TipoPessoa Pessoa);          //Insere um funcionário na lista dinâmica SEM DAR PRINT.

void VaziaDB(DataBase Lista);                                           //Verifica a quantidade de pessoas cadastradas na lista. 0 = Vazia.

int Empty(DataBase *Lista);                                            //Verifica se a lista está vazia ou não.

void removeFunDB(unsigned long long int ID, DataBase *Lista);          //Remove um funcionário da lista.

void Retira(DataBase *Lista);                                          //Remove funcionários da lista de forma sequencial.

void insereNewFunDB(DataBase *Lista);                                  //Função para preencher os dados de um funcionário e inseri-lo no Banco de Dados.

void selectionSortDB_Alfabeto(DataBase *Lista, Data_Base *Static_List);//Realiza a ordenação por ordem alfabética.

void insertionSortDB(DataBase *Lista, Data_Base *Static_List);         //Realiza a ordenação com base no código de identificação do funcionário com o algoritmo Insertion Sort

TipoPessoa buscaOrdenadaDB(char *Nome, DataBase *Lista);               //Utiliza o algoritmo de busca ordenada que, a partir do nome retorna um apontador para a posição dele na lista.

unsigned long long int buscaOrdenada_DB(DataBase *Lista, char *Nome);  //Utiliza o algoritmo de busca ordenada para, a partir do Nome retornar o código de identificação.

void imprimeListaDB(DataBase *Lista, Data_Base *Static_List);          //Imprime a lista de funcionários com as informações mais importantes(Nome, cargo, telefone e ID), para ver a ficha completa tem que puxar os dados específicos do funcionário.

void Dinamic_2_Static(DataBase *Lista, Data_Base *Static_List);        //Transfere a lista alocada dinamicamente para uma alocada estaticamente.

void Static_2_Dinamic(Data_Base *Static_List, DataBase*Lista);         //Transfere a lista alocada estaticamente para uma alocada dinamicamente.

void access_Fun(DataBase *Lista, char *Nome);                          //Acessa os dados de um funcionário específico.

void startList(Data_Base *Lista);                                       //Inicializa a lista estática.

int Vazia(Data_Base Lista);                                             //Verifica a quantidade de pessoas cadastradas na lista estática. 0 = Vazia.

void insereFun(Data_Base *Lista, TipoPessoa Pessoa);                    //Insere um novo funcionário na lista estática.

void alteraDados(unsigned long long int ID, DataBase *Lista, Data_Base *Static_List);          //Altera os dados de um funcionário específico.

void selectionSort_Alfabeto(Data_Base *Lista);                          //Realiza a ordenação por ordem alfabética por meio do algoritmo Selection Sort.

void insertionSort(Data_Base *Lista);                                   //Realiza a ordenação por meio do algoritmo Insertion Sort.

unsigned long long int buscaOrdenada(Data_Base *Lista, char *Nome);     //Utiliza o algoritmo de busca ordenada que, a partir do nome do funcionário retorna seu código.

int buscaBinaria(Data_Base *Lista, unsigned long long int ID);          //Utiliza o algoritmo de busca binária que, a partir do código do funcionário retorna a posição na lista. ::PRECISA ESTAR ORDENADO::

void end_DB(DataBase *Lista, int n); //Encerra o programa, reescrevendo o arquivo de dados.

/* ********************************************************************* FUNÇÕES ********************************************************************* */