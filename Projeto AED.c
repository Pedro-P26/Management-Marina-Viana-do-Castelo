/*Engenharia Informática*/
/*Projeto 1 Algoritmos e Estruturas de Dados*/
/*Problema 1-Gestão da Marina de Viana do Castelo*/
/*Pedro Poças nº28976 e Jorge Amorim nª29058*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMBAS 186
#include <locale.h>

struct embarcacao{
	char nome_matri[50];
	char letras_p[5];
	char nome_p[50];
	char nome_c[50];
	char pais_o[50];
	char tipo_c;
	int tot_d;
	int n_snem;
	int qtd_p;
	int dia_entra;
	int mes_entra;
	int ano_entra;
	int dia_saida;
	int mes_saida;
	int ano_saida;
};

struct embarcacao embas[MAX_EMBAS];
int i;
int n_emba=0;

void registrar_embarcacao(struct embarcacao emba){
	embas[n_emba]=emba;
	n_emba++;
}

struct embarcacao dados(){
	setlocale(LC_ALL,"Portuguese");
	struct embarcacao auxiliar;
	printf("\n\n");
	fflush(stdin);
	printf("Introduza o tipo de cais (formato-M):\n");
	fflush(stdin);
	scanf("%c",&auxiliar.tipo_c);
	fflush(stdin);
	printf("Introduza a matricula da embarcação (formato NOME-######-$PT):\n");
	fflush(stdin);
	scanf("%s-%d-%s",auxiliar.nome_matri,&auxiliar.n_snem,auxiliar.letras_p);
	fflush(stdin);
	printf("\nNome do proprietário:\n");
	fflush(stdin);
	fgets(auxiliar.nome_p,50,stdin);
	fflush(stdin);
	printf("\nNome do capitão:\n");
	fflush(stdin);
	fgets(auxiliar.nome_c,50,stdin);
	fflush(stdin);
	printf("\nPaís de origem:\n");
	fflush(stdin);
	fgets(auxiliar.pais_o,50,stdin);
	fflush(stdin);
	printf("\nQuantidade de passageiros:\n");
	fflush(stdin);
	scanf("%d",&auxiliar.qtd_p);
	fflush(stdin);
	printf("\nTotal de dias estadia:\n");
	fflush(stdin);
	scanf("%d",&auxiliar.tot_d);
	fflush(stdin);
	printf("\nDia de entrada(Formato dd/mm/aaaa):\n");
	fflush(stdin);
	scanf("%d/%d/%d",&auxiliar.dia_entra,&auxiliar.mes_entra,&auxiliar.ano_entra);
	fflush(stdin);
	printf("\nDia de saida(Formato dd/mm/aaaa):\n");
	fflush(stdin);
	scanf("%d/%d/%d",&auxiliar.dia_saida,&auxiliar.mes_saida,&auxiliar.ano_saida);
	fflush(stdin);
	printf("\n");
	return auxiliar;
}
void imprimeEMBAS(){
	setlocale(LC_ALL,"Portuguese");
	for (i=0;i<n_emba;i++){
		printf("*****************************\n");
		printf("Embarcação:%d\n\n",i+1);
		printf("Cais:%c\n",embas[i].tipo_c);
		printf("Matricula embarcação:%s-%d-%s\n",embas[i].nome_matri,embas[i].n_snem,embas[i].letras_p);
		printf("Nome do proprietário:%s\n",embas[i].nome_p);
		printf("Nome do capitão:%s\n",embas[i].nome_c);
		printf("Quantidade de passageiros:%d\n",embas[i].qtd_p);
		printf("País de origem:%s\n",embas[i].pais_o);
		printf("Total de dias estadia:%d\n",embas[i].tot_d);
		printf("Dia de entrada:%d/%d/%d\n",embas[i].dia_entra,embas[i].mes_entra,embas[i].ano_entra);
		printf("Dia de saida:%d/%d/%d\n",embas[i].dia_saida,embas[i].mes_saida,embas[i].ano_saida);
		printf("******************************\n\n");
	}
}
int Menu(){
	setlocale(LC_ALL,"Portuguese");
	int opcao;
	printf("Marina de Viana do Castelo\n\n");
	printf("0-Informações Marina\n");
	printf("1-Informações sobre os cais\n");
	printf("2-Inserir embarcação\n");
	printf("3-Listar embarcação\n");
	printf("4-Listar por tipo de cais\n");
	printf("5-Listar com mesmo dia de saida\n");
	printf("6-Prolongar estadia\n");
	printf("7-Preco de cada tipo de cais\n");
	printf("8-Remover embarcação\n");
	printf("9-Sair\n\n");
	printf("O que pretende fazer?");
	scanf("%d",&opcao);
	
	return opcao;
}
void remover_emba(int qtd_emba){
	setlocale(LC_ALL,"Portuguese");
	int indice =qtd_emba -1;
	int i=0;
	
	if((qtd_emba<1)||(qtd_emba>n_emba)){
		printf("Não foi possivel remover\n");
		return;
	}
	if(qtd_emba == n_emba){
		n_emba--;
		return;
	}

	for (i=indice;i<n_emba;i++){
		embas[i]=embas[i+1];
	}
	n_emba--;
	
}
int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	char t_c;
	int op;
	int rem=0;
	struct embarcacao nova_emba;
	int r;
	int t_d;
	float resolt;
	
	do{
		op=Menu();
		switch(op){
			case 0:
				printf("\n");	
				printf("AVISO!\n\n");
				
				printf("Para novos clientes na nossa Marina quem permanecer mais de 30 dias terá um desconto 10 porcento na sua estadia\n\n");
				
				return Menu();
				
			case 1:
				printf("\n");
				fflush(stdin);
				printf("Tipo de cais     Classe     Comprimento fora a fora\n");
				printf("     A              1               Ate 7.99m      \n");
				printf("     B              2               8 - 9.99m      \n");
				printf("     C              3               10- 7.99m      \n");
				printf("     D              4               12- 7.99m      \n");
				printf("     E              5               15-14.99m      \n");
				printf("     F              6               18- 7.99m      \n");
				printf("     G              7                  >  20m      \n");
				printf("\n");
				return Menu();	
			case 2:
				if(n_emba==MAX_EMBAS){
					printf("\nA nossa Marina já se encontra com a lotação cheia!\n");
					break;
				}
				nova_emba=dados();
				registrar_embarcacao(nova_emba);
				for(i=0;i<n_emba;i++){
					if(embas[i].tot_d>=30)
					printf("AVISO!\n");
					printf("No final da sua estadia vai ter um desconto de 10 porcento\n");
					printf("\n");
				}
				break;
			case 3:
				if(n_emba==0){
					printf("\n");
					printf("Não existe embarcação\n");
					printf("\n");
					break;
				}
				imprimeEMBAS();
				break;
			case 4:
				listar_t_c();
				break;
			
			case 5:
				embarcacao_saida_mesmo_dia();
				break;
			case 6:
				prolongar_estadia();
				break;
				
			case 7:
				printf("Qual cais pretende saber o preço (formato-M):");
				fflush(stdin);
				scanf("%c",&t_c);
				fflush(stdin);
				printf("\n\n");
				switch(t_c){
					case 'A':
						printf("***********************\n");
						printf("10.40 euros por dia\n");
						printf("***********************\n");
						printf("\n");
						break;
					
					case 'B':
						printf("************************\n");
						printf("\n15.50 euros por dia\n");
						printf("************************\n");
						printf("\n");
						break;
					
					case 'C':
						printf("*************************\n");
						printf("\n19.50 euros por dia\n");
						printf("*************************\n");
						printf("\n");
						break;
					
					case 'D':
						printf("*************************\n");
						printf("\n25.60 euros por dia\n");
						printf("*************************\n");
						printf("\n");
						break;
				
					case 'E':
						printf("*************************\n");
						printf("\n50.50 euros por dia\n");
						printf("*************************\n");
						printf("\n");
						break;
					
					case 'F':
						printf("*************************\n");
						printf("\n62.80 euros por dia\n");
						printf("*************************\n");
						printf("\n");
						break;
					
					case 'G':
						printf("*************************\n");
						printf("\n80.00 euros por dia\n");
						printf("*************************\n");
						printf("\n");
						break;
				}
				break;
				
			case 8:
				printf("\n");
				if(n_emba==0){
					printf("Não tem embarcação\n");
					printf("\n");
					break;
				}
				printf("Qual o numero da embarcação que pretende remover:\n");
				scanf("%d",&r);
				remover_emba(r);
				printf("Cais da embarcação:\n");
				fflush(stdin);
				scanf("%c",&t_c);
				fflush(stdin);
				printf("Número de dias atracado?\n");
				fflush(stdin);
				scanf("%d",&t_d);
				fflush(stdin);
				
				
					switch(t_c){
						case 'A':
							resolt=t_d*10.40;
							printf("Preço final da sua estadia=%0.2f euros",resolt);
							printf("\n");
							break;
						
						case 'B':
							resolt=t_d*15.50;
							printf("Preço final da sua estadia=%0.2f euros",resolt);
							printf("\n");
							break;
						
						case 'C':
							resolt=t_d*19.50;
							printf("Preço final da sua estadia=%0.2f euros",resolt);
							printf("\n");
							break;
						case 'D':
							resolt=t_d*25.60;
							printf("Preço final da sua estadia=%0.2f euros",resolt);
							printf("\n");
							break;
						case 'E':
							resolt=t_d*50.50;
							printf("Preço final da sua estadia=%0.2f euros",resolt);
							printf("\n");
							break;
						case 'F':
							resolt=t_d*62.80;
							printf("Preço final da sua estadia=%0.2f euros",resolt);
							printf("\n");
							break;
						case 'G':
							resolt=t_d*80.00;
							printf("Preço final da sua estadia=%0.2f euros",resolt);
							printf("\n");
							break;
					}
						
				printf("\n");
				break;
				
			case 9:
				return 0;
				break;

			default:
				printf("Inválido");
		}
	}
	while (op!=0);
	return 0;
}

int prolongar_estadia(){
	setlocale(LC_ALL,"Portuguese");
	int i;
	int num;
	int auxiliar_dia_saida;
	int auxiliar_mes_saida;
	int auxiliar_ano_saida;
	printf("Introduza o número da embarcação que deseja prolongar a estadia: ");
	scanf("%d", &num);
	printf("Introduza a nova data de saída: ");
	scanf("%d/%d/%d",&auxiliar_dia_saida,&auxiliar_mes_saida,&auxiliar_ano_saida);
	i = num -1;
	

	embas[i].dia_saida = auxiliar_dia_saida;
	embas[i].mes_saida = auxiliar_mes_saida;
	embas[i].ano_saida = auxiliar_ano_saida;
	printf("\n");
	printf("Nova data de saída embarcação: %d/%d/%d\n", embas[i].dia_saida, embas[i].mes_saida, embas[i].ano_saida );
	printf("\n");
}

int listar_t_c(){
	setlocale(LC_ALL,"Portuguese");
	int tip_c;
	
	printf("Introduza o tipo de cais (Formato-M):");
	fflush(stdin);
	scanf("%c",&tip_c);
	fflush(stdin);
	for(i=0;i<n_emba;i++){
		if(n_emba==0){
			printf("Não tem embarcação");
			break;
		}
		if(tip_c==embas[i].tipo_c){
			printf("\n");
			printf("**********************************\n");
			printf("Embarcação:%d\n",i+1);
			printf("\n");
			printf("Cais:%c\n",embas[i].tipo_c);
			printf("Matricula embarcação:%s-%d-$%s\n",embas[i].nome_matri,embas[i].n_snem,embas[i].letras_p);
			printf("Nome do proprietário:%s\n",embas[i].nome_p);
			printf("Nome do capitão:%s\n",embas[i].nome_c);
			printf("Quantidade de passageiros:%d\n",embas[i].qtd_p);
			printf("País de origem:%s\n",embas[i].pais_o);
			printf("Total dias estadia:%d\n",embas[i].tot_d);
			printf("Dia de entrada:%d/%d/%d\n",embas[i].dia_entra,embas[i].mes_entra,embas[i].ano_entra);
			printf("Dia de saida:%d/%d/%d\n",embas[i].dia_saida,embas[i].mes_saida,embas[i].ano_saida);
			printf("***********************************\n");
		}
	}
}
int embarcacao_saida_mesmo_dia(){
	setlocale(LC_ALL,"Portuguese");
	int d_s,m_s,a_s;
	if(n_emba==0){
		printf("Não existe embarcações\n");
		return 0;
	}
	printf("Introduza a data de saida das embarcação:\n");
	fflush(stdin);
	scanf("%d/%d/%d",&d_s,&m_s,&a_s);
	
	for(i=0;i<n_emba;i++){
		
		if(d_s==embas[i].dia_saida && m_s==embas[i].mes_saida && a_s==embas[i].ano_saida){
			printf("\n");
			printf("**************************************\n");
			printf("Embarcação:%d\n",i+1);
			printf("Cais:%c\n",embas[i].tipo_c);
			printf("Matricula embarcação:%s-%d-$%s\n",embas[i].nome_matri,embas[i].n_snem,embas[i].letras_p);
			printf("Nome do proprietário:%s\n",embas[i].nome_p);
			printf("Nome do capitão:%s\n",embas[i].nome_c);
			printf("Quantidade de passageiros:%d\n",embas[i].qtd_p);
			printf("País de origem:%s\n",embas[i].pais_o);
			printf("Total de dias estadia:%d\n",embas[i].tot_d);
			printf("Dia de entrada:%d/%d/%d\n",embas[i].dia_entra,embas[i].mes_entra,embas[i].ano_entra);
			printf("Dia de saida:%d/%d/%d\n",embas[i].dia_saida,embas[i].mes_saida,embas[i].ano_saida);
			printf("***************************************");
			printf("\n");
		}
		printf("Não existe embarcações com o mesmo dia de saida\n");
		printf("\n");
		break;
	}
}
