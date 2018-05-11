#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void f(vector<int> v,vector<vector<int> > *all){
	 all->push_back(v);
}


int main(){
	vector<int> v;
	vector<vector<int> > all;
	v.push_back(4);
	cout<<all.size();
	f(v,&all);
	f(v,&all);
	cout<<all.size();
}