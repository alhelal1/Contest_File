/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

#define MX 2
long double mul_res[MX][MX];
void multiply(long double a[][MX], long double b[][MX]){
    set0(mul_res);
    for(int i = 0; i < MX; i++){
        for(int j = 0; j < MX; j++){
            for(int k = 0; k < MX; k++){
                mul_res[i][j] = (mul_res[i][j] + a[i][k] * b[k][j]);
        	}
        }
    }
}

long double big_res[MX][MX];
long double init[MX][MX];
void matrix_expo(LL n){
    if(n == 0){
        set0(big_res);
        REP(i, MX)big_res[i][i] = 1;
        return;
    }
    if(n % 2 == 0){
        matrix_expo(n / 2);
        multiply(big_res, big_res);
        REP(i, MX){
            REP(j, MX)big_res[i][j] = mul_res[i][j];
        }
    }
    else {
        matrix_expo(n - 1);
        multiply(big_res, init);
        REP(i, MX){
            REP(j, MX)big_res[i][j] = mul_res[i][j];
        }
    }
}


int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    FOR(ts, 1, T+1){
        int n; cin >> n;

        long double Wa, Wb, La, Lb;
        cin >> Wa >> Wb >> La >> Lb;

        if(La > Lb){
            init[0][0] = La; init[0][1] = 1.0 - La;
            init[1][0] = Lb; init[1][1] = 1.0 - Lb;
        } else {
            init[0][0] = 1.0 - La; init[0][1] = La;
            init[1][0] = 1.0 - Lb; init[1][1] = Lb;
        }

        cout << "Case #" << ts << ": ";

        if(n == 1){
            cout << fixed << setprecision(10) << Wa << endl;
            continue;
        }

        matrix_expo(n-2);
        long double p1 = big_res[0][0], p2 = big_res[0][1];

        if(Wa > Wb) swap(Wa, Wb);

        long double res = (p1*La + p2*Lb)*Wb;
        res += (p1 * (1.0-La) + p2 * (1.0 - Lb)) * Wa;


        cout << fixed << setprecision(10) << res << endl;
    }
}

