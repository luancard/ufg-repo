#include "rh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define START 0
#define MAXTAM 500

void startList(Data_Base *Lista){

  Lista->First = START;
  Lista->Last = Lista->First;
  
}

int Vazia(Data_Base Lista){

  int cont = 0;
  
  if(Lista.First == Lista.Last){
    //printf("Lista estática Vazia!\n");
    return 0;
  } else {
    int n = Lista.First;
    int f = Lista.Last;
    for(int i = n; i < f; i++){
      cont++;
    }
    printf("%d Funcionários Cadastrados na lista estática!\n", cont);
    return cont;
  }
  
}

void insereFun(Data_Base *Lista, TipoPessoa Pessoa){

  int Aux = Lista->Last;

  if(Aux>=MAXTAM){
    printf("Lista Cheia!\n");
    return;
  } else {
    Lista->Pessoa[Aux] = Pessoa;
    Lista->Last++;
  }
  
}

unsigned long long int buscaOrdenada(Data_Base *Lista, char *Nome){

  int comp;
  
  for(int i = Lista->First; i < Lista->Last; i++){
    comp = strcmp(Lista->Pessoa[i].Nome, Nome);
    if(comp == 0){
      //printf("Funcionário encontrado!\n");
      return Lista->Pessoa[i].W_CODE;
    }
  }

  //printf("Funcionário não encontrado!\n");
  return -1;
  
}

int buscaBinaria(Data_Base *Lista, unsigned long long int ID){

  insertionSort(Lista);
  int inf = 0;
  int sup = Lista->Last-1;
  int meio;
    while (inf <= sup)
    {
      meio = (inf + sup)/2;
      if (ID == Lista->Pessoa[meio].W_CODE){
        printf("Funcionário encontrado!\n");
        return meio;
      }
      if (ID < Lista->Pessoa[meio].W_CODE){
        sup = meio-1;
      }else{
        inf = meio+1;
      }
    }
    printf("Funcionário não encontrado!\n");
    return -1;
  
}

void insertionSort(Data_Base *Lista){

  int i, j;
  TipoPessoa Aux;

  for(i = Lista->First+1; i < Lista->Last; i++){
    for(j = i; j >= Lista->First; j--){
      if(Lista->Pessoa[j].W_CODE < Lista->Pessoa[j-1].W_CODE){
        Aux = Lista->Pessoa[j-1];
        Lista->Pessoa[j-1] = Lista->Pessoa[j];
        Lista->Pessoa[j] = Aux;
      } else {
        break;
      }
    }
  }
  
}

void selectionSort_Alfabeto(Data_Base *Lista){

  int i, j;
  int x = 0;
  TipoPessoa Aux;

  for(i = 0; i < Lista->Last-1; i++){
    for(j = i+1; j < Lista->Last; j++){

      while(Lista->Pessoa[j].Nome[x]==Lista->Pessoa[i].Nome[x]){
        x++;
      }
      
      if(Lista->Pessoa[j].Nome[x] < Lista->Pessoa[i].Nome[x]){
        Aux = Lista->Pessoa[j];
        Lista->Pessoa[j] = Lista->Pessoa[i];
        Lista->Pessoa[i] = Aux;
      }
      x = 0;
    }
  }
}

void access_Fun(DataBase *Lista, char *Nome){

  TipoPessoa Aux = buscaOrdenadaDB(Nome, Lista);
  if(Aux.Nome[1]=='0') return;

  printf("Nome: %s\n", Aux.Nome);
  printf("Genero: %s\n", Aux.Genero);
  printf("Raça: %s\n", Aux.Raca);
  printf("Estado Civil: %s\n", Aux.Estado_Civil);
  printf("Escolaridade: %s\n", Aux.Escolaridade);
  printf("Cargo: %s\n", Aux.Cargo);
  printf("Salário: R$%.2f\n", Aux.Salario);
  printf("Data de nascimento: %d/%d/%d\n", Aux.Birthday_D, Aux.Birthday_M, Aux.Birthday_Y);
  printf("Telefone: %llu\n", Aux.Phone_Num);
  printf("Código de Identificação: %llu\n", Aux.W_CODE);
  printf("\n\n");
  
}

