#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

using namespace std;

int count_inversion_merge(int array[], int first, int last)
{
    int mid = (first+last)/2;
    int ai = first;
    int bi = mid+1;
    int final[last-first+1], finali=0;
    int inversion = 0, i;

    while (ai <= mid && bi <= last) {
        if (array[ai] <= array[bi]) {
                final[finali++] = array[ai++];
        } else {
                final[finali++] = array[bi++];
                inversion += mid - ai + 1;
        }
    }

    while (ai <= mid)
        final[finali++] = array[ai++];

    while (bi <= last)
        final[finali++] = array[bi++];

    for (i=0 ; i<last-first+1 ; i++)
        array[i+first] = final[i];

    return inversion;
}

int count_inversion(int array[], int a, int b)
{
    int x, y, z, mid;
    if (a >= b) return 0;

    mid = (a+b)/2;

    x = count_inversion(array, a, mid);
    y = count_inversion(array, mid+1, b);
    z = count_inversion_merge(array, a, b);

    return x+y+z;
}

int main()
{
    int a[100000];
    int len = 0,tmp;
    int i;
    int inversion;
    int N;
    scanf("%d",&N);
    for(int j=0;j<N;j++){
        memset(a,0,sizeof(int)*100000);
        scanf("%d",&len);
        for(int k=0;k<len;k++)
            scanf("%d",&a[k]);
        inversion = count_inversion(a, 0, len-1);
        printf("%d\n",inversion);
    }
}
