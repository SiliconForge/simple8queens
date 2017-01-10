//--------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------INCLUSAO DO ARQUIVO HEADER-------------------------------------------------------------
#include<genetics.h>


//--------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------CORPO PRINCIPAL------------------------------------------------------------------------


void main()
{
	printf("\n------------------------------------------------------\n");
	printf("|Resolvedor das oito rainhas por algoritimo genetico.|");
	printf("\n------------------------------------------------------\n\n");
	int estados_atuais[T][k];
	int estados_auxiliares[T][k];
	int valores_fitness[k];
	int resposta[T];
	int num_gen=0;
	bool falha=0;
	inicio(estados_atuais);
	fitness_populacao(estados_atuais,valores_fitness);
	while(checar_resultado(valores_fitness) == -1)
	{
		reproduzir_populacao(estados_atuais,estados_auxiliares,valores_fitness,pais);
		fitness_populacao(estados_atuais,valores_fitness);
		if(num_gen%100) printf("\rGeracao numero: %d",num_gen);
		num_gen++;
		if(num_gen>=50000)
		{
			falha=1;
			break;
		}		
	}						
	pegar_vetor(estados_atuais,resposta,checar_resultado(valores_fitness));
	mostra_tabuleiro(resposta);	
	if(falha==0) printf("\nForam necessarias %d geracoes para convergir ao resultado.\n\n",num_gen);
	if(falha==1) 
	{
	printf("\nO codigo nao convergiu devido a estar preso em um minimo local, tente novamente\n\n");
	main();	
	}
}


//--------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------FIM DE CODIGO--------------------------------------------------------------------------