void alteraDados(unsigned long long int ID, DataBase *Lista, Data_Base *Static_List){

  Dinamic_2_Static(Lista, Static_List);
  
  int pos = buscaBinaria(Static_List, ID);
  if(pos == -1) return;

  char teste[64];
  int str_len;
  int boo = 0;

  printf("Qual informação deseja alterar?\n");
  printf("(0)CANCELA \n");
  printf("(1)Nome \n");
  printf("(2)Gênero \n");
  printf("(3)Raça \n");
  printf("(4)Estado Civil \n");
  printf("(5)Escolaridade \n");
  printf("(6)Cargo \n");
  printf("(7)Salário \n");
  printf("(8)Data de Nascimento \n");
  printf("(9)Telefone \n");
  int esc;
  scanf("%d%*c", &esc);
    
    switch(esc){
  
      case 1:
        printf("Digite novamente o nome do funcionário: ");
        scanf("%[^\n]%*c", Static_List->Pessoa[pos].Nome);
      break;
  
      case 2:
        printf("Digite novamente o gênero: ");
        scanf("%[^\n]%*c", Static_List->Pessoa[pos].Genero);
      break;
  
      case 3:
        printf("Digite novamente a raça: ");
        scanf("%[^\n]%*c", Static_List->Pessoa[pos].Raca);
      break;
  
      case 4:
        printf("Digite novamente o estado Civil: ");
        scanf("%[^\n]%*c", Static_List->Pessoa[pos].Estado_Civil);
      break;
  
      case 5:
        printf("Digite novamente a escolaridade: ");
        scanf("%[^\n]%*c", Static_List->Pessoa[pos].Escolaridade);
      break;
  
      case 6:
        printf("Digite novamente o cargo: ");
        scanf("%[^\n]%*c", Static_List->Pessoa[pos].Cargo);
      break;
  
      case 7:
        printf("Digite novamente o salário: ");
        scanf("%[^\n]%*c", teste);
        str_len = strlen(teste);
          for(int i = 0; i < str_len; i++){
            if(!isdigit(teste[i])){
              while(boo == 0){
                printf("Digite um VALOR NUMÉRICO VÁLIDO para o Salário: ");
                scanf("%[^\n]%*c", teste);
                str_len = strlen(teste);
                for(int i = 0; i < str_len; i++){
                  if(!isdigit(teste[i])){
                    break;
                  } else {
                    boo = 1;
                  }
                }
              }
            }
          }
        Static_List->Pessoa[pos].Salario = (float)atof(teste);
      break;
  
      case 8:
        printf("Digite novamente a data de nascimento(Dia, Mês e Ano): ");
        scanf("%d %d %d%*c", &(Static_List->Pessoa[pos].Birthday_D), &(Static_List->Pessoa[pos].Birthday_M), &(Static_List->Pessoa[pos].Birthday_Y));
      break;
  
      case 9:
        printf("Digite novamente o telefone: ");
        scanf("%llu%*c", &(Static_List->Pessoa[pos].Phone_Num));
      break;
  
      default: printf("Escolha inválida!\n");
      
    }
  Static_2_Dinamic(Static_List, Lista);
}

/* ---------------------------------------------------------- A L O C A Ç Ã O   D I N Â M I C A ---------------------------------------------------------- */

void startListDB(DataBase *Lista){

  Lista->DBFirst = NULL;
  Lista->DBLast = Lista->DBFirst;
  
}

void insereFunDB(DataBase *Lista, TipoPessoa Pessoa){

  TipoApontador New = (TipoApontador) malloc(sizeof(TipoCelula));
  New->Pessoa = Pessoa;
  New->Next = NULL;
  if(Lista->DBFirst == NULL){
    Lista->DBFirst = New;
  } else {
    Lista->DBLast->Next = New;
  }

  Lista->DBLast = New;

  printf("Funcionário de código %llu adicionado!\n", Pessoa.W_CODE);
  
}

