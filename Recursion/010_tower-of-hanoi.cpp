// 10.
// Tower Of Hanoi
// https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1 
// YT : https://www.youtube.com/watch?v=FfUE6gtqOB4

class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 0) return 0; // handle the case when n == 0

        if (n == 1) {
            // cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
            return 1;
        }

        int count = towerOfHanoi(n - 1, from, aux, to);

        // cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        count += 1;

        count += towerOfHanoi(n - 1, aux, to, from);
        return count;
    }
};
