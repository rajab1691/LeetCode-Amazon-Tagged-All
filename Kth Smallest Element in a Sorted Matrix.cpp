/*
    **At any point if you see Kth then we can always apply HEAP.**
  
  Prob: Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
*/

/*
  Brutest Idea: push all element into vector, sort that and return v[k-1]th element.
  
  1. Using max-heap
    a.Push all elements into max heap and then pop (k-1) element.
    b.return top element now.
    T.C-O(n*m*log(m*n))
    S.C-O(n*m)
*/

/*
  2. Using min-heap
    a. Idea is from merge k sorted array problem.
    b. Push the (1st element,r,c) of min(n,k) rows, into min-heap.
    c. then run a loop till k times pop element from heap and push its next column element into heap.
    
    T.C-O(k*logk)
    S.C-O(k)
*/
int kthSmallest(vector<vector<int>>&a, int k) {

  int n = a.size();
  priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;

  for (int i = 0; i < min(n, k); i++) {
   int kthSmallest(vector < vector < int >> & a, int k) {

  int n = a.size();
  priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;

  for (int i = 0; i < min(n, k); i++) {
    pq.push({a[i][0],i,0});
  }
  int ans;
  for (int i = 1; i <= k; i++) {
    auto top = pq.top();
    pq.pop();
    ans = top[0];
    int r = top[1];
    int c = top[2];

    if (c + 1 < n)
      pq.push({a[r][c+1],r,c+1});
  }
  return ans;
}
  }
  int ans;
  for (int i = 1; i <= k; i++) {
    auto top = pq.top();
    pq.pop();
    ans = top[0];
    int r = top[1];
    int c = top[2];

    if (c + 1 < n)
      pq.push({a[r][c+1],r,c+1});
  }
  return ans;
}

/*
  3. Binary Search
    a. Apply binary search on number range.
    b. so l=a[0][0] and h=a[n-1][n-1]
    c. if count of numbers(less than equal to mid) present in matrix is >= k,then check on left side
    d. else check on right side
    
    T.C-O((m+n)*logD), D=difference
    S.C-O(1)
*/

int count(vector<vector<int>>&a, int range) {
  int n = a.size();
  int cnt = 0;

  int col = n - 1;

  for (int i = 0; i < n; i++) {

    while (col >= 0 and a[i][col] > range) col--;

    cnt += (col + 1);
  }
  return cnt;
}
int kthSmallest(vector<vector<int>>&a, int k) {
  int n = a.size();

  int l = a[0][0];
  int h = a[n - 1][n - 1];
  int ans;
  while (l <= h) {

    int mid = l + (h - l) / 2;

    if (count(a, mid) >= k) {
      /*update ans and check in right bcuz we're checking on range so
      maybe that no is not in matrix so that's why check for available num*/
      ans = mid;
      h = mid - 1;

    } else {
      l = mid + 1;
    }
  }
  return ans;
}
