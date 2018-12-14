#include <iostream>
#include <queue>
#include <map>
#include <list>

using namespace std;

class permutation {
	public:
		string vertice = "";
		int dist = 1000000000;
		bool visited = false;
};

int n = 0;
int cost[7][7];

bool operator<(const permutation& per1, const permutation& per2) {
	return per1.dist < per2.dist;
}

bool operator> (const permutation&per1, const permutation& per2) {
	return per1.dist > per2.dist;
}

int transCost(string u, string v) {
	int index1 = -1;
	int index2 = -1;
	
	for (int i=0; i<u.length(); i++) {
		if (u[i] != v[i]) {
			if (index1!=-1) index2 = i;
			else index1 = i;
		}
	}
	return cost[u[index1]-48-1][u[index2]-48-1];
}

list<string> getNeighbors(string s) {
	list<string> neighbors;
	string temp;
	for (int i=0; i<s.length(); i++) {
		for (int j=0; j<s.length(); j++) {
			temp = s;
			if (i!=j) {
				char c = temp[i];
				temp[i] = temp[j];
				temp[j] = c;
				neighbors.push_back(temp);
			}
		}
	}
	return neighbors;
}

void update(permutation u, permutation v) {
	int distance = transCost(u.vertice, v.vertice);
	if (v.dist > u.dist + distance) {
		v.dist = u.dist + distance;
	}
}

void dijkstra(string input, string output) {
	priority_queue<permutation, vector<permutation>, less<vector<permutation>::value_type>> queue;
	list<string> inTheQueue;
	map<string, permutation> map;
	
	permutation root;
	
	root.vertice = input;
	root.dist = 0;
	root.visited = true;
	
	map.insert(pair<string, permutation> (input, root));
	
	queue.push(root);
	
	while (!queue.empty()) {
		permutation smallest = queue.front();
		queue.pop();
		smallest.visited = true;
		if (!queue.empty()) {
			while (queue.front().vertice==smallest.vertice) queue.pop();
		}
		
		list<string> neighbors = getNeighbors(smallest.vertice);
		list<string>::iterator it;
		for (it=neighbors.begin(); it!=neighbors.end(); ++it) {
			permutation newNode;
			if (map.count(*it) == 0) {
				newNode.vertice = *it;
				map.insert(pair<string, permutation> (*it, newNode));
			} else{
				map<string, permutation>::iterator iter;
				iter = map.find(*it);
				newNode = *iter;
			}
			
			if (!newNode.visited) {
				update(smallest, newNode);
				bool found = (find(inTheQueue.begin(), inTheQueue.end(), newNode.vertice));
				if (!found) {
					queue.push(newNode);
					inTheQueue.push_back(newNode.vertice);
				}
				permutation adjust;
				adjust.dist = -1000000000;
				queue.push(adjust);
				queue.pop();
			}
		}
	}
	cout << map[output];
}

int main() {
	string s, input, output;
	
	cin >> s;
	for (int i=0; i<s.length(); i++) {
		if (s[i]!=" ") {
			n++;
			input+=s[i];
			output+=(i+1);
		}
	}	
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) 
			cin >> cost[i][j];
	}
	
	dijkstra(input, output);
	return 0;
}
