#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int f(vector<int> &v){
	v.push_back(-1);
}

int main(){
	vector<int> v;
	v.push_back(1);
	f(v);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}