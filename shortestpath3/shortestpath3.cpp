#include <bits/stdc++.h>
#define int long long
#define P(x) {if (debug) cout << x << endl;}
#define H(x) P(#x << ": " << (x))
#define FR(i,a,b) for (int i=(a); i<(b); i++)
#define F(i,n) FR(i,0,n)
#define D(i,n) for (int i=(n); i-->0;)
#define S(s) (int)(s).size()
#define ALL(v) v.begin(), v.end()
#define MI(a,v) a = min(a,v)
#define V vector
#define pb push_back
#define mt make_tuple
using namespace std;
template<class T> ostream& operator<<(ostream& os, V<T> v) {
    F(i,S(v)) os<<(i?" ":"")<<v[i]; return os;}
const bool debug = 1;
const int INF = 1e15;

struct edge {int v,d;};

signed main() {
    int n,m,q,s;
    while (cin>>n>>m>>q>>s, n||m||q||s) {
        V<V<edge>> g(n);
        F(i,m) {
            int a,b,d; cin>>a>>b>>d;
            g[a].pb({b,d});
        }
        V<int> dist(n, INF), mid;
        dist[s] = 0;
        F(step,4*n+5) { // 2*n should be enough but let's be extra safe
            if (step == n) mid = dist; // capture the distance after n passes
            F(u,n) if (dist[u] != INF) for (edge e : g[u])
                MI(dist[e.v], dist[u] + e.d);
        }
        F(u,n) if (dist[u] != mid[u]) {// distance is -INF iff the distance changed afterwards
            assert(dist[u] < mid[u]);
            dist[u] = -INF;
        }
        F(i,q) {
            int t; cin>>t;
            if (dist[t] == INF) cout<<"Impossible\n";
            else if (dist[t] == -INF) cout<<"-Infinity\n";
            else cout<<dist[t]<<"\n";
        }
        cout<<"\n";
    }
}
