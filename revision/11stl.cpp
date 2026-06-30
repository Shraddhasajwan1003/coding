#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void explainvector(vector<int> v) {
        v.push_back(1);
        v.emplace_back(2);

        for (auto it : v) {
            cout << it << " ";
        }

        cout << "\n" << v.size() << endl;
    }

    void pairedvector(vector<pair<int, int>> vec) {
        vec.push_back({35, 89});
        vec.push_back({112, 48});

        for (auto it : vec) {
            cout << it.first << " ," << it.second << endl;
        }
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int m;
    cin >> m;

    vector<pair<int, int>> vec;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        vec.push_back({x, x + 1});
    }
    cout<<"output"<<"\n";
    obj.explainvector(v);
    obj.pairedvector(vec);
    vector<int>::iterator it = v.begin();
        it++;
        cout << *it << "'";//"it" prints addresses of the vector positons, use *it for vector values 
    // vector<int>::iterator it = v.begin();//commmented bcz same name vector cant be declared again that is "it" 
    //     it++;
    //     cout << *it << " ";
    if(v.size() > 1){
    auto it = v.begin();//most shortcut way to write auto it(it is iterator name):v( v is vector name)
    it++;
    cout << *it;
    }
    for(vector<int>::iterator it3=v.begin();it3 !=v.end();it3++){//instead of writing vector<int>iterator :: ---> u can write "auto" 
        cout<<*it3<<" ";

    }
    vector<int> v2;
    for(auto it:v2){
        int x;
        cin>>x;
        v2.push_back(x);
    }
    v.swap(v2);
    return 0;
}

