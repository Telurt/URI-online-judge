#include <bits/stdc++.h>


using namespace std;


int n_ling=1;



typedef struct ling		
{
	string lingua;
	int num;
}ling;



typedef struct aresta
{
	int num;
	int tam;
	char ch;
	
}aresta;


typedef struct noh
{
	int dist;
	char ch;
	int ant;
	int num;
}noh;









void increm(string str, list<ling> &lista)
{
	ling novo;
	novo.lingua = str;
	novo.num = n_ling;
	
	
	lista.insert(lista.begin(),novo);	
}


int procurar(string str, list<ling> &lista)
{
	list<ling>::iterator it;
	
	for(it=lista.begin(); it != lista.end(); it++)
	{
		if(!(it->lingua.compare(str))) return it->num;
	}
	
	increm(str,lista);
	n_ling++;
	return n_ling-1;		
	
	
}




void inserir_hash(vector<list<aresta> > &hash, int a, int b, char ch, int tam)
{
	list<aresta>::iterator it;		
	
	aresta noh;
	noh.num = b;
	noh.ch = ch;
	noh.tam = tam;
	
	it = hash[a].begin();
	if(it == hash[a].end()) 
	{
		hash[a].insert(it,noh);		
	}			
	
	else
	{
		while(tam > it->tam && it!=hash[a].end()) it++;		
		hash[a].insert(it,noh);		
	}
	
	
	
	aresta noh1;
	noh1.num = a;
	noh1.ch = ch;
	noh1.tam = tam;
	it = hash[b].begin();
	if(it == hash[b].end()) 
	{
		hash[b].insert(it,noh1);		
	}			
	else
	{
		while(tam > it->tam && it!=hash[b].end()) it++;		
		hash[b].insert(it,noh1);		
	}
	
}
	





void excluir_noh(list<noh> &fila, int dist, char ch, int num)
{
		
	list<noh>::iterator it;
	it = fila.begin();
	
	while(it != fila.end())
	{
		if((it->dist == dist) && (it->ch == ch) && (it->num == num))
		{
			fila.erase(it);
			return;
		}
		it++;
	}
	
}





int inserir_noh(list<noh> &fila, list<noh> &excluidos, int sign, int dist, char ch, int num)
{
	list<noh>::iterator jt;
	
	if(sign)
	{	
		
		for(jt = excluidos.begin(); jt != excluidos.end(); jt++)
		{
	
			if((jt->num == num) && (jt->ch == ch))
			{
	
				return 0;
			}
		}
		
		
		for(jt = fila.begin(); jt != fila.end(); jt++)
		{
			if((jt->num == num) && (jt->ch == ch))
			{
				if(dist < jt->dist)
				{
					excluir_noh(fila, jt->dist, ch, num);
					inserir_noh(fila, excluidos,0, dist, ch, num);				
				}
				return 0;
			}
		}
	}
	
	
	noh novo;
	novo.dist = dist;
	novo.ch = ch;
	novo.num = num;	
	
	
	
	
	jt = fila.begin();
	
	while(jt!=fila.end() && jt->dist < dist) jt++;
	
	fila.insert(jt,novo);
	
	return 0;
}








int dijkstra(vector<list<aresta> > &hash, int source, int target)
{
	list<aresta>::iterator it;
	list<noh> ativos;	// distancia e indice
	list<noh> excluidos;	// distancia e indice
	list<noh>::iterator jt;	
	
	
	noh novo;
	novo.dist = 0;
	novo.ch = ' ';
	novo.num = source;	
	
	
	ativos.insert(ativos.begin(),novo);	
	
		
	int pivot,dist;
	
	while(!ativos.empty())
	
	{	
		pivot = ativos.begin()->num;
		
		if(pivot == target)
		{
			cout << ativos.begin()->dist << endl;				
			return 0;			
		}
		
	
		
		jt = ativos.begin();
		it = hash[pivot].begin();
				
		for(;it!=hash[pivot].end();it++)
		{
			if(it->ch == jt->ch)
			{	
				continue;
			}
			else
			{
				dist = it->tam+jt->dist;
			}				
				inserir_noh(ativos,excluidos,1,dist,it->ch,it->num);							
			
		}
		jt++;
		excluidos.insert(excluidos.begin(),ativos.begin(),jt);
	
		
		ativos.erase(ativos.begin());		
	}
	
	cout << "impossivel\n";
	return 0;
	
	
	
}






int main()
{
	int i,m,a,b;
	string ini, fim, str1, str2, str3;
	
	while(1)
	{
		n_ling = 1;
		cin >> m;	
		if(!m) break; 
		
		cin >> ini >> fim;
		
		list<ling> lista;
		
		vector<list<aresta> > hash(m*2+1);
		
		
		for(i=0;i<m;i++)
		{
			cin >> str1 >> str2 >> str3;
			a = procurar(str1,lista);
			b = procurar(str2,lista);
			
			
			
			inserir_hash(hash, a, b, str3[0], str3.size());						
			
		}
		
			
		
	
		
	
	
		i = n_ling;
		a = procurar(ini,lista);
		b = procurar(fim,lista);
		
		if(i<n_ling)
		{
			cout << "impossivel\n";		
			continue;	
		}
		
		dijkstra(hash, a, b);			
			
	}
	
	return 0;							
	
}