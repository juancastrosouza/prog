#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "listas.h"

typedef struct{
	char Nome[30];
	int Idade;
	char Lugar[11][11];
	int filme,hr,status;
}Registro;


int reserva(FILE *);
void consultap(FILE *);
void cancela(FILE *);
int tamarqp(FILE *);
void relatorio(FILE *);
void relatorioord(FILE *);

int main(void){
	setlocale(LC_ALL,"");
	int OP,k,j,i,l;
	FILE *arqp;
	arqp = fopen("dadosP.dat","rb+");
	if (arqp==0){
		arqp = fopen("dadosP.dat","wb+");	
	}
	
	do{
		system("cls");
		printf("================= MENU DE OPÇÕES ====================\n");
		printf("1. Fazer uma reserva.\n");
		printf("2. Cancelar uma reserva. \n");
		printf("3. Consultar uma reserva.\n");
		printf("4. Relatorio.\n");
		printf("5. Relatorio Ordenado.\n");
		printf("0. Exit\n");
		printf("=====================================================\n");
		printf("Filme 1 - Star Wars: Sarrada nas estrelas - +10 - Dublado/Legendado - Manhã/Tarde/Noite\n");
		printf("Filme 2 - Xeroque Rolmes                  - +14 - Dublado/Legendado - Manhã/Noite\n");
		printf("Filme 3 - Os Vampiros que se mordam       - +16 - Legendado - Tarde/Noite\n");
		printf("Filme 4 - Inatividade Paranormal          - +18 - Legendado - Noite\n");
		printf("Filme 5 - Frozen 7                        -   L - Dublado - Manhã\n ");
		printf("=====================================================\n");
		printf("Sua opção: ");
		scanf("%d",&OP);
		fflush(stdin);
				
		switch(OP){	
			
			case 1:{
				reserva(arqp);
				break;
			}
			case 2:{
				cancela(arqp);
				break;
			}
			case 3:{
				consultap(arqp);		
				break;
			}
			case 4:{
				relatorio(arqp);
				break;
			}
			case 5:{
				relatorioord(arqp);
				break;
			}
			case 0:{
				printf("Saindo do programa...");
				break;
			}
		}
	}while(OP!=0);
	fclose(arqp);
}

