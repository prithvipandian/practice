#include "PriorityQueue.h"
#include <algorithm>
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue() 
{
  // 0th index is kept unused to simplify calculations
  _vec.push_back(make_pair(0, ""));
}

void PriorityQueue::downHeap(int index)
{
  int left_child_index = 2 * index;
  int right_child_index = 2 * index + 1;

  int min_child_index = left_child_index;
  if (_vec[left_child_index].first > _vec[right_child_index].first && 
      right_child_index < _vec.size())
    min_child_index = right_child_index;

  if (_vec[min_child_index].first > _vec[index].first ||
      min_child_index >= _vec.size())
    return;

  swap(_vec[index], _vec[min_child_index]);
  downHeap(min_child_index);
}

void PriorityQueue::upHeap(int index)
{
  if (index == 1 || _vec[index].first > _vec[index / 2].first)
    return;

  swap(_vec[index], _vec[index / 2]);
  upHeap(index / 2);
}

void PriorityQueue::push(string element, int priority)
{
  _vec.push_back(make_pair(priority, element));
  upHeap(_vec.size() - 1);
}

string PriorityQueue::pop()
{
  string rv = _vec[1].second;
  swap(_vec[1], _vec[_vec.size() - 1]);
  _vec.pop_back();
  downHeap(1);
  return rv;
}

string PriorityQueue::top()
{
  return _vec[1].second;
}

int PriorityQueue::size()
{
  return _vec.size() - 1;
}

bool PriorityQueue::empty()
{
  return (_vec.size() <= 1);
}

int main() 
{
  PriorityQueue pq = PriorityQueue();
  pq.push("queue!", 5);
  pq.push("I", 1);
  pq.push("a", 3);
  pq.push("made", 2);
  pq.push("priority", 4);
  while (!pq.empty())
    cout << pq.pop() << " ";
  cout << "\n";  
}


