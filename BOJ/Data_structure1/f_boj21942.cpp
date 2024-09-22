#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <sstream>
using namespace std;

/**
 * 부품 대여 조건
 * 1. 같은 종류의 부품은 하나만 대여가능
 * 2. 다른 종류의 부품 , 개인당 같은 시간 여러개 대여 가능
 * 3. 다른 사람이더라도 대여기간은 부품마다 별도
 *
 * 입력
 * 정보의 개수 N
 * 대여기간 L
 * 벌금 F
 *
 * 첫째줄 N L F
 *
 * 형식
 * DDD/hh:mm DDD는 000/ 00:00은 주어지지 않는다
 * yyyy-MM-dd hh:mm
 * 연도는 항상 2021
 *
 * 출력
 * 사전순으로 동아리 회원 닉네임 M과 내야하는 벌금
 * 벌금 내야하는 사람들이 없다면 -1 출력
 * */

/**
 * sol1)
 * 2.맵에도 push
 * 3.새로운 입력이 들어올때마다 map에서 key로 아이디를 찾고, value에 해당 부품이 있는지 확인한다.
 * 4.존재한다면 map에 push 하지않는다.
 * -> 계산한다 -> 초과시, 벌금 vector에 {아이디, 벌금}push 한다.
 * 5. 존재하지 않는다면 map에 push 한다.
 * 6. N번 진행 후 vector이 empty 라면 -1을 출력한다.
 */

// 대여시간, 부품 이름
map<string, vector<pair<string, string>>> M;

int insertToMap()
{
}

// 대여시간 파싱 로직
int parsingListItem()
{

    // 2021 - 01 - 01 09 : 12 arduino tony9402

    string date;
    string time;
    string obj;
    string id;

    cin >> date >> time >> obj >> id;
}

vector<string> parseDayNDate(string day)
{

    vector<string> parseVec;
    stringstream sstream(day);
    string word;

    if (getline(sstream, word, '/'))
    {

        parseVec.push_back(word);
    }
    return parseVec;
}

vector<int> parsingTime(string time)
{
    vector<int> timeVec;
    stringstream sstream(time);
    string word;

    while (getline(sstream, word, ':'))
    {
        timeVec.push_back(stoi(word));
    }

    return timeVec;
}

/**
 * index 1부터 참조
 */
vector<int> parsingInsertDay(string time)
{
    vector<int> timeVec;
    stringstream sstream(time);
    string word;

    while (getline(sstream, word, '-'))
    {
        timeVec.push_back(stoi(word));
    }

    return timeVec;
}

int boj()
{

    int N, F;
    string L;
    vector<int> vec;
    // 회원수 N, 대여기간 L, 벌금 F

    cin >> N >> L >> F;
    vec = parsingTime(L);
    int hour = vec[1];
    int min = vec[2];

    while (N--)
    {
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();
    return 0;
}