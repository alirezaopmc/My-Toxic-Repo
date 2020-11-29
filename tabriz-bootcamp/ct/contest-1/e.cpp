#include <iostream>
using namespace std;

const int N=100*1000+100;


int main(){
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	int b=0,f=0,s=0;
	for(int i=0;i<2*n;i++){
		if(s1[i]=='1'&&s2[i]=='1')
			b++;
		else if(s1[i]=='1'&&s2[i]=='0')
			f++;
		else if(s1[i]=='0'&&s2[i]=='1')
			s++;		
	}
    
	if(b%2)
		f++;
	if(f>s)
		cout<<"First";
	else if(s>f+1)
		cout<<"Second";
	else
		cout<<"Draw";
    
}