#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
임의의 원을 2개 골랐을때 교점이 존재하면 안된다.

1. 원의 중점이 다르다면, |x1-x2| > r1+ r2
2. 원의 중점이 같다면, r1 != r2

비교를 어떻게 할까? 하나씩 비교 O(n*n) -> 1초 넘음
 */

/*
답 보고 푼다

저장해야할 정보 : 좌표, isOpen, 원의 번호

vector에 저장한다
스택에 넣고 비교

원의 번호가 필요한 이유?
같은 원의 isOpen, isClose인지 알아야하니까 -> 다른 원이지만, 좌표, isClose|| isOpen 같을 수 있다

1. 구조체 형인 vector 생성, 오름차순으로 정렬
- 좌표가 같다면 아묻따 교점있다 -> return >> NO 출력
2. isOpen인 구조체만 stack에 push -> id만 넣는다
3. isClose라면 스택 top과 비교 같은 원(id)이라면 pop
4. 아니라면 return >> NO 출력
5. 스택이 empty라면 ->  YES 출력

*/

struct info
{
    int pos, is_open, id;
};

vector<info> v;
stack<int> s;

int comp(info &a, info &b)
{
    return a.pos < b.pos;
}

int sol()
{

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1].pos == v[i].pos)
        {
            return 0;
        }
    }
    // 하나씩 해야하니까
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].is_open)
        {
            // 열려있다면
            s.push(v[i].id);
        }
        else if (v[i].id == s.top())
        {
            // 닫혀있다면
            // 원의 번호, 현재 스택에 있는 원의 번호 비교
            s.pop();
        }
        else
        {
            // 원의 id가 다르다면 원끼리 교점이 생긴다
            return 0;
        }
    }

    return 1;
    // 스택이 empty라면
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, r;
        cin >> x >> r;

        v.push_back({x - r, 1, i});
        v.push_back({x + r, 0, i});
    }

    // 다 넣고 난 후 정렬
    sort(v.begin(), v.end(), comp);

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].pos << v[i].is_open << v[i].id << "\n";
    // }

    // sol() ? cout << "YES" : cout << "NO";
    return 0;
}