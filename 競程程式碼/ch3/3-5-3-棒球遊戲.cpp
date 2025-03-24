#include <iostream>
#include <string>
using namespace std;
bool b[4];
int convert(string s) {
  if (s.compare("1B") == 0) return 1;
  if (s.compare("2B") == 0) return 2;
  if (s.compare("3B") == 0) return 3;
  if (s.compare("HR") == 0) return 4;
  if (s.compare("FO") == 0) return 0;
  if (s.compare("GO") == 0) return 0;
  if (s.compare("SO") == 0) return 0;
}
int win(int c) {//c為1表示一壘打， c為2表示二壘打。 
  int s = 0;
  for (int i = 3; i>3 - c; i--) {//已經在壘包上的得分
    if (b[i]) s++;
  }
  for (int i = 3; i>c; i--) {//已經在壘包上往前推進
	b[i] = b[i - c];
  }
  if (c == 4) s++; //全壘打
  else b[c] = true;//打擊者上壘
  for (int i = 1; i<c; i++) b[i] = false;//往前推進，壘包設定為沒有人
  return s;//回傳得分
}
int main() {
  int p[9][20], n[9], out, ocount, score;
  string s;
  for (int i = 0; i<9; i++) {
	cin >> n[i];
	for (int j = 0; j<n[i]; j++) {
	  cin >> s;
	  p[i][j] = convert(s);
	}
  }
  cin >> out;
  ocount = 0;
  score = 0;
  for (int i = 1; i<4; i++) b[i] = false; 
  for (int i = 0; i<9 && ocount<out; i++) { 
    for (int j = 0; j< 9 && ocount<out; j++) {
      if (p[j][i] > 0) {//1B 2B 3B HR
        score += win(p[j][i]);
      } else {
        ocount++;//出局
        if (ocount % 3 == 0) {//三出局
          for (int k = 1; k<4; k++) b[k] = false;
        }
      }
    }
  }
  cout << score << endl;
}
