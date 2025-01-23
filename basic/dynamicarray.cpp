#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node{
        Node* links[27];
        bool endswith = false;
    public:
        void put(char ch, Node* node){
            if(ch =='/'){
                links[26] = node;
                return;
            }
            links[ch-'a'] = node;
        }
        Node* get(char ch){
            return ch !='/' ? links[ch-'a'] : links[26];
        }
        bool containskey(char ch){
            return ch != '/' ? (links[ch-'a'] !=NULL): (links[26] !=NULL);
        }
    };
    class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void InsertElement(string s){
            int n = s.length();
            Node* node = root;
            for(int i =0;i<n;i++){
                if(!node->containskey(s[i])){
                    node->put(s[i],new Node());
                }
                node = node->get(s[i]);
            }
            node->endswith = true;
        }
        bool check(string s){
            Node* node = root;
            int n = s.length();
            for(int i =0;i<n;i++){
                if(!node->containskey(s[i])){
                    return false;
                }
                node = node->get(s[i]);
            }
            return node->endswith;
        }
    };
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        Trie* stuff = new Trie();
        vector<string> ans;
        for(int i = 0;i<n;i++){
            stuff->InsertElement(folder[i]);
        }
        for(int i = 0;i<n;i++){
            string s ="";
            for(int j = 0;j<folder[i].size();j++){
                s+=folder[i][j];
                if(stuff->check(s) && j!= folder[i].size() - 1){
                    break;
                } 
                if(j == folder[i].size() -1){
                    ans.push_back(folder[i]);
                }
            }
        }
        return ans;
    }
};