int reserva(FILE *arqp){
	Registro regp;
	int OPF,OPH,OPFi,OPP,k,i,j,l,ID,nr;
	
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			regp.Lugar[i][j]='O';
		}
	}	
	
	
	system("cls");
	printf("=====================================================\n");
	printf("Filme 1 - Star Wars: Sarrada nas estrelas \n");
	printf("Filme 2 - Xeroque Rolmes \n");
	printf("Filme 3 - Os Vampiros que se mordam  \n");
	printf("Filme 4 - Inatividade Paranormal   \n");
	printf("Filme 5 - Frozen 7  \n");
	printf("=====================================================\n");
	printf("Escolha um filme: ");
	scanf("%d",&OPF);
	regp.filme = OPF;
	
	
	
	switch(OPF){
		case 1:{
			system("cls");
			printf("====================== Star Wars: Sarrada nas estrelas ======================\n");
			printf("1. Manhã e Dublado\n");
			printf("2. Tarde e Dublado\n");
			printf("3. Noite e Dublado\n");
			printf("4. Manhã e Legendado\n");
			printf("5. Tarde e Legendado\n");
			printf("6. Noite e Legendado\n");
			printf("=============================================================================\n");
			printf("Escolha um horario:\n");
			scanf("%d",&OPH);
			
			regp.hr = OPH;	
			break;
		}
		case 2:{
			system("cls");
			printf("=========================== Xeroque Rolmes ===========================\n");
			printf("1. Manhã e Dublado\n");
			printf("2. Noite e Dublado\n");
			printf("3. Manhã e Legendado\n");
			printf("4. Noite e Legendado\n");
			printf("======================================================================\n");
			printf("Escolha um horario:\n");
			scanf("%d",&OPH);
						
			regp.hr = OPH;
			break;
		}
		case 3:{
			system("cls");
			printf("=========================== Os Vampiros que se mordam ===========================\n");
			printf("1. Tarde e Legendado\n");
			printf("2. Noite e Legendado\n");
			printf("=================================================================================\n");
			printf("Escolha um horario:\n");
			scanf("%d",&OPH);
						
			regp.hr = OPH;
			break;
		}
		case 4:{
			system("cls");
			printf("=========================== Inatividade Paranormal  ===========================\n");
			printf("1. Noite e Legendado\n");
			printf("===============================================================================\n");
			printf("Escolha um horario:\n");
			scanf("%d",&OPH);
						
			regp.hr = OPH;
			break;
		}
		case 5:{
			system("cls");
			printf("=========================== Frozen 7 ===========================\n");
			printf("1. Manhã e Dublado\n");
			printf("================================================================\n");
			printf("Escolha um horario:\n");
			scanf("%d",&OPH);
						
			regp.hr = OPH;
			break;
			}
		}
	fflush(stdin);
	system("cls");
	printf("Informe seu nome: ");
	gets(regp.Nome);
	printf("Informe sua idade: ");
	scanf("%d",&ID);
	fflush(stdin);
	
	switch(OPF){
		
		case 1:{
			if(ID<10){
				printf("Classificação indicativa não permidita! \n");
				system("pause");
				return 0;
			}else{
				printf("Continuando com a reserva... \n");
				regp.Idade = ID;
			}
			break;
		}
		case 2:{
			if(ID<14){
				printf("Classificação indicativa não permidita! \n");
				system("pause");
				return 0;
			}else{
				printf("Continuando com a reserva... \n");
				regp.Idade = ID;
			}
			break;
		}
		case 3:{
			if(ID<16){
				printf("Cassificação indicativa não permitida! \n");
				system("pause");
			return 0;
			}else{
				printf("Continuando com a reserva... \n");
				regp.Idade = ID;
			}
			break;
		}
		case 4:{
			if(ID<18){
				printf("Classificação indicativa não permitida! \n");
				system("pause");
			return 0;
			}else{
				printf("Continuando com a reserva... \n");
				regp.Idade = ID;
			}
			break;
		}
		case 5:{
			printf("Continuando com a reserva... \n");
			regp.Idade = ID;
			break;
		}
	}
	system("pause");
	system("cls");
	
	k=0;
	printf("     0   1   2   3   4   5   6   7   8  9   \n");
	printf("  -------------------------------------------\n");
	for (i=0;i<10;i++){
		k++;
		printf("%d | ",k-1);
		for (j=0;j<10;j++){
			printf(" %c  ",'O');
		}
		printf("| ");
		printf("\n");
	}
	printf("  --------------------TELA-------------------\n");
	
	printf("Escolha uma fileira: ");
	scanf("%d",&OPFi);
	fflush(stdin);
	printf("Escolha uma poltrona: ");
	scanf("%d",&OPP);
	fflush(stdin);
	
	if(regp.Lugar[OPFi][OPP] == 'X'){
		printf("Este lugar está ocupado! \n");
		system("pause");
		return 0;
	}else{
		regp.Lugar[OPFi][OPP]='X';
	}
	regp.status=1;
	printf("Número do ingresso: %d\n", tamarqp(arqp)+1);
	fseek(arqp,0,SEEK_END);
	fwrite(&regp,sizeof(Registro),1,arqp);
	fflush(stdin);
	
	printf("Reserva efetuada com sucesso!\n");
	system("pause");	
}

