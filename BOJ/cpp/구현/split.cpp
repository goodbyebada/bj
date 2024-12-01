#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
/**
 * stringstream은 읽기 및 쓰기 가능하다.
 */
vector<string> split(string input, char delimeter) {
  vector<string> answer;
  stringstream ss(input);

  string temp;

  //   getline 함수는 ss(스트림)을에서 구분자(delimeter)을 기준으로 문자열을
  //   읽어온다.
  //   구분자를 만날때마다 temp에 저장한다.
  //   구분자로 나눌 부분이 없을때 루프가 종료된다.

  while (getline(ss, temp, delimeter)) {
    answer.push_back(temp);
  }

  return answer;
}

/**
 * ostringstream 쓰기 전용
 * 데이터를 문자열로 조합하는데 사용한다.
 *
 */
void ostringstreamFun() {
  ostringstream oss;
  string s1 = "abc", s2 = "dfe";

  int i1 = 19234;
  double d1 = 3.591;

  oss << s1 << "\n" << i1 << "\n" << s2 << "\n" << d1;  // 문자열 붙이기
  cout << oss.str()
       << endl;  // str() : ostringstream 객체에서 조립된 문자열을 꺼낼 수 있다.
}

/**
 * istringstream
 * 읽기 전용
 * 문자열로 초기화
 * >> 로 읽을 수 있다.
 */
void istringstreamFun() {
  string exampleString = "let me go home";

  // 공백을 기준으로 문자열을 파싱하고, 변수 형식에 맞게 형변환을 해준다.
  istringstream input(exampleString);
  string a, b, c, d;
  double db;

  input >> a >> b >> c >> d;
  input >> a >> b >> c >> db;

  cout << a << b << c << d << '\n';
  //   letmegohome

  cout << a << b << c << db << '\n';
  //   letmego0
  // 변환 실패시 기존값이 유지 되지 않고 초기화된다.
}

int main() {
  cout << cin.eof();
  // split 예시
  ostringstreamFun();
  string splitString = "let,me,go,home";
  for (const auto &i : split(splitString, ',')) {
    cout << i << '\n';
  }
  return 0;
}