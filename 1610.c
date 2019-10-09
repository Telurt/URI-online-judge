#include <stdio.h>
#define branco -1
#define cinza 0
#define preto 1

/*structure for problems*/
typedef struct noh
{
	int num;
	struct noh *next;
}noh;



typedef struct inicio
{
	int cor;
	struct noh *next;
}inicio;


/*functions */

void incluir(inicio *ini, int numero)
{
	noh *p = (noh*) malloc(sizeof(noh));
	p->num = numero;
	p->next = ini->next;
	ini->next = p;
}

int dfs(inicio vet[], int *y)
{
	int z;
	noh *p = vet[*y].next;

	while(p)
	{
		z = p->num;
		if(vet[z].cor == preto)
		{
			p = p->next;
			continue;
		}
		if(vet[z].cor == cinza)	return 1;
		vet[z].cor = cinza;
		if(dfs(vet,&z)) return 1;
		p = p->next;

	}
	vet[*y].cor = preto;
	return 0;
}



/*principal function*/
int main()
{
	int aux = 0, n, x,y, n_doc, n_depend;

	scanf("%d",&n);

	int k,i,m;
	short int flag;


	inicio *vet;

	for(k=0; k<n; k++)
	{
		flag = 0;

		scanf("%d %d",&n_doc, &n_depend);

		if(n_doc > aux)
		{
			aux = n_doc;
			vet = (inicio*) malloc(sizeof(inicio)*aux);
		}

		for(i=0; i< n_doc; i++)
		{
			vet[i].next = NULL;
			vet[i].cor = branco;
		}

		for(i=0; i<n_depend; i++)
		{
			scanf("%d %d",&x, &y);
			incluir(&vet[x-1],y-1);
		}

        for(i=0; i<n_doc; i++)
		{
			if(!vet[i].next)
			{
				vet[i].cor = preto;
				continue;
			}
			if(vet[i].cor == preto) continue;
			vet[i].cor = cinza;
			if(dfs(vet,&i))
			{
				flag = 1;
				break;
			}
		}

		if(flag) printf("SIM\n");
		else printf("NAO\n");

	}
    return 0;

}





