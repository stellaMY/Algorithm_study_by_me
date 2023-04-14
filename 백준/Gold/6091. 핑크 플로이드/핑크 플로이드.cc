#include <iostream>
#include <vector>
using namespace std;

int n;
int tree[2000][2000]; // 변형된 코드 받기 (왼쪽 위만 주었으니 그걸로 오른쪽 아래 채우기)
int temp[2000][2000]; // 변형된 코드를 통해서 연결되면 1 아니면 0으로 담기
vector<int>final[2000]; // 리스트 완성

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> tree[i][j];
            tree[j][i] = tree[i][j];
        }
    }
    int flag = 0;
    // 만약 k를 거쳐서 값이 만들어지지 않는다면 다이렉트로 연결된 상태 -> temp에 1로 넣는다
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            flag = 0;
            if (tree[i][j] == 0)continue;
            for (int k = 0; k < n; k++) {
                if (tree[i][k] == 0 || tree[k][j] == 0)continue;
                if (tree[i][j] == tree[i][k] + tree[k][j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)temp[i][j] = 0;
            else temp[i][j] = 1;
        }
    }
    // temp에 1로 되어있으면 연결된 것으로 final에 넣어준다
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (temp[i][j] == 1)
                final[i].push_back(j+1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << final[i].size() << " ";
        for (int j = 0; j < final[i].size(); j++) {
            cout << final[i][j] << " ";
        }
        cout << "\n";
    }
}