// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdlib> // absolute

using namespace std;
//-struct------------------------------------------------------

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


// function declaration----------------------------------------
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
bool isPalindrome(string s);
bool canConstruct(string ransomNote, string magazine);
vector<string> summaryRanges(vector<int>& nums);
int maxDepth(TreeNode* root);
vector<double> averageOfLevels(TreeNode* root);
int getMinimumDifference(TreeNode* root);
TreeNode* sortedArrayToBST(vector<int>& nums);

//-------------------------------------------------------------
int main()
{
   //std::cout << __cplusplus << std::endl; check cplus version

   
    return 0;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int index1 = 0;
    int index2 = 0;

    vector<int> answer;

    if (n == 0)
        return;
    

    while (m+n > index1 + index2)
    {
        if (index2<n && index1 < m && nums1[index1] < nums2[index2])
        {
            answer.push_back(nums1[index1]);
            ++index1;
        }
        else if(index2 < n)
        {
            answer.push_back(nums2[index2]);
            ++index2;
        }
        else
        {
            answer.push_back(nums1[index1]);
            ++index1;
        }
    }

    nums1 = answer;
}
bool isPalindrome(string s)
{
    std::string filtered;

    for (char c : s) 
    {
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z')) 
        {
            filtered += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
    }

    int indexback = filtered.size()-1;
    int indexfront = 0;

    for (size_t i = 0; i < filtered.size() /2 ; i++)
    {
        if (filtered[indexback] != filtered[indexfront])
            return false;

        ++indexfront;
        --indexback;
    }

    return true;
    
}
bool canConstruct(string ransomNote, string magazine)
{
    vector<int> aphabetCount(27,0);

    for(char letter : magazine)
    {
        ++aphabetCount[letter - 97];
    }

    for (char letter : ransomNote)
    {
        --aphabetCount[letter - 97];
    }

    for (int count : aphabetCount)
    {
        if (count < 0)
            return false;
    }

    return true;
}
vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> answer;

    if (nums.size() < 1)
        return answer;

    int start = nums[0];
    for (size_t i = 0; i < nums.size()-1; i++)
    {
        if (nums[i]+1 != nums[i + 1])
        {
            if(start == nums[i])
                answer.push_back(to_string( start));
            else
                answer.push_back(format("{}->{}", start, nums[i]));

            start = nums[i + 1];
        }

    }

    if(start == nums[nums.size()-1])
        answer.push_back(to_string(start));
    else
        answer.push_back(format("{}->{}", start, nums[nums.size() - 1]));

    return answer;
}
bool isValid(string s) 
{
    std::stack<char> st;
    for (char c : s) 
    {
        
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else 
        {
            if (st.empty()) return false;

            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();
            }
            else 
            {
                return false;
            }
        }
    }

    return st.empty();

}
bool hasCycle(ListNode* head) 
{
    unordered_map< ListNode* , ListNode*> umap;
    ListNode* node = head;

    if (head == nullptr)
        return false;

    while(node->next != nullptr)
    {
        if (umap.find(node) == umap.end())
        {
            umap[node] = node->next;
        }
        else 
        {
            return true;
        }

        node = node->next;
    }

    return false;
}
int maxDepth(TreeNode* root)
{
    stack<pair<TreeNode*, int>> st;
    st.push({ root, 1 });
    int deepest = 0;

    while (!st.empty())
    {
        auto [node, d] = st.top();
        st.pop();

        if (node == nullptr) continue;
        if (d > deepest)
            deepest = d;


        if (node->right) st.push({ node->right, d + 1 });
        if (node->left)  st.push({ node->left, d + 1 });
      
    }

    return deepest;
}
vector<double> averageOfLevels(TreeNode* root) 
{
    vector<double> averages; 

    if (!root) return averages;

    queue<TreeNode*> q; 
    q.push(root); 

    while (!q.empty()) 
    { 
        int size = q.size(); 
        double sum = 0; 

        for (int i = 0; i < size; ++i) 
        { 
            TreeNode* node = q.front();
            q.pop(); 

            sum += node->val; 

            if (node->left) q.push(node->left); 
            if (node->right) q.push(node->right);
        }

        averages.push_back(sum / size); 
    }

    return averages;
}
int getMinimumDifference(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);

    vector<int> values;

    while (!q.empty())
    {
        int size = q.size();
       
        for (int i = 0; i < size; ++i)
        {
            TreeNode* node = q.front();
            q.pop();

            values.push_back(abs(node->val));

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    sort(values.begin(),values.end());

    int minimumD = values[values.size() - 1];
    for (size_t i = 0; i < values.size()-1; i++)
    {
       minimumD = min(minimumD, values[i + 1] - values[i]);
    }

    return minimumD;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    int rootindex = nums.size() / 2;

       
}
 
 

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
