#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ifstream data ("data.txt");

struct node{
	int distance;
	int visited;
	string path;
	int last;
};

int main()
{
	int N, start;
	int a, b, w;
	data>>N;
	
	int matrix[N+1][N+1];
	struct node nodes[N+1];
		
	start = 999;
	
	cout << "Projekt iz kolegija DSTG - Matija Sabolic, Marko Srnec, Mario Selek" << endl;
	cout << "Dijkstrin algoritam" << endl << endl;
	
	if(start > N){
		cout << "Unesite pocetni vrh : ";
		cin >> start;
	}
	
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N; j++){
			matrix[i][j] = -1;
		}
		
		nodes[i].distance = -1;
		nodes[i].visited = 0;
		nodes[i].path = "-";
		nodes[i].last = -1;
	}
	
	nodes[start].distance = 0;
	
	ostringstream temp; 
	temp<<start;
	nodes[start].path=temp.str();
		
	while(!data.eof()){
		data>>a>>b>>w;
		
		matrix[a][b] = w;
		matrix[b][a] = w;
	}
	
	int x = start;
	
	cout << endl;
	
	do{
		nodes[x].visited = 1;
		
		for(int i = 1; i <=N; i++){
			if((nodes[i].visited == 0) && (matrix[x][i] != -1)){
				if((nodes[x].distance + matrix[x][i] < nodes[i].distance) || (nodes[i].distance == -1)){
					nodes[i].distance = nodes[x].distance + matrix[x][i];
					nodes[i].last = x;
				}
			}
		}
		
		int smaller = -1;
		int sw = -1;
		
		for(int i = 0; i <=N; i++){
			if((nodes[i].distance >= 0) && (nodes[i].visited == 0) && ((sw > nodes[i].distance) || (sw == -1))){
				sw = nodes[i].distance;
				smaller = i;
			}
		}
		
		if(smaller != -1){
			int last = nodes[smaller].last;
			
			ostringstream temp; 
			temp<<smaller;
			string this_node = temp.str();
			
			if(last != start){
				nodes[smaller].path = nodes[last].path + ", " + this_node;
			} else {
				ostringstream temp2; 
				temp2<<nodes[smaller].last;
				string last_node = temp2.str();
				
				nodes[smaller].path = last_node + ", " + this_node;
			}
		}
		
		x = smaller;
	}while(x != -1);
	
	for(int i=1; i<=N; i++){
		cout << "Najkraca udaljenost izmedu " << start << " i " << i << " jednaka je " << nodes[i].distance << endl;
		cout << "Put do najkrace udaljenosti je : " << nodes[i].path << endl <<endl;
	}
	
	system("pause");
	return 0;	
}
