#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef unsigned long long ll;

typedef struct {
  int time;
  int direction;
} Person;

int calculteIntervalTime(int *index, vector<Person> l) {
  int i = *index;
  if (l[i + 1].time - l[i].time < 10) {
    i++;
  }
  *index = i;

  return l[i].time - l[*index].time + 10;
}

int calculateEndTime(vector<Person> list1, vector<Person> list2) {
  int i, j = 0;
  int totalTime = list1[0].time;
  bool isWait = false;

  while (i < list1.size() || j < list2.size()) {
    if (list1[i].time < list2[j].time) {
      totalTime += calculteIntervalTime(&i, list1);
      int difference = list1[i + 1].time - list1[i].time;
      while (list1[i].time < list2[j].time && difference > 10) {
        totalTime += (totalTime - difference);
        i++;
      }
    } else {
      totalTime += calculteIntervalTime(&j, list2);
    }
  }

  return totalTime;
}

int main() {
  int n;
  cin >> n;

  vector<Person> d0;
  vector<Person> d1;

  for (int i = 0; i < n; i++) {
    Person p;
    cin >> p.time >> p.direction;
    if (p.direction == 0) {
      d0.push_back(p);
    } else {
      d1.push_back(p);
    }
  }

  if (d0[0].time < d1[0].time) {
    calculateEndTime(d0, d1);
  } else {
    calculateEndTime(d1, d0);
  }
}
