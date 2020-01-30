// C++ implementation of search and insert 
// Operations on Trie 

/*
    pmaik


          ( •̪●)
        ███████]▄▄▄▄▄▄▄▄▃  ▃  ▃ 
    ▂▄▅█████████▅▄▃▂
   [███████████████████]
  ...◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤......

*/
#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<bitset>
#include<deque>
#include<iterator>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cstdio>
#include<memory.h>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include <iomanip>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false);
 

const int ALPHABET_SIZE = 26; 
// trie node 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 

	// isEndOfWord is true if the node represents 
	// end of a word 
	bool isEndOfWord; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *temp = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!temp->children[index]) 
		{
			temp->children[index] = getNode(); 
		}

		temp = temp->children[index]; 
	} 

	// mark last node as leaf 
	temp->isEndOfWord = true; 
} 

// Returns true if key presents in trie, else false 
bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *temp = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!temp->children[index]) 
		{
			return false;
		} 

		temp = temp->children[index]; 
	} 

	return (temp != NULL && temp->isEndOfWord); 
} 

// Returns true if root has no children, else false 
bool isEmpty(TrieNode* root) 
{ 
    for(int i = 0; i < ALPHABET_SIZE; i++) 
    {
    	if (root->children[i]) 
        {
         	return false; 
        }
    }
    return true; 
} 

// Recursive function to delete a key from given Trie 
TrieNode* remove(TrieNode* root, string key, int depth = 0) 
{ 
	// If tree is empty 
	if (!root) 
		return NULL; 

	// If last character of key is being processed 
	if (depth == key.size()) 
	{ 

		// This node is no more end of word after 
		// removal of given key 
		if (root->isEndOfWord) 
			root->isEndOfWord = false; 

		// If given is not prefix of any other word 
		if (isEmpty(root)) 
		{ 
			delete (root); 
			root = NULL; 
		} 

		return root; 
	}

	// If not last character, recur for the child 
	// obtained using ASCII value 
	int index = key[depth] - 'a'; 
	root->children[index] = remove(root->children[index], key, depth + 1); 

	// If root does not have any child (its only child got deleted), 
	// and it is not end of another word. 
	if (isEmpty(root) && root->isEndOfWord == false) 
	{ 
		delete (root); 
		root = NULL; 
	} 

	return root; 
} 

// Driver 
int main() 
{ 
	fastio;

	// Input keys (use only 'a' through 'z' and lower case)
	ll n,i;
	cin>>n; 
	string keys[n];
	for(i=0; i<n; i++)
	{
		cin>>keys[i];
	}

	struct TrieNode *root = getNode(); 

	// Construct trie 
	for(i = 0; i < n; i++) 
	{
		insert(root, keys[i]);
	} 

	// Search for different keys 
	ll m;
	cin>>m;
	string s;
	for(i=0; i<m; i++)
	{
		cin>>s;
		if( search(root, s) )
		{
			cout<<s<<" -- is present \n";
		}
		else
		{
			cout<<s<<" -- is not present \n";
		}
	}
	cin>>s;
	cout<<"delete --- "<<s<<endl;
	
	remove(root, s );
	if( search(root, s) )
	{
		cout<<s<<" -- is present \n";
	}
	else
	{
		cout<<s<<" -- is not present \n";
	}
	
	return 0; 
} 