void consultap(FILE *arqp){
	int nr,i,j,F,P,k;
	printf("Entre com o número do ingresso: ");
	scanf("%d",&nr);
	fflush(stdin);
	
	Registro reg;
	fseek(arqp,(nr-1)*sizeof(Registro),SEEK_SET);
	fread(&reg,sizeof(Registro),1,arqp);
	system("cls");
	printf("Nome.....:%s\n",reg.Nome);
	switch(reg.filme){
		case 1:{
			printf("Filme....:Star Wars: Sarrada nas estrelas \n");
			break;
		}
		case 2:{
			printf("Filme....:Xeroque Rolmes \n");
			break;
		}
		case 3:{
			printf("Filme....:Os Vampiros que se mordam \n");
			break;
		}
		case 4:{
			printf("Filme....:Inatividade Paranormal \n");
			break;
		}
		case 5:{
			printf("Filme....:Frozen 7 \n");
			break;
		}
	}	
		
	switch(reg.hr){
		case 1:{
			printf("Horario..:Manhã e Dublado\n");
			break;
		}
		case 2:{
			printf("Horario..:Tarde e Dublado\n");
			break;
		}
		case 3:{
			printf("Horario..:Noite e Dublado\n");
			break;
		}
		case 4:{
			printf("Horario..:Manhã e Legendado\n");
			break;
		}
		case 5:{
			printf("Horario..:Tarde e Legendado\n");
			break;
		}
		case 6:{
			printf("Horario..:Noite e Legendado\n");
			break;
		}
	}
	if (reg.status == 1){
		printf("Status...:Ativo\n");
	}else{
		printf("Status...:Inativo\n");
	}
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			if(reg.Lugar[i][j] == 'X'){
				F = i;
				P = j;
			}
		}
	}
	printf("Fileira..:%d  \nPoltrona.:%d\n",F,P);
	printf("     0   1   2   3   4   5   6   7   8  9   \n");
	printf("  -------------------------------------------\n");
	for (i=0;i<10;i++){
		k++;
		printf("%d | ",k-1);
		for (j=0;j<10;j++){
			printf(" %c  ",reg.Lugar[i][j]);
		}
		printf("| ");
		printf("\n");
	}
	printf("  --------------------TELA-------------------\n");
	system("pause");
	fflush(stdin);
}

void cancela(FILE *arqp){
	int nr,F,P,i,j;
	Registro reg;
	system("cls");
	printf("=====================================================\n");
	printf("Entre com o número do ingresso: ");
	scanf("%d",&nr);
	fflush(stdin);
	
	fseek(arqp,(nr-1)*sizeof(Registro),SEEK_SET);
	fread(&reg,sizeof(Registro),1,arqp);
	
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			if(reg.Lugar[i][j] == 'X'){
				F = i;
				P = j;
			}
		}
	}
	
	reg.status = 0;
	fseek(arqp,(nr-1)*sizeof(Registro),SEEK_SET);
	fwrite(&reg,sizeof(Registro),1,arqp);	
	printf("Reserva cancelada com sucesso!\n");
	system("pause");
	printf("=====================================================\n");
	fflush(stdin);
}

void relatorio(FILE *arqp){
	int nr,i,j,F,P,k;
	Registro reg;
	FILE *arqtxt=fopen("Relatorio.txt","w");
	fprintf(arqtxt,"Reservas Ativas\n");
	fprintf(arqtxt,"==============================================================\n");
	for(nr=0;nr<tamarqp(arqp);nr++){
			fseek(arqp,nr*sizeof(Registro),SEEK_SET);
			fread(&reg,sizeof(Registro),1,arqp);
		if(reg.status == 1){
			fprintf(arqtxt,"Nome.....:%s\n",reg.Nome);
			switch(reg.filme){
				case 1:{
					fprintf(arqtxt,"Filme....:Star Wars: Sarrada nas estrelas \n");
					break;
				}
				case 2:{
					fprintf(arqtxt,"Filme....:Xeroque Rolmes \n");
					break;
				}
				case 3:{
					fprintf(arqtxt,"Filme....:Os Vampiros que se mordam \n");
					break;
				}
				case 4:{
					fprintf(arqtxt,"Filme....:Inatividade Paranormal \n");
					break;
				}
				case 5:{
					fprintf(arqtxt,"Filme....:Frozen 7 \n");
					break;
				}
			}	
				
			switch(reg.hr){
				case 1:{
					fprintf(arqtxt,"Horario..:Manhã e Dublado\n");
					break;
				}
				case 2:{
					fprintf(arqtxt,"Horario..:Tarde e Dublado\n");
					break;
				}
				case 3:{
					fprintf(arqtxt,"Horario..:Noite e Dublado\n");
					break;
				}
				case 4:{
					fprintf(arqtxt,"Horario..:Manhã e Legendado\n");
					break;
				}
				case 5:{
					fprintf(arqtxt,"Horario..:Tarde e Legendado\n");
					break;
				}
				case 6:{
					fprintf(arqtxt,"Horario..:Noite e Legendado\n");
					break;
				}
			}
			for (i=0;i<10;i++){
				for (j=0;j<10;j++){
					if(reg.Lugar[i][j] == 'X'){
						F = i;
						P = j;
					}
				}
			}
			fprintf(arqtxt,"Fileira..:%d  \nPoltrona.:%d\n\n",F,P);
			fprintf(arqtxt,"     0   1   2   3   4   5   6   7   8  9   \n");
			fprintf(arqtxt,"  -------------------------------------------\n");
			k=0;
			for (i=0;i<10;i++){
				k++;
				fprintf(arqtxt,"%d | ",k-1);
				for (j=0;j<10;j++){
					fprintf(arqtxt," %c  ",reg.Lugar[i][j]);
				}
				fprintf(arqtxt,"| ");
				fprintf(arqtxt,"\n");
			}
			fprintf(arqtxt,"  --------------------TELA-------------------\n");
			fflush(stdin);
			fprintf(arqtxt,"\n==============================================================\n\n");	
		}
			
	}
	fclose(arqtxt);
	printf("Relatorio gerado com sucesso!\n");
	system("pause");
}

