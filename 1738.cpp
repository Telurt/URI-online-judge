#include <bits/stdc++.h>
#include <stdio.h>



using namespace std;


typedef struct noh
{
	bool vet[26];
}noh;


void zerar(bool vet[26])
{
	int i;
	for(i=0;i<26;i++) vet[i] = false;
}



void intercesao(bool a[26], bool b[26], bool c[26])
{
	int i;
	for(i=0;i<26;i++)
	{
		if(b[i] && c[i]) a[i] = true;
	}
}



int main()
{
	int k,i,j, cont, n, a, b;
	string str;
	string::iterator it;
	
	while(1)
	{
		cin >> n;
		if(!n) return 0;
		
		vector<noh>mat(n*n);	
		for(i=0;i<n*n;i++) zerar(mat[i].vet);
		
		
			
		while(1)
		{
			cin >> a;
			cin >> b;
						
			if(!a && !b) break;
			
			a--;	b--;
			
			cin >> str;
			it = str.begin();
			for(;it!=str.end();it++)
			{
				mat[a*n+b].vet[*it-97] = true;
			}				
		}
		
		
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				if(i==k) continue;
				for(j=0;j<n;j++)
				{
					if(j==k	||  j==i) continue;
					intercesao(mat[i*n+j].vet, mat[i*n+k].vet, mat[k*n+j].vet);
				}
			}
		}
			
												
		
		while(1)	// Pegar as consultas
		{
			cin >> a;
			cin >> b;
			
			if(!a	&&	!b) break;
			
			a--;	b--;
			
			cont=0;
				
			for(i=0;i<26;i++)
			{
				if(mat[a*n+b].vet[i])
				{
					printf("%c",'a'+i);
					cont++;
				}	
			}
			
			if(cont) printf("\n");
			else printf("-\n");
						
		}										
								
		cout << endl;
	}