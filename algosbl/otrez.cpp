#include<iostream>
#include<vector>

int main()
{
    int n;
    int k;
    std::cin >> n >> k;

    std::vector <int> mas(n);
    for (int i = 0; i < n + 1; ++i)
    {
        std::cin >> mas[i];
    }

    std::vector <int> sp(n);
    for (int i = 0; i < n; ++i)
    {
        sp[i] += 1;
    }

    std::vector <int> sp_sum(k);
    sp_sum[0] = sp[0];
    for (int i = 1; i < k; ++i)
    {
        sp_sum[i] = sp_sum[i-1] + sp[i];
    }

    int q;
    std:: cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        std:: cin >> l >> r;
        l = std::max(0, l);
        r = std::min(r, k);
        std::cout << sp_sum[r] - sp_sum[l];
    }
}