void insereFunDB_NOPRINT(DataBase *Lista, TipoPessoa Pessoa){

  TipoApontador New = (TipoApontador) malloc(sizeof(TipoCelula));
  New->Pessoa = Pessoa;
  New->Next = NULL;
  if(Lista->DBFirst == NULL){
    Lista->DBFirst = New;
  } else {
    Lista->DBLast->Next = New;
  }

  Lista->DBLast = New;
  
}

void insereNewFunDB(DataBase *Lista){

  TipoPessoa pessoa;
  char teste[64];
  int str_len;
  int boo = 0;

  srand( (unsigned)time(NULL) );
  
  printf("\n");
  printf("Digite o nome do funcionário: ");
  scanf("%[^\n]%*c", pessoa.Nome);
  printf("Gênero: ");
  scanf("%[^\n]%*c", pessoa.Genero);
  printf("Raça: ");
  scanf("%[^\n]%*c", pessoa.Raca);
  printf("Estado Civil: ");
  scanf("%[^\n]%*c", pessoa.Estado_Civil);
  printf("Escolaridade: ");
  scanf("%[^\n]%*c", pessoa.Escolaridade);
  printf("Cargo: ");
  scanf("%[^\n]%*c", pessoa.Cargo);
  printf("Salário: ");
  scanf("%[^\n]%*c", teste);
  str_len = strlen(teste);
    for(int i = 0; i < str_len; i++){
      if(!isdigit(teste[i])){
        while(boo == 0){
          printf("Digite um VALOR NUMÉRICO VÁLIDO para o Salário: ");
          scanf("%[^\n]%*c", teste);
          str_len = strlen(teste);
          for(int i = 0; i < str_len; i++){
            if(!isdigit(teste[i])){
              break;
            } else {
              boo = 1;
            }
          }
        }
      }
    }
  pessoa.Salario = (float)atof(teste);
  printf("Data de nascimento(dd mm yyyy): ");
  scanf("%d %d %d%*c", &(pessoa.Birthday_D), &(pessoa.Birthday_M), &(pessoa.Birthday_Y));
  printf("Telefone: ");
  scanf("%llu%*c", &(pessoa.Phone_Num));

  pessoa.W_CODE = (unsigned long long int)rand() % 999999999999;

  insereFunDB(Lista, pessoa);
  
}

void VaziaDB(DataBase Lista){

  if(Lista.DBFirst==NULL){
    printf("O Banco de Dados está vazio!\n");
  } else{
    int cont = 0;
    TipoApontador Aux;
    Aux = Lista.DBFirst;
    while(Aux != NULL){
      cont++;
      Aux = Aux->Next;
    }
    printf("%d informações cadastradas no Banco de Dados!\n", cont);
    
  }
  
}

int Empty(DataBase *Lista){
  if(Lista->DBFirst==NULL){
    //printf("Lista encadeada vazia!");
    return 1;
  } else return 0;
}

void removeFunDB(unsigned long long int ID, DataBase *Lista){

  TipoApontador Out;
  TipoApontador Aux;
  Out = Lista->DBFirst;
  while(Out != NULL){

    if(ID == Out->Pessoa.W_CODE) break;
    Aux = Out;
    Out = Out->Next;
    
  }

  Aux->Next = Out->Next;
  printf("\n");
  printf("Funcionário de identificação %llu removido do Banco de Dados!\n", ID);
  if(Lista->DBFirst == NULL){
    Lista->DBLast = NULL;
  }
  free(Out);
}

void Retira(DataBase *Lista){

  TipoApontador q;
  if (Empty(Lista)==1) 
  { 
    printf("\n");
    printf("Banco de Dados vazio!\n");
    return; 
  }
  q = Lista->DBFirst;
  Lista->DBFirst = Lista->DBFirst->Next;
  free(q);
  if (Lista->DBFirst==NULL){
    Lista->DBLast=NULL;
  }
  
}

