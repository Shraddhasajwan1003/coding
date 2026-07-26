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


#include <bits/stdc++.h>
#include<vector>
void pairexplain(){
    std::pair<int,str> p = {1,"shraddha"};
    cout<<p.first<<" "<<p.second<<"\n";
    //for {1,{3,4}}
    std::pair<int,pair<int,int>> p1 = {1,{3,4}};
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<"\n";
    //pair array
    std::pair<int,int>int array[]= {{1,2},{3,4},{5,6}};
    for(int i=0;i<3;i++){
        cout<<array[i].first<<" "<<array[i].second<<"\n";
    }
}
void vectorexplain(){
    //vector is like dynamic array
    vector<int>v; //declaration
    v.push_back(1); //insertion at end
    v.emplace_back(2); //insertion at end (faster than push_back)
    v.push_back(3);
    cout<<"vector elements: ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "; //accessing elements
    }
    cout<<"\n";
    cout<<"first element: "<<v.front()<<"\n"; //first element
    cout<<"last element: "<<v.back()<<"\n"; //last element
    cout<<"is vector empty? "<<v.empty()<<"\n"; //check if empty
    cout<<"vector size: "<<v.size()<<"\n"; //size of vector
    v.pop_back(); //remove last element
    cout<<"after pop_back, vector elements: ";
    for(int i=0;i<v.size();i++){//method 1 for accessing elements by using for loop 
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    vector<int>v1(5,100);//{100,100,100,1001,100}
    vector<int>v2(5);//{0,0,0,0,0}
    vector<int>v2(v1);//copy one vector to another v1 comes in v2
    v1.push_back(5);//size now becomes 6 , even if size declared earlier was 5
    cout<<v1.size()<<"\n";
    vector<int>::iterator it= v1.begin();
    it++;
    cout<<*(it)<<"\n";

}
void vector_as_pair(){
    vector <pair<int,int>>vp;
    vp.push_back({1,2});
    vp.emplace_back(3,4);
    for(int i=0;i<vp.size();i++){
        cout<<vp[i].first<<" "<<vp[i].second<<"\n";
    }
}
int main(){
    pairexplain();
    vectorexplain();
    vector_as_pair();

}

