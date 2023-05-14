#include <stdio.h>
int main() {
  int n,         // number of problems
      view,      // the view of each student (can he/she solve it)
      views_sum, // the number of students who can solve a problem (0 to 3);
      // the number of problems that can be solved (a problem is solvable
      // if at least 2 students know how to solve it)
      solved_count = 0;
  scanf("%d", &n);
  // there are n problems in total. can replace with for loop
  while (n--) {
    // for this problem start with 0 students knowing the solution
    views_sum = 0;
    // there are 3 students, each has a view wether they can solve the problem
    // or not
    for (int i = 0; i < 3; i++) {
      // scan the view of one student
      scanf("%d", &view);
      // sum how many students know the solution
      views_sum += view;
    }
    if (views_sum >= 2)
      // if 2 or more students know the solution to this
      // problem, count this
      // problem as solvable
      solved_count++;
  }
  // how many problems can the students solve
  printf("%d", solved_count);
  return 0;
}