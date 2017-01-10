//--------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------INCLUSAO DO ARQUIVO HEADER-------------------------------------------------------------
#include<genetics.h>


//--------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------FUNCAO DE REPRODUCAO DE POPULACAO------------------------------------------------------


void reproduzir_populacao(int matriz[][k],int matriz_auxiliar[][k],int *vetor,int geradores)
{
	int aux[T];
	int auxiliar_fitness[k];
	int reprodutor_1[T];
	int reprodutor_2[T];
	int aleatorio;
	copy(auxiliar_fitness,vetor,k);
	int i,j,qual_pai;
	qual_pai=0;
	for(i=0;i<geradores;i++)
	{
		for(j=0;j<k;j++)
		{
		copy(auxiliar_fitness,vetor,k);
			if(auxiliar_fitness[j]>auxiliar_fitness[qual_pai])
			{
				qual_pai = j;
				auxiliar_fitness[j]=0;
			}
		pegar_vetor(matriz,aux,qual_pai);
		insere_vetor(matriz_auxiliar,aux,i);
		}
	}
	for(i=0;i<k;i++)
	{
		aleatorio = rand()%geradores;
		pegar_vetor(matriz_auxiliar,reprodutor_1,aleatorio);
		aleatorio = rand()%geradores;
		pegar_vetor(matriz_auxiliar,reprodutor_2,aleatorio);
		crossover(reprodutor_1,reprodutor_2);
		aleatorio = rand()%100;
		if(aleatorio < muta)
		{
			mutacao(reprodutor_1);
		}
		insere_vetor(matriz,reprodutor_1,i);
	}	
}


//--------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------FIM DE CODIGO--------------------------------------------------------------------------
