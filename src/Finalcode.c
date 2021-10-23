#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define plv 1000

struct node{
	int chave;
	struct node *esquerda;
	struct node *direita;
	int FatBal;
};

typedef struct node NODE;

int altura_arvore(NODE* raiz4)
{
   int AlturaE , AlturaD;

   if(raiz4 != NULL)
   {
       AlturaE = altura_arvore(raiz4->esquerda);
       AlturaD = altura_arvore(raiz4->direita);
       if( AlturaE > AlturaD ) return( AlturaE + 1);
       else return(AlturaD + 1);
   }
   else return(0);
}

int def_FB(NODE* raiz5){

	int altEsquerda = altura_arvore(raiz5->esquerda);
	int altDireita = altura_arvore(raiz5->direita);
	raiz5->FatBal = altEsquerda - altDireita;
	return raiz5->FatBal;

}

NODE* insert(NODE *raiz1, int i){
	
	if(raiz1 != NULL){
		if(i<raiz1 -> chave){
			raiz1->esquerda = insert(raiz1->esquerda, i);
			return raiz1;
		}else{
			raiz1->direita = insert(raiz1->direita, i);
			return raiz1;
		}
	}
	
	NODE *novo = (NODE*)malloc(sizeof(NODE));
	novo->direita = NULL;
	novo->esquerda = NULL;
	novo->chave = i;
	return novo;
}

void imprimir(NODE* raiz3){
	int aux;
	if(raiz3!=NULL){
		
		imprimir(raiz3->esquerda);
		aux = def_FB(raiz3);
		printf("%i	%i\n", raiz3->chave, aux);
		imprimir(raiz3->direita);
	}
}

void desaloca(NODE* raiz6){
	if(raiz6!=NULL){
		
		free(raiz6->direita);
		free(raiz6->esquerda);
	}
	
	printf("Memoria desalocada com sucesso\n");
}

int main()
{
	char arq[20], temp[plv];
	char *subs;
	int valor;
	printf("Nome do arquivo .csv:\n");
	scanf("%s", arq);
	
	NODE *raiz = NULL; //CRIANDO O PRIMEIRO NÓ;
	FILE *arquivo = fopen(arq, "r");
	
	long long i;
	while(fgets(temp, plv, arquivo) != NULL){
		subs=strtok(temp, ",;");
		while(subs != NULL){
			i = strtol(subs,NULL,10);
			raiz = insert(raiz, i);
			subs=strtok(NULL, ",;");
		}
	}
	printf("Chave	FatBal\n");
	imprimir(raiz);
	
	system("pause");
	desaloca(raiz);
	
	return 0;
}
