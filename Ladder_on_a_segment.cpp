#include <bits/stdc++.h>

using namespace std;

#define ll long long	
#define pb push_back
#define bug cout << "bug" << endl
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pll pair <ll, ll> 
#define pii pair <int, int> 
#define triple pair <pair <ll, ll> , ll>   
#define ull unsigned long long
#define ld long double
#define pinode pair <node*, node*>

const ll INF = 9e18 + 5;
const ll inf = 1e9 + 5;
const ll N = 2e5 + 5;
const ll shift = 2e6;
const ll mod = 998244353;
const ll mod2 = 1e9 + 9;
const ll M = 1e3 + 5;
const ll LOG = 21;
const ll sp = 263;
const ll sp2 = 9973;
const int block = 100;
const double eps = 1e-10;

ll n, t[N * 4], add[N * 4], lads[N * 4], a[N], q;

void push(int v, int tl, int tr){
	if(add[v] == 0 && lads[v] == 0)
		return;
	ll tm = (tl + tr) / 2;
	ll len = tr - tl + 1;
	t[v] += (add[v] * 1ll * len) + (len * 1ll * (len + 1) / 2ll) * 1ll * lads[v];
	if(tl != tr) {
		add[v * 2] += add[v];
		add[v * 2 + 1] += (add[v] + (tm - tl + 1) * 1ll * lads[v]);
		lads[v * 2] += lads[v];
		lads[v * 2 + 1] += lads[v];
	}
	add[v] = 0;
	lads[v] = 0;
}

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

void upd(int v, int tl, int tr, int l, int r){
	push(v, tl, tr);
	if(tl >= l && tr <= r){
		lads[v] += 1;
		add[v] += (tl - l);
//		cout << "F " << tl << " " << tr << " " << lads[v] << endl;
		push(v, tl, tr);	
		return;
	}
	if(tl > r || tr < l)
		return;
	int tm = (tl + tr) / 2;
	upd(v * 2, tl, tm, l, r);
	upd(v * 2 + 1, tm + 1, tr, l, r);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

ll get(int v, int tl, int tr, int l, int r){
	push(v, tl, tr);
	if(tl >= l && tr <= r)
		return t[v];
	if(tl > r || tr < l)
		return 0;
	int tm = (tl + tr) / 2;
	ll q1 = get(v * 2, tl, tm, l, r);
	ll q2 = get(v * 2 + 1, tm + 1, tr, l, r);
	return q1 + q2;
}

int main(){
	speed;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	while(q--){
		int type, l, r;
		cin >> type >> l >> r;
		if(type == 1){
			upd(1, 1, n, l, r);
		}else{
			cout << get(1, 1, n, l, r) << endl;
		}
	}
}
/*	
%I64d6


5 4
0 0 0 0 0
1 3 5
2 1 5
1 1 5
2 1 5



%I64d
*/ 
