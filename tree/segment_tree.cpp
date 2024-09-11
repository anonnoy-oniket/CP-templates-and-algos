
const int N = 2e5 + 5; // this might already be defined inside the template
vector<int> t(N);

//the tree vector t is 1 based indexed, the main vector v is 0 based indexed
// curr is the current node of the tree t (1 based indexed)
// tl and tr are the current nodes range (comes from v, 0 based indexed)

void build(vector<int> v, int curr, int tl, int tr) {

    if (tl == tr)
    {
        t[curr] = v[tl];
        return;
    }

    int l = 2 * curr, r = 2 * curr + 1;
    int mid = (tl + tr) >> 1;
    build(v, l, tl, mid);
    build(v, r, mid + 1, tr);
    t[curr] = t[l] + t[r];
}

void update(int curr, int tl, int tr, int idx, int new_val) {

    if (idx < tl || idx > tr) return;
    if (tl == tr)  // tl == tr == idx, which is the last node
    {
        t[curr] = new_val;
        return;
    }

    int l = 2 * curr, r = 2 * curr + 1;
    int mid = (tl + tr) >> 1;
    update(l, tl, mid, idx, new_val);
    update(r, mid + 1, tr, idx, new_val);
    t[curr] = t[l] + t[r];
}

int query(int curr, int tl, int tr, int i, int j) {

    if (tr < i || tl > j) return 0;
    if (tl >= i && tr <= j) return t[curr];

    int l = 2 * curr, r = 2 * curr + 1;
    int mid = (tl + tr) >> 1;
    return query(l, tl, mid, i, j) + query(r, mid + 1, tr, i, j);
}











int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];


    build(v, 1, 0, n - 1);
    update(1, 0, n - 1, 3 , 2);
    int ans = query(1, 0, n - 1, 2, 4);

    for (int i = 1; i < 4 * n; i++) cout << t[i] << " ";
    cout << endl << ans;

    return 0;
}
