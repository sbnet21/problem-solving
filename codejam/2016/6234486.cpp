/*
Bad Horse
https://code.google.com/codejam/contest/6234486/dashboard
*/
#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 100

using namespace std;

vector<string> v;
queue<int> q;
int color[MAX_SIZE];
bool adjacent_matrix[MAX_SIZE][MAX_SIZE];

int getIndex(string s)
{
    for (int i = 0; i < v.size(); i++) // search
        if (s == v[i])  return i;
    v.push_back(s); // add only if not found
    return v.size() - 1;    
}

int main()
{
    int T, M;
    bool yes;
    string s;
    cin >> T;

    for (int i = 0 ; i < T; i++) {
        yes = true;
        v.clear();
        cin >> M;

        for (int j = 0; j < MAX_SIZE; j++) {
            color[j] = -1; // not assigned
            for (int k = 0; k < MAX_SIZE; k++)
                adjacent_matrix[j][k] = false;
        }
        
        for (int j = 0; j < M; j++) {
            cin >> s;           
            int idx1 = getIndex(s);
            cin >> s;
            int idx2 = getIndex(s);
            
            adjacent_matrix[idx1][idx2] = true;
        }
        
        for (int j = 0; j < v.size(); j++) {
            if (color[j] == -1) {
                color[j] = 0;
                q.push(j);
            }
            
            while(!q.empty()) {
                int item = q.front();
                q.pop();
                                
                for (int k = 0; k < v.size(); k++) {
                    if (adjacent_matrix[item][k] == true) {
                        if (color[k] == color[item]) {
                            yes = false;
                            while(!q.empty()) q.pop();
                            break;
                        } else if (color[k] == -1){
                            color[k] = 1 - color[item];
                            q.push(k);
                        } 
                    }
                }
                if (yes == false)
                    break;
            }
            if (yes == false)
                break;
        }
        cout << "Case #" << (i + 1) << ": " << (yes ? "Yes" : "No") << endl;
    }
    return 0;
}
