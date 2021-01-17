# #include <iostream>
# #include <vector>
# #include <algorithm>
# #include <stack>
# using namespace std;
# #define l(i,s,n) for(int i=s;i<n;++i)
# #define ll long long
# int main()
# {
#     int n;
#     cin >> n;
#     vector<float> a(n);
#     l(i, 0, n) cin >> a[i];
#     stack<pair<float, float>> st;
#     st.push({a[0], 1});
#     l(i, 1, n)
#     {
#         float val = a[i], cnt = 1;
#         while (!st.empty() && st.top().first * cnt >= val * st.top().second)
#         {
#             val += st.top().first;
#             cnt += st.top().second;
#             st.pop();
#         }
#         st.push({val, cnt});
#     }
#     vector<pair<float, float>> f;
#     while(!st.empty())
#     {
#         f.emplace_back(st.top().first, st.top().second);
#         st.pop();
#     }
#     reverse(f.begin(), f.end());
#     for(auto p : f) {
#         l(i, 0, p.second) printf("%.11f\n", p.first / p.second);
#     }
# }


n = int(input())
a = list(map(int, input().split()))

st = [(a[0], 1)]

for i in range(1, n):
    val, cnt = a[i], 1
    while st and st[-1][0] * cnt >= val * st[-1][1]:
        p, q = st.pop()
        val += p
        cnt += q
    st.append((val, cnt))

print(''.join(['{:.9f}\n'.format(val / cnt) * cnt for val, cnt in st]))

# for val, cnt in st:
#     for i in range(cnt): print(val / cnt)
