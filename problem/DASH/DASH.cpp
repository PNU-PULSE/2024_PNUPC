#include <iostream>
#include <string>
#include <stack>
using namespace std;

const char vec[4][2] = {{'H', 'D'}, {'D', 'A'}, {'A', 'S'}, {'S', 'H'}};

int N;
string s;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string ans;

    stack<char> dash;

    cin >> N;
    cin >> s;

    for(int i = 0 ; i < N; ++i) {
        if(dash.empty()) {
            if(s[i] == 'D')
                dash.push(s[i]);
            else
                ans.push_back(s[i]);
            continue;
        }

        int j;
        for(j = 0; j < 4; ++j) {
            if(dash.top() == vec[j][0] && s[i] == vec[j][1]) {
                dash.push(s[i]);
                break;
            }
        }

        if(j == 4)
            ans.push_back(s[i]);
    }

    if(dash.top() != 'H') {
        string temp = "";
        while(dash.top() != 'H') {
            temp = dash.top() + temp;
            dash.pop();
        }
        ans.append(temp);
    }

    cout << dash.size() / 4 << '\n' << ans;

    return 0;
}