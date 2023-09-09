<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
 
set<pair<int, int>> db;
//set{} => binary search tree¸¦ °¡Áö°í ÀÖ´Ù
 
map<int, int> dict;
//key, value  

//´ä °Ë»öÇÔ 
// SetÀº ¼ø¼­°¡ º¸ÀåµÇÁö ¾Ê°í Áßº¹À» Çã¿ëÇÏÁö ¾Ê´Â´Ù
// MapÀº ¼ø¼­°¡ º¸ÀåµÇÁö ¾Ê°í, Key Áßº¹Àº Çã¿ëÇÏÁö ¾ÊÁö¸¸ ValueÀÇ Áßº¹Àº Çã¿ëµÈ´Ù.
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m; 
	cin >> n;
	
    for(int i = 0; i < n; i++){
        int p, l; 
        // p = ¹®Á¦  ¹øÈ£
		// l = ¹®Á¦ ³­ÀÌµµ  
		cin >> p >> l;
        db.insert({l, p});
        dict[p] = l;
        // dict[¹®Á¦¹øÈ£] = ¹®Á¦ ³­ÀÌµµ ==> ¹®Á¦¹øÈ£·Î ¹®Á¦ ³­ÀÌµµ¸¦ Ã£´Â´Ù O(logN)  
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
            // dict[¹®Á¦¹øÈ£] = ¹®Á¦ ³­ÀÌµµ 
        }else if(op == "recommend"){
            int x; 
			cin >> x;
            if(x == -1){    // °¡Àå ½¬¿î ¹®Á¦ÀÇ ¹øÈ£¸¦ Ãâ·Â
                cout << (*db.begin()).second << "\n";
                // db.begin() => ÁÖ¼Ò°ª 
				//  *db.begin() => °ª! 
            }else{  // x == 1, °¡Àå ¾î·Á¿î ¹®Á¦ÀÇ ¹øÈ£¸¦ Ãâ·Â
                cout << (*prev(db.end())).second << "\n";
                
			//prev() : ±âÁØ iterator¿¡¼­ ¿øÇÏ´Â °Å¸®(-nÂ÷) °Å¸®ÀÇ iterator¸¦ ¹ÝÈ¯ÇÏ´Â ÇÔ¼ö                
            }
        }else{  
		// op == "solved"
            int p; 
			cin >> p;
            db.erase({dict[p], p});
            //  ´Ù setÀ¸·Î ÇÏ¸é ¾ÈµÊ? solved ¹®Á¦ ÀÖ´ÂÁö Å½»öÇÒ¶§ {l,p} ·Î Ã£¾Æ¾ßÇÏ´Âµ¥
			// lÀ» ¸ð¸£´Ï±î ¸ø Ã£À½ => mapÀº m[key]  = value; ²ÃÀÌ´Ï±î p·Î l¸¦ ¾Ë ¼ö ÀÖ´Ù 
			//±×·¸±â ‹š¹®¿¡ mapÀ» ¾´´Ù³×  
            dict.erase(p);
            //solved ÇßÀ¸´Ï dict¿¡¼­µµ »èÁ¦  
        }
    }
}
=======
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

/*
ë‘˜ ë‹¤ ë ˆë“œë¸”ëž™íŠ¸ë¦¬ ì‚½ìž…/ì‚­ì œ/íƒìƒ‰ ì‹œê°„ ë³µìž¡ë„ log(n)
set ì‚¬ìš© -> ì¤‘ë³µëœ ê°’ì„ ê°€ì§€ì§€ ì•ŠëŠ”ë‹¤

1. add p l
2. solved p  -> ë¬¸ì œ ì‚­ì œ
3. recommand x -> ë¬¸ì œ ì¶œë ¥

*/

set<int> list;

int boj()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    boj();
    return 0;
}
>>>>>>> cc0a11e (ì•Œê³ ë¦¬ì¦˜)
