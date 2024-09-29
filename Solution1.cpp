#include <bits/stdc++.h>
using namespace std;

struct phanSo
{
    /* data */
    int tuSo, mauSo;
};

void solve(phanSo p)
{
    int hi = __gcd(p.mauSo,p.tuSo);
    p.tuSo/=hi;
    p.mauSo/=hi;
    if (p.mauSo == 1) cout<<p.tuSo;
    else{
        cout<<p.tuSo<<"/"<<p.mauSo;
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    if (b==0)
    {
        cout<<"Phan so khong hop le";
    }
    else {
        phanSo p;
        p.tuSo = a;
        p.mauSo = b;
        solve(p);
    }

}