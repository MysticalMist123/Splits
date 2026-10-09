#include <bits/stdc++.h>
#define INPUT_FILE "transactions.txt"
using namespace std;

typedef struct {
	string src, dest;
	double weight;
} Edge;

void read_edges(vector<Edge>& edges) {
	ifstream file(INPUT_FILE);
	Edge e;

	while (file >> e.src >> e.dest >> e.weight) {
		edges.push_back(e);
	}

	file.close();
}

void print_edges(vector<Edge>& edges) {
	for (const Edge& e : edges) {
		cout << e.src << " pays " << e.dest << " an amount of " << e.weight << "\n";
	}
}

vector<Edge> simplify_graph(const vector<Edge>& edges) {
	// Aggregate weights for each directed edge.
	map<pair<string, string>, double> weightSum;

	for (const Edge& e : edges) {
		// Ignore self-loops.
		if (e.src == e.dest)
			continue;

		weightSum[{e.src, e.dest}] += e.weight;
	}

	vector<Edge> result;
	set<pair<string, string>> processed;

	for (const auto& entry : weightSum) {
		string u = entry.first.first;
		string v = entry.first.second;
		double w1 = entry.second;

		// Skip if this pair has already been processed.
		if (processed.count({u, v}))
			continue;

		double w2 = 0.0;

		auto it = weightSum.find({v, u});
		if (it != weightSum.end()) {
			w2 = it->second;
		}

		// Mark both directions as processed.
		processed.insert({u, v});
		processed.insert({v, u});

		double diff = abs(w1 - w2);

		// Keep the direction with the greater weight.
		if (diff > 0.0) {
			if (w1 > w2)
				result.push_back({u, v, diff});
			else
				result.push_back({v, u, diff});
		}
	}
	return result;
}

int main() {
	vector<Edge> edges;
	read_edges(edges);
	vector<Edge> s_edges = simplify_graph(edges);
	print_edges(s_edges);
	return 0;
}
