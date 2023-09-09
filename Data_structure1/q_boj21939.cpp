#include <iostream>
#include <set>
#include <map>
using namespace std;

set<pair<int, int>> db;
// set{} => binary search tree�� ������ �ִ�

map<int, int> dict;
// key, value

// �� �˻���
//  Set�� ������ ������� �ʰ� �ߺ��� ������� �ʴ´�
//  Map�� ������ ������� �ʰ�, Key �ߺ��� ������� ������ Value�� �ߺ��� ���ȴ�.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p, l;
        // p = ����  ��ȣ
        // l = ���� ���̵�
        cin >> p >> l;
        db.insert({l, p});
        dict[p] = l;
        // dict[������ȣ] = ���� ���̵� ==> ������ȣ�� ���� ���̵��� ã�´� O(logN)
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string op;
        cin >> op;

        if (op == "add")
        {
            int p, l;
            cin >> p >> l;
            db.insert({l, p});
            dict[p] = l;
            // dict[������ȣ] = ���� ���̵�
        }
        else if (op == "recommend")
        {
            int x;
            cin >> x;
            if (x == -1)
            { // ���� ���� ������ ��ȣ�� ���
                cout << (*db.begin()).second << "\n";
                // db.begin() => �ּҰ�
                //  *db.begin() => ��!
            }
            else
            { // x == 1, ���� ����� ������ ��ȣ�� ���
                cout << (*prev(db.end())).second << "\n";

                // prev() : ���� iterator���� ���ϴ� �Ÿ�(-n��) �Ÿ��� iterator�� ��ȯ�ϴ� �Լ�
            }
        }
        else
        {
            // op == "solved"
            int p;
            cin >> p;
            db.erase({dict[p], p});
            //  �� set���� �ϸ� �ȵ�? solved ���� �ִ��� Ž���Ҷ� {l,p} �� ã�ƾ��ϴµ�
            // l�� �𸣴ϱ� �� ã�� => map�� m[key]  = value; ���̴ϱ� p�� l�� �� �� �ִ�
            // �׷��� ������ map�� ���ٳ�
            dict.erase(p);
            // solved ������ dict������ ����
        }
    }
}
