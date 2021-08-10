#include <bits/stdc++.h>
using namespace std;
typedef struct TrieNode{
    struct TrieNode* children[26];
    bool isEnd;
    int freq;
}T;
T* getNode(){
    T* res = new T;
    res->isEnd = false;
    res->freq = 0;
    for(int i=0;i<26;i++)res->children[i] = NULL;
    
    return res;
}
void insert(T** root,string word){
    if(*root==NULL)*root = getNode();
   // cout<<*root<<endl;
    T* ptr = *root;
    for(char i:word){
        int indx = i-'a';
        if(!ptr->children[indx]){
            ptr->children[indx] = getNode();
        }
        ptr = ptr->children[indx];
        ++ptr->freq;
    }
    ptr->isEnd = 1;
}
int main() {
	//code
	string words[4] = {"zebra", "dog", "duck", "dove"};
	T* root = NULL;
	for(string s:words){insert(&root,s);}
	vector<string>up;
	for(string s:words){
	    string tmp="";
	    T* ptr = root;
	    for(char i:s){
	        int indx = i-'a';
	        ptr = ptr->children[indx];
	        tmp+=i;
	        if(ptr->freq==1){
	            up.push_back(tmp);
	            break;
	        }
	    }
	}
	
	for(string s:up)cout<<s<<' ';
	cout<<endl;
	
	return 0;
}
