const int maxN = 1e5 + 9;
long long a[maxN], t[maxN * 4], lazy[maxN * 4];

void push(int curr, int b, int e) {
   if (lazy[curr] == 0) {
      return;
   }
   
   t[curr] += (1LL * (e - b + 1) * lazy[curr]); // change here
   
   if (b != e) {
      int l = (2 * curr), r = (2 * curr) + 1;
      lazy[l] += lazy[curr]; //change here
      lazy[r] += lazy[curr]; //change here
   }
   lazy[curr] = 0;
}

void build(int curr, int b, int e) {
   if (b == e) {
      t[curr] = a[b];
      return;
   }
   int mid = (b + e) / 2, l = (2 * curr), r = (2 * curr) + 1;
   build(l, b, mid);
   build(r, mid + 1, e);
   
   t[curr] = t[l] + t[r]; // change here
}

void update(int curr, int b, int e, int i, int j, int v) {
   push(curr, b, e);
   if (e < i || j < b) {
      return;
   }
   if (b >= i && e <= j) {
      lazy[curr] = v;
      push(curr, b, e);
      return;
   }
   int mid = (b + e) / 2, l = (2 * curr), r = (2 * curr) + 1;
   update(l, b, mid, i, j, v);
   update(r, mid + 1, e, i, j, v);
   
   t[curr] = t[l] + t[r]; // change here
}

long long query(int curr, int b, int e, int i, int j) {
   push(curr, b, e);
   if (e < i || j < b) {
      return 0; // change here
   }
   if (b >= i && e <= j) {
      return t[curr];
   }
   int mid = (b + e) / 2, l = (2 * curr), r = (2 * curr) + 1;
   
   return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j); // change here
}
