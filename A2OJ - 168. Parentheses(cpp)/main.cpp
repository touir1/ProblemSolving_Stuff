#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
#define BE(x) x.begin(),x.end()
using namespace std;
const int oo=1e9;
const int MAX=1010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<string,string> ss;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

void printParentheses(int open,int close,string s){
    if(open>close)
        return;
    if(close<0 || open < 0)
        return;
    if(close == open && close ==0)
        cout << s << endl;
    printParentheses(open-1,close,s+"(");
    printParentheses(open,close-1,s+")");
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    printParentheses(n,n,"");
    return 0;
}
