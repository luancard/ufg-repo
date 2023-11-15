/*

Alunos: Luan Dias Cardoso Costa    Matrícula: 202003589
        Igor Daniel Toledo Campos  Matrícula: 202103733

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rh.h"

#define STR_LEN 100

int main(void) {

  DataBase Lista;
  Data_Base Static_List;
  FILE *arq;
  int n, boo;
  unsigned long long int cod;
  char nome[STR_LEN];
  TipoPessoa pessoa;

  srand( (unsigned)time(NULL) );

  startListDB(&Lista);
  VaziaDB(Lista);

  arq = fopen("data.txt", "r");
  if(!arq) exit(1);

  fscanf(arq, "%d%*c", &boo);

  if(boo == 0){
    fscanf(arq, "%d%*c", &n);
    for(int i = 0; i<n; i++){
  
      fscanf(arq, "%[^\n]%*c", pessoa.Nome);
      fscanf(arq, "%[^\n]%*c", pessoa.Genero);
      fscanf(arq, "%[^\n]%*c", pessoa.Raca);
      fscanf(arq, "%[^\n]%*c", pessoa.Estado_Civil);
      fscanf(arq, "%[^\n]%*c", pessoa.Escolaridade);
      fscanf(arq, "%[^\n]%*c", pessoa.Cargo);
      fscanf(arq, "%f%*c", &(pessoa.Salario));
      fscanf(arq, "%d %d %d%*c", &(pessoa.Birthday_D), &(pessoa.Birthday_M), &(pessoa.Birthday_Y));
      fscanf(arq, "%llu%*c", &(pessoa.Phone_Num));
      pessoa.W_CODE = (unsigned long long int)rand() % 999999999999;
  
      insereFunDB(&Lista, pessoa);
      
    }
    fclose(arq);
  } else {

    fscanf(arq, "%d%*c", &n);
    for(int i = 0; i<n; i++){
  
      fscanf(arq, "%[^\n]%*c", pessoa.Nome);
      fscanf(arq, "%[^\n]%*c", pessoa.Genero);
      fscanf(arq, "%[^\n]%*c", pessoa.Raca);
      fscanf(arq, "%[^\n]%*c", pessoa.Estado_Civil);
      fscanf(arq, "%[^\n]%*c", pessoa.Escolaridade);
      fscanf(arq, "%[^\n]%*c", pessoa.Cargo);
      fscanf(arq, "%f%*c", &(pessoa.Salario));
      fscanf(arq, "%d %d %d%*c", &(pessoa.Birthday_D), &(pessoa.Birthday_M), &(pessoa.Birthday_Y));
      fscanf(arq, "%llu%*c", &(pessoa.Phone_Num));
      fscanf(arq,"%llu%*c", &(pessoa.W_CODE));
  
      insereFunDB_NOPRINT(&Lista, pessoa);
      
    }
    fclose(arq);
    
  }

    


  int esc = 1;
  printf("\n");
  printf("/--- BEM VINDO AO NOSSO SERVIÇO DE BANCO DE DADOS! ---/\n");
  printf("Digite a ação que gostaria de fazer agora:\n");
  printf("(0)SAIR\n");
  printf("(1)PESQUISAR ALGUMA INFORMAÇÃO NO BANCO DE DADOS\n");
  printf("(2)INSERIR INFORMAÇÕES NO BANCO DE DADOS\n");
  printf("(3)REMOVER AS INFORMAÇÕES DE ALGUÉM DO BANCO DE DADOS\n");
  printf("(4)ALTERAR AS INFORMAÇÕES DE ALGUÉM\n");
  printf("(5)VERIFICAR QUANTAS INFORMAÇÕES ESTÃO CADASTRADAS NO BANCO DE DADOS\n");
  printf("(6)IMPRIMIR A LISTA COMPLETA DO BANCO DE DADOS\n");

  while(esc != 0){

    scanf("%d%*c", &esc);
    
    switch(esc){
      case 1:
        printf("\n");
        printf("Digite o nome do funcionário que deseja conferir: ");
        scanf("%[^\n]%*c", nome);
        printf("\n");
        access_Fun(&Lista, nome);
        printf("\n\n");
      break;

      case 2:
        printf("\n");
        insereNewFunDB(&Lista);
        n++;
        printf("\n\n");
      break;

      case 3:
        printf("\n");
        printf("Digite o nome do funcionário que deseja remover: ");
        scanf("%[^\n]%*c", nome);
        printf("\n");
        removeFunDB(buscaOrdenada_DB(&Lista, nome), &Lista);
        n--;
      break;

      case 4:
        printf("\n");
        printf("Digite o nome do funcionário o qual deseja alterar as informações: ");
        scanf("%[^\n]%*c", nome);
        printf("\n");
        unsigned long long int busca = buscaOrdenada_DB(&Lista, nome);
        if(busca == 0){
          printf("Nome inválido!\n");
        } else {
          alteraDados(busca, &Lista, &Static_List); 
        }
      break;

      case 5:
        printf("\n");
        VaziaDB(Lista);
      break;

      case 6:
        printf("\n");
        imprimeListaDB(&Lista, &Static_List);
      break;

      case 0:
        end_DB(&Lista, n);
      break;
      
      default:
        printf("Comando inválido!\n");
    }
    if(esc != 0){
      printf("Digite novamente a ação que gostaria de fazer agora:\n");
      printf("(0)SAIR\n");
      printf("(1)PESQUISAR ALGUMA INFORMAÇÃO NO BANCO DE DADOS\n");
      printf("(2)INSERIR INFORMAÇÕES NO BANCO DE DADOS\n");
      printf("(3)REMOVER AS INFORMAÇÕES DE ALGUÉM DO BANCO DE DADOS\n");
      printf("(4)ALTERAR AS INFORMAÇÕES DE ALGUÉM\n");
      printf("(5)VERIFICAR QUANTAS INFORMAÇÕES ESTÃO CADASTRADAS NO BANCO DE DADOS\n");
      printf("(6)IMPRIMIR A LISTA COMPLETA DO BANCO DE DADOS\n");
    }
  }
  
  
  return 0;
}