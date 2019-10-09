#include <bits/stdc++.h>

using namespace std;

// function for mdc

int mdc(int n1, int n2)
{
	int resto= n1%n2;
    while(resto)
       {
        n1    = n2;
        n2    = resto;
        resto = n1%n2;         
       }
     return n2;
}


// principal function

int main()
{
	
	int aux,a,b,i, n_vert, n_arest;
	
	cin >> n_vert >> n_arest;
	
	
				
	vector<set<int> >hash(n_vert+1); 
	int peso[n_vert+1];
	list<pair<int,int> >pilha;
	set<int> qtd_k;
	vector<set<int> >registro(n_vert+1);
	
	
	
	for(i=1;i<=n_vert;i++) 
	{
		cin >> aux;
		peso[i] = aux;
		qtd_k.insert(aux);	
		registro[i].insert(aux);
		pilha.insert(pilha.begin(),make_pair(i,aux));
	}
	
	for(i=0;i<n_arest;i++)
	{
		cin >> a >> b;
		hash[a].insert(b);
		hash[b].insert(a);		
		
	}
	
	
	set<int>::iterator it;
	
	while(!pilha.empty())
	{
		a = pilha.begin()->first;
		b = pilha.begin()->second;
		pilha.erase(pilha.begin());	
		
		it = hash[a].begin();
		for(;it!=hash[a].end();it++)
		{
			aux = mdc(b,peso[*it]);
			if(registro[*it].find(aux) == registro[*it].end())
			{
			registro[*it].insert(aux);
			qtd_k.insert(aux);			
			pilha.insert(pilha.begin(),make_pair(*it,aux));
			}	
		} 
	}
	
	cout << qtd_k.size() << endl;				
	
}