TipoPessoa buscaOrdenadaDB(char *Nome, DataBase *Lista){

  TipoApontador Aux = Lista->DBFirst;
  TipoPessoa NULL1;
  NULL1.Nome[1] = '0';

  while(Aux != NULL){

    int COMP = strcmp(Nome, Aux->Pessoa.Nome);
    if(COMP==0){
      printf("Funcionário encontrado!\n\n");
      return Aux->Pessoa;
    }
    
    Aux = Aux->Next;
  }
  printf("Funcionário não encontrado!\n\n");
  return NULL1;
}

unsigned long long int buscaOrdenada_DB(DataBase *Lista, char *Nome){

  TipoApontador Aux = Lista->DBFirst;

  while(Aux != NULL){

    int COMP = strcmp(Nome, Aux->Pessoa.Nome);
    if(COMP==0){
      printf("Funcionário encontrado!\n\n");
      return Aux->Pessoa.W_CODE;
    }
    
    Aux = Aux->Next;
  }
  printf("Funcionário não encontrado!\n\n");
  return 0;
}

void imprimeListaDB(DataBase *Lista, Data_Base *Static_List){

  selectionSortDB_Alfabeto(Lista, Static_List);

  TipoApontador Aux;
  Aux = Lista->DBFirst;

  printf("\n");
  while(Aux != NULL){

    printf("Nome: %s\n", Aux->Pessoa.Nome);
    printf("Cargo: %s\n", Aux->Pessoa.Cargo);
    printf("Telefone: %llu\n", Aux->Pessoa.Phone_Num);
    printf("Código de Identificação: %llu\n", Aux->Pessoa.W_CODE);
    printf("\n\n");

    Aux = Aux->Next;
  }
  
}

void Dinamic_2_Static(DataBase *Lista, Data_Base *Static_List){

  TipoApontador Aux;
  TipoPessoa pessoa;
  int v;
  Aux = Lista->DBFirst;

  startList(Static_List);
  v = Vazia(*Static_List);
  while(Aux != NULL){
    pessoa = Aux->Pessoa;
    insereFun(Static_List, pessoa);
    Aux = Aux->Next;
    Retira(Lista);
  }
}

void Static_2_Dinamic(Data_Base *Static_List, DataBase *Lista){

  int i;
  for(i = 0; i < Static_List->Last; i++){
    insereFunDB_NOPRINT(Lista, Static_List->Pessoa[i]);
  }

  Static_List->Last = Static_List->First;

}

void selectionSortDB_Alfabeto(DataBase *Lista, Data_Base *Static_List){

  Dinamic_2_Static(Lista, Static_List);
  selectionSort_Alfabeto(Static_List);
  Static_2_Dinamic(Static_List, Lista);
  
}

void insertionSortDB(DataBase *Lista, Data_Base *Static_List){

  Dinamic_2_Static(Lista, Static_List);
  insertionSort(Static_List);
  Static_2_Dinamic(Static_List, Lista);
  
}

void end_DB(DataBase *Lista, int n){

  FILE *arq;
  TipoApontador Aux = Lista->DBFirst;

  arq = fopen("data.txt", "w");
  if(!arq) exit(1);

  fprintf(arq, "1\n");
  fprintf(arq, "%d\n", n);

  
  while(Aux != NULL){

    fprintf(arq, "%s\n", Aux->Pessoa.Nome);
    fprintf(arq, "%s\n", Aux->Pessoa.Genero);
    fprintf(arq, "%s\n", Aux->Pessoa.Raca);
    fprintf(arq, "%s\n", Aux->Pessoa.Estado_Civil);
    fprintf(arq, "%s\n", Aux->Pessoa.Escolaridade);
    fprintf(arq, "%s\n", Aux->Pessoa.Cargo);
    fprintf(arq, "%f\n", Aux->Pessoa.Salario);
    fprintf(arq, "%d %d %d\n", Aux->Pessoa.Birthday_D, Aux->Pessoa.Birthday_M, Aux->Pessoa.Birthday_Y);
    fprintf(arq, "%llu\n", Aux->Pessoa.Phone_Num);
    fprintf(arq, "%llu\n", Aux->Pessoa.W_CODE);
    

    Aux = Aux->Next;
  }

  printf("\n");
  printf("Fim do programa!\n");

  fclose(arq);
  
}