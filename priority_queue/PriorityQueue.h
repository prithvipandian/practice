#include <vector>
#include <string>
#include <utility>

using namespace std;

class PriorityQueue
{
private:
  void downHeap(int index);
  void upHeap(int index);
  vector<pair<int, string> > _vec;

public:
  PriorityQueue();
  void push(string element, int priority);
  string top();
  string pop();
  int size();
  bool empty();
};



