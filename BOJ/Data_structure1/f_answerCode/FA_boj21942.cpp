
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * 계산
 *
 * 대여 월 일 시간
 * 반납  월 일 시간
 *
 *
 * 어차피 년도는 2021년으로 고정이 되어있음
 *
 * 반납 월 - 대여 월
 *
 * -> 분 단위로 바꿔서 계산을 해준다.
 *
 * 1) 월이 같지 않다면
 * 2월은 29일까지 3월은 31일 4월은 30일..!?
 *
 */
struct info
{
    string mm;
    string dd;
    string time;
    string obj;
    string name;
    bool flag;
};

void init()
{
    ios_base::sync_with_stdio(false);
    // c 스타일과, cpp 스타일 혼합할 수 없는 대신에 동기화 과정에서 시간 절약돼 입출력 속도가 빨라짐.
    cin.tie(0), cout.tie(0);
    // 내부적으로 cin과 cout을 묶어주는 과정을 수행하지 않아 절약.
    // 평소에는 cin과 cout이 하나로 묶여져 있음.
}

/**
 * 2개씩 있는 문자 변수 : 반납시간
 * 1개씩 있는 문자 변수 : 대여시간
 */
long long feeCal(string m, string d, string t, string mm, string dd, string tt)
{

    long long t2 = stoll(tt.substr(0, 2)) * 60 + stoll(tt.substr(3, 2));
    // 반납시간 hh:mm 형식 -> 분 단위로

    long long t1 = stoll(t.substr(0, 2)) * 60 + stoll(t.substr(3, 2));
    // 대여시간 -> 분 단위로

    if (m == mm)
    {
        // 대여 월과 반납 월이 같을 때

        long long day = (stoll(dd) - stoll(d)) * 60 * 24;

        return day + (t2 - t1);
        // 대여 일( 분으로 전환) + 시간
    }
    else
    {
        /**
         * 대여 월과 반납 월이 같지 않다면,
         * ex) 대여 월 03월 28일,  반납 월 5월 1일
         * ex) 대여 월 03월 1일,  반납 월 5월 1일
         */
        long long day = 0;
        if (stoll(mm) - stoll(m) > 1)
        {

            for (long long i = stoll(m) + 1; i < stoll(mm); i++)
            {
                day += (month[i] * 60 * 24);
                /**
                 * 한 달이 되는 기준으로 계산한다.
                 * ex) 대여 월 03월 28일,  반납 월 6월 5일
                 * 4월, 5월 , 6월의 일 수 계산 ( 분 단위로  전환)
                 */
            }
        }
        // day+=  ((mm월의 dd까지의 일) + (m월의 남은 일)) *60 *24

        day += (stoll(dd) + (month[stoll(m)] - stoll(d))) * 60 * 24;

        return day + (t2 - t1);
    }
}

void solution()
{
    long long n, f;
    string l;

    cin >> n >> l >> f;
    // 8 014/00:00 5

    // l : 014/00:00
    string day = l.substr(0, 3);
    // 014 day
    string hour = l.substr(4, 2);
    // 00 hour
    string min = l.substr(7, 2);
    // 00 min

    long long reservedTime = (stoll(day) * 24 + stoll(hour)) * 60 + stoll(min);
    // 예약된 시간 ( 벌금을 부과하지 않는 시간 )

    map<string, info> objInfo;
    map<string, long long> peopleFee;

    for (int i = 0; i < n; i++)
    {
        string date, time, obj, name;

        // yyyy-MM-dd hh:mm [부품 이름] [동아리 회원 닉네임]
        cin >> date >> time >> obj >> name;

        string mm = date.substr(5, 2);
        string dd = date.substr(8, 2);

        /**
         *std::map의 operator[]를 사용할 때, 해당하는 키가 맵에 없는 경우에는 새로운 항목이 자동으로 생성된다. 이 항목은 기본 값으로 초기화 된다.
         *
         */
        if (objInfo[obj + name].flag)
        {
            // 이전에 빌린 obj와 name이라면 이 코드 블록에 들어온다.

            info i = objInfo[obj + name];
            // time : 반납 시간 mm : 반납 월 dd : 반납 일
            // i.time: 대여 시간 i.mm : 대여 월 i.dd : 대여 일

            long long used = feeCal(i.mm, i.dd, i.time, mm, dd, time);
            // 빌린 시간 계산

            if (reservedTime < used)
            {
                peopleFee[name] += (used - reservedTime) * f;
                // 아이디 : 벌금
                // 중복 아이디 물건 여러개 대여로 벌금이 누적되기 때문에 += 연산자를 이용해야한다.
            }
            objInfo.erase(obj + name);
            // 벌금 부과한 objname은 지운다.
            // if문의 조건문 flag값이 0이어야, else 블록으로 넘어가 새로운 value 저장 가능하기 때문이다.
        }
        else
        {
            objInfo[obj + name] = {mm, dd, time, obj, name, true};
            // obj와 name이 없다면 value값으로 넣는다.
        }
    }

    if (peopleFee.empty())
    {
        cout << -1;
        return;
    }
    vector<pair<string, long long>> v;
    // 답안 vector

    map<string, long long> peopleFee;
    for (auto p : peopleFee)
    {
        v.push_back({p.first, p.second});
    }
    sort(v.begin(), v.end());

    for (auto vv : v)
    {
        cout << vv.first << ' ' << vv.second << '\n';
    }
}

int main()
{
    init();
    solution();
    return 0;
}