//problem link:- https://leetcode.com/problems/counting-bits/submissions/

//Brute force approach:-

//time complexity: O(nlogn)
//space complexity: O(n+1)

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            sum = 0;
            int number = i;
            while (number >= 2)
            {
                sum = sum + number % 2;
                number = number / 2;
            }
            if (number == 1)
            {
                sum += 1;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

//Second Approach:--
//Time complexity: O(n), space complexity: O(n)

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> answer(n);
        answer.push_back(0);
        if (n == 0)
            return answer;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
                answer[i] = answer[i / 2];
            else
                answer[i] = answer[i - 1] + 1;
        }
        return answer;
    }
};