#include <bits/stdc++.h>
using namespace std;
 
set<pair<int, int>> db;
//set{} => binary search tree를 가지고 있다
 
map<int, int> dict;
//key, value  

//답 검색함 
// Set은 순서가 보장되지 않고 중복을 허용하지 않는다
// Map은 순서가 보장되지 않고, Key 중복은 허용하지 않지만 Value의 중복은 허용된다.
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m; 
	cin >> n;
	
    for(int i = 0; i < n; i++){
        int p, l; 
        // p = 문제  번호
		// l = 문제 난이도  
		cin >> p >> l;
        db.insert({l, p});
        dict[p] = l;
        // dict[문제번호] = 문제 난이도 ==> 문제번호로 문제 난이도를 찾는다 O(logN)  
    }
    
    cin >> m;
    
    for(int i = 0; i < m; i++){
        string op; 
		cin >> op;
 
        if(op == "add"){
            int p, l; 
			cin >> p >> l;
            db.insert({l, p});            
            dict[p] = l;
            // dict[문제번호] = 문제 난이도 
        }else if(op == "recommend"){
            int x; 
			cin >> x;
            if(x == -1){    // 가장 쉬운 문제의 번호를 출력
                cout << (*db.begin()).second << "\n";
                // db.begin() => 주소값 
				//  *db.begin() => 값! 
            }else{  // x == 1, 가장 어려운 문제의 번호를 출력
                cout << (*prev(db.end())).second << "\n";
                
			//prev() : 기준 iterator에서 원하는 거리(-n차) 거리의 iterator를 반환하는 함수                
            }
        }else{  
		// op == "solved"
            int p; 
			cin >> p;
            db.erase({dict[p], p});
            //  다 set으로 하면 안됨? solved 문제 있는지 탐색할때 {l,p} 로 찾아야하는데
			// l을 모르니까 못 찾음 => map은 m[key]  = value; 꼴이니까 p로 l를 알 수 있다 
			//그렇기 떄문에 map을 쓴다네  
            dict.erase(p);
            //solved 했으니 dict에서도 삭제  
        }
    }
}
