#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define INF \
  INT_MAX  // Used to set the distance of unreachable nodes to infinity

struct Pair {  // Create Pair
  int first;
  int second;
};
class Queue {
  vector<Pair> data;

 public:
  Queue() {              // Constructor for empty queue
    this->data.clear();  // Empty the vector incase it is not empty
  }

  int size() { return this->data.size(); }

  bool isEmpty() { return (size() == 0); }

  void enqueue(Pair element) { this->data.push_back(element); }

  Pair dequeue() {
    Pair top_element = this->data[0];
    this->data.erase(data.begin());
    return top_element;
  }
};

int n, m;
vector<vector<int>> grid;
vector<vector<int>> time_to_infection;
Queue q;

bool isValid(int x, int y) {
  return (((x >= 0) && (x < n)) && ((y >= 0) && (y < m)) &&
          (grid[x][y] != 0));  // Vaccinated person does not spread the disease
}

void bfs() {
  while (!q.isEmpty()) {
    Pair p = q.dequeue();
    int x = p.first, y = p.second;

    // Queue up all valid neighbours of the current node. Using if queues all 4
    // neighbours in one iteration
    if (isValid(x - 1, y) && time_to_infection[x - 1][y] == INF) {
      time_to_infection[x - 1][y] = min(time_to_infection[x][y] + 1, time_to_infection[x - 1][y]);
      q.enqueue({x - 1, y});
    }
    if (isValid(x + 1, y) && time_to_infection[x + 1][y] == INF) {
      time_to_infection[x + 1][y] = time_to_infection[x][y] + 1;
      q.enqueue({x + 1, y});
    }
    if (isValid(x, y - 1) && time_to_infection[x][y - 1] == INF) {
      time_to_infection[x][y - 1] = time_to_infection[x][y] + 1;
      q.enqueue({x, y - 1});
    }
    if (isValid(x, y + 1) && time_to_infection[x][y + 1] == INF) {
      time_to_infection[x][y + 1] = time_to_infection[x][y] + 1;
      q.enqueue({x, y + 1});
    }
  }
}

int main() {
  cin >> n >> m;

  grid.resize(n, vector<int>(m));
  time_to_infection.resize(n, vector<int>(m, INF));

  // Queue all initially infected nodes while taking input
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];

      if (grid[i][j] == 2) {
        q.enqueue({i, j});
        time_to_infection[i][j] =
            0;  // Distance of infected node from itself is 0
      }
    }
  }

  bfs();  // Fills in distance of node from nearest infected node for all
          // nodes

  int time_needed = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        time_needed = max(time_needed, time_to_infection[i][j]);

        if (time_to_infection[i][j] ==
            INF) {  // If any healthy node is present, print -1
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  cout << time_needed << endl;
  return 0;
}
