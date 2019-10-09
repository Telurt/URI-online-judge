#include <bits/stdc++.h>


using namespace std;

int buscar(char in[], int ini, char letra)
{
	for(int i=1;; i++)
	{
		if(in[i] == letra) return i;
	}
}


void posifica(char pre[], char in[], char pos[], int *i, int ini, int fim, int *cont)
{
	int meio, qtd;
	char ch = pre[*i];
	(*i)++;
	meio = buscar(in,ini,ch);	
	qtd = meio-ini;		
	if(qtd) 
		posifica(pre,in,pos,i,ini,meio-1,cont);
	
	qtd = fim-meio;	
	if(qtd) 
		posifica(pre,in,pos,i,meio+1,fim,cont);
	
	pos[*cont] = ch;
	(*cont)++;
	
}


int main()
{
	
	ios_base::sync_with_stdio(false);
	
	
	int c;
	cin >> c;
	
	int n;
	for(int k=0; k<c; k++)
	{
		cin >> n;
		
		int cont = 1, i = 1, ini = 1, fim = n;
		
		char ch, pre[n+1], in[n+1], pos[n+1];
		
		for(int j=1; j<=n; j++) cin >> pre[j];
		
		for(int j=1; j<=n; j++) cin >> in[j];
		
	
		
	posifica(pre, in, pos, &i, ini, fim, &cont);
		
		for(int j=1; j<=n; j++) cout << pos[j];
		cout << endl;
		
	}
	
	
	return 0;		
}
