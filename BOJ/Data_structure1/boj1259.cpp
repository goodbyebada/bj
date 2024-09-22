#include <iostream>
#include <string>
#define endl "\n";
using namespace std; 

/*
1. 문자열을 받는다
2. 앞과 끝을 동시에 인덱스를 하나씩 줄여가면서 비교한다
3. 문자열의 길이가 짝수라면 end - begin = 1 일때 멈춘다
  홀수라면 begin == end 멈춘다

==begin > end 멈춘다 
while ( begin <= end) 
4. 다르다면 no 출력 

*/

int lessMemory_check(){
	
	while(1){
		
		int n;
		if(!n) break;
		int q=0, m= n;
		while(n){
			
			q = 10*q+ n%10;
			// n은 끝의 자리 수
			n /= 10;
			// n의 몫, 즉 맨 마지막 자리를 제외한 나머지 수 
			
			// 숫자를 거꾸로 뒤집는다. 
			// q*10 자리수를 앞으로 뺀다 + 현재의 맨 마지막 자리 수
			// n을 10으로 나누는 이유? 맨 끝에 있는 자리 수를 제거하기 위해서  
		}
		
		if( q == n) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}

int check(string str){
	
		int begin = 0;
		int end = str.size()-1;
			
		while(begin <= end){
			if(str[begin] != str[end]){
				cout << "no" << endl;
				return 0;		
			}
			
			begin++;
			end--;
			
		}
		
	cout << "yes" << endl;
	
	
	
	return 0;
}

int main(){
	
	string str;
	
	while(1){
		cin >> str;
		if(str == "0"){
			return 0;
		}
		check(str);
	}


}
