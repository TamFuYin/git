#include<bits/stdc++.h>
template<typename T>
bool find(typename std::vector<T>::iterator b,typename std::vector<T>::iterator e,T x){
	auto i=std::lower_bound(b,e,x);
	return i!=e&&*i==x;
}
int main(){}
