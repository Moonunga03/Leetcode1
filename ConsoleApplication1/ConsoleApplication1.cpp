// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
bool isPalindrome(string s);
bool canConstruct(string ransomNote, string magazine);
vector<string> summaryRanges(vector<int>& nums);

int main()
{
    
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
