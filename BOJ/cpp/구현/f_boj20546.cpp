#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 🐜 기적의 매매법 🐜
 * 실버 5
 *
 * 답지 참고해 다시 작성
 */

int bnp(vector<int> dailyPrice, int budget) {
  int count = 0;

  for (int i = 0; i < dailyPrice.size(); i++) {
    if (budget >= dailyPrice[i]) {
      count += budget / dailyPrice[i];

      budget = budget % dailyPrice[i];
      // 나머지 금액
    }
  }

  return dailyPrice[dailyPrice.size() - 1] * count + budget;
}

int timing(vector<int> dailyPrice, int budget) {
  int count = 0;
  int cntUp = 0, cntDown = 0;

  for (int i = 1; i < dailyPrice.size(); i++) {
    if (dailyPrice[i - 1] < dailyPrice[i]) {
      cntUp++;
      cntDown = 0;
    }

    if (dailyPrice[i - 1] > dailyPrice[i]) {
      cntDown++;
      cntUp = 0;
    }

    if (dailyPrice[i - 1] == dailyPrice[i]) {
      cntUp = 0;
      cntDown = 0;
    }

    // 3일 이상 상승
    if (cntUp >= 3 && count > 0) {
      budget += dailyPrice[i] * count;
      count = 0;
    }

    // 3일 이상 하락
    if (cntDown >= 3) {
      if (budget >= dailyPrice[i]) {
        count += budget / dailyPrice[i];
        budget = budget % dailyPrice[i];
      }
    }
  }

  return dailyPrice[dailyPrice.size() - 1] * count + budget;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int BNP, TIMING;

  int budget;
  cin >> budget;

  vector<int> dailyPrice(14);

  for (auto &i : dailyPrice) {
    cin >> i;
  }

  BNP = bnp(dailyPrice, budget);
  TIMING = timing(dailyPrice, budget);

  if (BNP > TIMING) {
    cout << "BNP";
    return 0;
  }

  if (BNP < TIMING) {
    cout << "TIMING";
    return 0;
  }

  if (BNP == TIMING) {
    cout << "SAMESAME";
    return 0;
  }

  return 0;
}