#include <bits/stdc++.h>
using namespace std;
typedef struct TrieNode{
    struct TrieNode* children[26];
    bool isEnd;
    int freq;
}T;
T* root = NULL;
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
bool search(T* root,string word){
    if(root==NULL)return 0;
    T* ptr = root;
    for(char i:word){
        int indx = i-'a';
        if(!ptr->children[indx]){
            return 0;
        }
        ptr = ptr->children[indx];
        ++ptr->freq;
    }
   return ptr!=NULL&&ptr->isEnd;
}

bool canbebroken(string s){
	if(s.length()==0)return 1;
	
	for(int i = 1;i<=(int)s.length();i++){
		string tmp = s.substr(0,i);
        
        if(search(root,tmp)&&canbebroken(s.substr(i,(int)s.length()-i))){
			return 1;
		}
        
		
	}
	return 0;
}
	
int main() {
	//code
	
	
	string dictionary[] = {"mobile","samsung","sam", 
                           "sung","man","mango", 
                           "icecream","and","go","i", 
                           "like","ice","cream"};
                           
    for(string s:dictionary)insert(&root,s);
    
    
    string input;
    int t;cin>>t;
    
    while(t--){
    cin>>input;
    
    //if dictionary contains a particular prefix of the given string if yes then we look into the other part of the string
    cout<<canbebroken(input)<<'\n';
    }
	
	return 0;
}