void relatorioord(FILE *arqp){
	Lista L;
	Linit(&L);
	int nr,i,j,F,P,k;
	Registro reg;
	Elem X;
	
	for(nr=0;nr<tamarqp(arqp);nr++){
		fseek(arqp,nr*sizeof(Registro),SEEK_SET);
		fread(&reg,sizeof(Registro),1,arqp);
		strcpy(X.nome,reg.Nome);
		X.nr = nr;
		Lins(&L,X);
	}
	int c;
	FILE *arqtxt=fopen("RelatioOrdenado.txt","w");
	fprintf(arqtxt,"Reservas Ativas\n");
	fprintf(arqtxt,"==============================================================\n");
	for(c=0;c<L.Fim;c++){
		nr=L.M[c].nr;
		fseek(arqp,nr*sizeof(Registro),SEEK_SET);
		fread(&reg,sizeof(Registro),1,arqp);	
		if(reg.status == 1){
			fprintf(arqtxt,"Nome.....:%s\n",reg.Nome);
			switch(reg.filme){
				case 1:{
					fprintf(arqtxt,"Filme....:Star Wars: Sarrada nas estrelas \n");
					break;
				}
				case 2:{
					fprintf(arqtxt,"Filme....:Xeroque Rolmes \n");
					break;
				}
				case 3:{
					fprintf(arqtxt,"Filme....:Os Vampiros que se mordam \n");
					break;
				}
				case 4:{
					fprintf(arqtxt,"Filme....:Inatividade Paranormal \n");
					break;
				}
				case 5:{
					fprintf(arqtxt,"Filme....:Frozen 7 \n");
					break;
				}
			}	
				
			switch(reg.hr){
				case 1:{
					fprintf(arqtxt,"Horario..:Manhã e Dublado\n");
					break;
				}
				case 2:{
					fprintf(arqtxt,"Horario..:Tarde e Dublado\n");
					break;
				}
				case 3:{
					fprintf(arqtxt,"Horario..:Noite e Dublado\n");
					break;
				}
				case 4:{
					fprintf(arqtxt,"Horario..:Manhã e Legendado\n");
					break;
				}
				case 5:{
					fprintf(arqtxt,"Horario..:Tarde e Legendado\n");
					break;
				}
				case 6:{
					fprintf(arqtxt,"Horario..:Noite e Legendado\n");
					break;
				}
			}
			for (i=0;i<10;i++){
				for (j=0;j<10;j++){
					if(reg.Lugar[i][j] == 'X'){
						F = i;
						P = j;
					}
				}
			}
			k=0;
			fprintf(arqtxt,"Fileira..:%d  \nPoltrona.:%d\n\n",F,P);
			fprintf(arqtxt,"     0   1   2   3   4   5   6   7   8  9   \n");
			fprintf(arqtxt,"  -------------------------------------------\n");
			for (i=0;i<10;i++){
				k++;
				fprintf(arqtxt,"%d | ",k-1);
				for (j=0;j<10;j++){
					fprintf(arqtxt," %c  ",reg.Lugar[i][j]);
				}
				fprintf(arqtxt,"| ");
				fprintf(arqtxt,"\n");
			}
			fprintf(arqtxt,"  --------------------TELA-------------------\n");
			fflush(stdin);
			fprintf(arqtxt,"\n==============================================================\n\n");	
		}
	}
	fclose(arqtxt);
	printf("Relatorio gerado com sucesso!\n");
	system("pause");
	
}

int tamarqp(FILE *arqp){
	fseek(arqp,0,SEEK_END);
	return ftell(arqp)/sizeof(Registro);
}

