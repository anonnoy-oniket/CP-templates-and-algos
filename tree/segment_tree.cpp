const int maxN = 1e5 + 9;
long long a[maxN], t[4 * maxN];

void build(int curr, int b, int e) {
    if (b == e) {
        t[curr] = a[b];
        return;
    }
    int mid = (b + e) >> 1, l = 2 * curr, r = (2 * curr) + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    
    t[curr] = t[l] + t[r]; // change comes here
}


void update(int curr, int b, int e, int i, int new_val) {
    if (i<b || i>e) {
        return;
    }
    if (b == e) {
        t[curr] = new_val;
        return;
    }
    int mid = (b + e) >> 1, l = 2 * curr, r = (2 * curr) + 1;
    update(l, b, mid, i, new_val);
    update(r, mid + 1, e, i, new_val);
    
    t[curr] = t[l] + t[r]; // change comes here
}


long long query(int curr, int b, int e, int i, int j) {
    if (e < i || j < b) {
        return 0;  // change comes here
    }
    if (b >= i && e <= j) {
        return t[curr];
    }
    int mid = (b + e) >> 1, l = 2 *curr, r = (2 * curr) + 1;
    
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j); // change comes here
}











int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];


    build(1, 0, n - 1);
    update(1, 0, n - 1, 3 , 2);
    int ans = query(1, 0, n - 1, 2, 4);

    for (int i = 1; i < 4 * n; i++) cout << t[i] << " ";
    cout << endl << ans;

    return 0;
}
