//--------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------INCLUSAO DO ARQUIVO HEADER-------------------------------------------------------------
#include<genetics.h>


//--------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------CHECAR SE O RESULTADO FOI ATINGIDO-----------------------------------------------------


int checar_resultado(int *vetor)
{
	int i;
	for(i=0;i<k;i++)
	{
		if(vetor[i] == resultado)
		{
			return(i);
		}
	}
	return(-1);
}


//--------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------FIM DE CODIGO--------------------------------------------------------------------------