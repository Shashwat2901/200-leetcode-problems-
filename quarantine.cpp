1. class Solution
{
public:
    void reverseString(vector<char> &S)
    {
        int s = 0;
        int e = S.size() - 1;
        while (s < e)
        {
            swap(S[s], S[e]);
            s++;
            e--;
        }
    }
};
2. class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
3. class Solution
{
public:
    int singleNumber(vector<int> &V)
    {
        int ans = V[0];
        for (int i = 1; i < V.size(); i++)
            ans = (ans ^ V[i]);
        return ans;
    }
};
4. class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> Z;
        for (int i = 1; i <= n; i++)
        {
            if ((i % 3 == 0) && (i % 5 == 0))
                Z.push_back("FizzBuzz");
            else if (i % 3 == 0)
                Z.push_back("Fizz");
            else if (i % 5 == 0)
                Z.push_back("Buzz");
            else
            {
                int temp = i;
                string S = "";
                while (temp)
                {
                    char x = char(temp % 10) + 48;
                    // cout<<"x "<<x<<endl;
                    S = x + S;
                    temp /= 10;
                }
                Z.push_back(S);
            }
        }
        return Z;
    }
};
5. class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        /* ListNode *current=head;
        ListNode *prev=NULL;
        ListNode *next=NULL;
        while(current){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;*/
        //Recursive sol
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *head1 = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return head1;
    }
};

6. class Solution
{
public:
    void deleteNode(ListNode *node)
    {

        node->val = node->next->val;
        ListNode *temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

7. class Solution
{
public:
    void moveZeroes(vector<int> &V)
    {
        int s = 0;
        for (int i = 0; i < V.size(); i++)
        {
            if (V[i] != 0)
            {
                swap(V[i], V[s]);
                s++;
            }
        }
        /* for(int i=s;i<V.size();i++){
            V[i]=0;
        }*/
    }
};

8. class Solution
{
public:
    int majorityElement(vector<int> &V)
    {
        int assume = V[0], c = 1;
        for (int i = 1; i < V.size(); i++)
        {
            if (c == 0)
            {
                c = 1;
                assume = V[i];
                continue;
            }
            if (V[i] == assume)
            {
                c++;
            }
            else
                c--;
        }
        return assume;
    }
};
9. TreeNode *f(vector<int> &V, int s, int e)
{

    if (s > e)
        return NULL;
    int m = (s + e) / 2;
    TreeNode *root = new TreeNode(V[m]);
    root->left = f(V, s, m - 1);
    root->right = f(V, m + 1, e);
    return root;
}
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &V)
    {
        if (V.empty())
            return NULL;
        return f(V, 0, V.size() - 1);
    }
};
10. class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int V[256] = {0};
        for (int i = 0; i < s.length(); i++)
            V[s[i]]++;
        for (int i = 0; i < t.length(); i++)
            V[t[i]]--;

        for (char i = 'a'; i <= 'z'; i++)
        {
            if (V[i] > 0)
            {
                // cout<<"I "<<V[i];
                return false;
            }
        }
        return true;
    }
};