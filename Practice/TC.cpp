/*#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool compare(pair<int, int> a, pair<int , int> b)
{
    return (a.second - a.first <= b.second - b.first);
}
bool check(string pal){
	int i = 0, j = pal.length()-1;
	while(i<=j and pal[i]==pal[j]){i++;j--;
	
	}
		return i>j;
}

void solve(){
	for(ll i = 1;i<=1e7;i++){
		stringstream ss,sp;
		string pal ="";
		ss << i;
		ss >> pal;
		string sq = "";
		sp << (i*i);
		sp >> sq;
		if(check(pal) and check(sq)){
			cout<<pal<<" "<<sq<<'\n';
			}
		}
}
	int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t ;
    t = 1;
    //cin>>t;
    while(t--){solve();}
}
*/
// C++ program to find minimum time required
// to burn the binary tree completely

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
	int data;
	Node* left;
	Node* right;

	Node()
	{
		left = NULL;
		right = NULL;
	}
};

// Utility function to create a new Node
struct Info {
    int lDepth;
    int rDepth;
    bool contains;
  
    int time;
  
    Info()
    {
        lDepth = rDepth = 0;
        contains = false;
  
        time = -1;
    }
};
Node* newNode(int val)
{
	Node* temp = new Node;

	temp->data = val;

	return temp;
}

/*
	***********ADDITIONAL INFO*************
	lDepth - maximum height of left subtree
	rDepth - maximum height of right subtree
	contains - stores true if tree rooted at current node
			contains the first burnt node
	time - time to reach fire from the initally burnt leaf
		node to this node
*/
int mD(Node* root){
	if(root==NULL)return 0;
	
	return 1+max(mD(root->left),mD(root->right));	
}
int findDistance(Node* root,int x){
	  if (root == NULL)
      return -1;
 
    // Initialize distance
    int dist = -1;
 
    // Check if x is present at root or in left
    // subtree or right subtree.
    if ((root->data == x) ||
        (dist = findDistance(root->left, x)) >= 0 ||
        (dist = findDistance(root->right, x)) >= 0)
        return dist + 1;
 
    return dist;	
}
/*
	Function to calculate time required to burn
	tree completely
	
	node - address of current node
	info - extra information about current node
	target - node that is fired
	res - stores the result
*/
Info calcTime(Node* node, Info& info, int target, int& res)
{

	// Base case: if root is null
	if (node == NULL) {
		return info;
	}

	// If current node is leaf
	if (node->left == NULL && node->right == NULL) {

		// If current node is the first burnt node
		if (node->data == target) {
			info.contains = true;
			info.time = 0;
		}
		return info;
	}

	// Information about left child of root
	Info leftInfo;
	calcTime(node->left, leftInfo, target, res);

	// Information about right child of root
	Info rightInfo;
	calcTime(node->right, rightInfo, target, res);

	// If left subtree contains the fired node then
	// time required to reach fire to current node
	// will be (1 + time required for left child)
	info.time = (node->left && leftInfo.contains) ? (leftInfo.time + 1) : -1;

	// If right subtree contains the fired node then
	// time required to reach fire to current node
	// will be (1 + time required for right child)
	if (info.time == -1)
		info.time = (node->right && rightInfo.contains) ? (rightInfo.time + 1) : -1;

	// Storing(true or false) if the tree rooted at
	// current node contains the fired node
	info.contains = ((node->left && leftInfo.contains) || (node->right && rightInfo.contains));

	// Calculate the maximum depth of left subtree
	info.lDepth = !(node->left) ? 0 : (1 + max(leftInfo.lDepth, leftInfo.rDepth));

	// Calculate the maximum depth of right subtree
	info.rDepth = !(node->right) ? 0 : (1 + max(rightInfo.lDepth, rightInfo.rDepth));

	// Calculating answer
	if (info.contains) {
		// If left subtree exists and
		// it contains the fired node
		if (node->left && leftInfo.contains) {
			// calculate result
			res = max(res, info.time + info.rDepth);
		}

		// If right subtree exists and it
		// contains the fired node
		if (node->right && rightInfo.contains) {
			// calculate result
			res = max(res, info.time + info.lDepth);
		}
	}
	return info;
}


// Driver function to calculate minimum
// time required
bool isRight(Node* root,int target){
	if(root==NULL)return 0;
	
		if(root->data == target){
			return 1;
			}
		return isRight(root->left,target) or isRight(root->right,target);
}
int minTime(Node* root, int target)
{
	int res = 0;
	Info info;

	calcTime(root, info, target, res);
	
	//cout<<mD(root)<<' '<<mD(root->left)<<' '<<mD(root->right)<<'\n';
	cout<<res<<'\n';
	
	
	int H = findDistance(root,target);
	//cout<<H<<'\n';
	if(isRight(root->left,target)){
		res = H + mD(root->right);
	}else{
		res = H + mD(root->left);			
	}
	
	return res;
}

// Driver Code
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->left->left->left = newNode(8);
	root->left->right->left = newNode(9);
	root->left->right->right = newNode(10);
	root->left->right->left->left = newNode(11);

	// target node is 8
	int target = 8;

	cout << minTime(root, target)<<'\n';

	return 0;
}

//1 N 15 13 26 3 14 20 31 2 4
//4

