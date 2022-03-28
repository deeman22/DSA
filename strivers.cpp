#include <iostream>
#include <vector>
#include <map>
using namespace std;

////////////////////  Set Matrix Zeroes
void setZeroes(vector<vector<int> > &arr)
{

    int n = arr[0].size();
    int m = arr.size();
    bool row = false, col = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[0][i] == 0)
        {
            row = true;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (arr[j][0] == 0)
        {
            col = true;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[j][i] == 0)
            {
                arr[0][i] = 0;
                arr[j][0] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[0][i] == 0)
        {
            for (int j = 1; j < m; j++)
            {
                arr[j][i] = 0;
            }
        }
    }

    for (int j = 1; j < m; j++)
    {
        if (arr[j][0] == 0)
        {
            for (int i = 1; i < n; i++)
            {
                arr[j][i] = 0;
            }
        }
    }
    if (col)
    {
        for (int j = 0; j < m; j++)
        {
            arr[j][0] = 0;
        }
    }
    if (row)
    {
        for (int i = 0; i < n; i++)
        {
            arr[0][i] = 0;
        }
    }
}

///////////////////// Pascal's Triangle
vector<vector<int> > generate(int numRows)
{

    //         vector<vector<int>> pascal(numRows) ;

    //         for(int i=0; i<numRows; i++){
    //             pascal[i].resize(i+1,1);
    //         }
    //         for(int i=2; i<numRows; i++){
    //             for(int j=1; j<i; j++){
    //                 pascal[i][j]= pascal[i-1][j-1]+pascal[i-1][j] ;
    //             }
    //         }
    vector<vector<int> > pascal;

    for (int i = 1; i <= numRows; i++)
    {
        vector<int> temp(i, 1);

        for (int j = 1; j < i - 1; j++)
        {
            temp[j] = pascal[i - 2][j - 1] + pascal[i - 2][j];
        }
        pascal.push_back(temp);
    }
    return pascal;
}
///////////////////// Next permutation
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int k = n - 2;
    int l = n - 1;

    for (; k >= 0; k--)
    {
        if (nums[k + 1] > nums[k])
            break;
    }
    if (k < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                swap(nums[l], nums[k]);
                reverse(nums.begin() + k + 1, nums.end());
                break;
            }
        }
    }
}
///////////////////// kadan's algorithm
int maxSubArray(vector<int> &nums)
{
    int mth = 0;
    int msf = INT_MIN;
    int l = 0, r = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        mth += nums[i];

        if (mth < nums[i])
        {
            mth = nums[i];
            l = r = i;
        }
        if (mth > msf)
        {
            msf = mth;
            r = i;
        }
    }
    // for(int i=l ; i<=r; i++)
    //     cout << nums[i]<<"  ";
    return msf;
}
/////////////////////// sort 0 1 2
void sort012(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {

        if (arr[mid] == 0)
        {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;

            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}
//////////////////////  Best Time to Buy and Sell Stock
int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxPro = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
}
// day 2
////////////////////// rotate matrix
void transpose(vector<vector<int> > &mat)
{

    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
}
void Reverse(vector<int> &arr)
{

    int n = arr.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
void rotate(vector<vector<int> > &matrix)
{

    transpose(matrix);
    for (int i = 0; i < matrix.size(); i++)
        Reverse(matrix[i]);
}
////////////////////// Merge Intervals
vector<vector<int> > merge(vector<vector<int> > &in)
{

    sort(in.begin(), in.end());
    vector<vector<int> > res;
    res.push_back(in[0]);
    int e = 0;

    for (int i = 1; i < in.size(); i++)
    {

        if (in[i][0] <= res[e][1])
        {
            res[e][1] = max(res[e][1], in[i][1]);
        }
        else
        {
            res.push_back(in[i]);
            e++;
        }
    }
    return res;
}
///////////////////////  Merge Sorted Array
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int i = m - 1, j = n - 1, k = m + n - 1;

    while (i >= 0 && j >= 0 && k >= 0)
    {

        if (nums1[i] >= nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
    while (j >= 0 && k >= 0)
    {

        nums1[k--] = nums2[j--];
    }
}
/////////////////////// Find the duplicate in an array of N+1 integers.
int findDuplicate(vector<int> &nums)
{

    int fast = 0, slow = 0;

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (fast != slow);

    int slow2 = 0;

    while (slow != slow2)
    {
        slow = nums[slow];
        slow2 = nums[slow2];
    }
    return slow;
}
/////////////////////// Repeat and Missing Number
vector<int> repeatedNumber(const vector<int> &A)
{
    long long int n = A.size();
    long long int P = n * (n + 1) / 2;               // P = m-d
    long long int Q = n * (n + 1) * (2 * n + 1) / 6; // Q = m2 - d2

    for (int i = 0; i < n; i++)
    {
        P = P - A[i];
        Q = Q - (long long int)A[i] * (long long int)A[i];
    }

    long long int missing = (P + Q / P) / 2;
    long long int duplicate = missing - P;

    vector<int> ans;
    ans.push_back(duplicate);
    ans.push_back(missing);

    return ans;
}
///////////////////////  Inversion of Array (Pre-req: Merge Sort)
long long merge(long long *arr, int l, int h)
{

    int mid = (l + h) / 2 + 1;
    int i = l;
    int j = mid;
    int k = 0;
    int count = 0;

    int temp[h - l + 1] = {0};

    while (i < mid && j <= h)
    {

        if (arr[i] > arr[j])
        {
            count += mid - i;
            temp[k++] = arr[j++];
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }
    while (i < mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= h)
    {
        temp[k++] = arr[j++];
    }
    for (int p = 0; p <= h - l; p++)
    {
        arr[l + p] = temp[p];
    }

    return count;
}

long long mergeSort(long long *arr, int l, int h)
{
    long long count = 0;
    if (l < h)
    {
        int mid = (l + h) / 2;
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid + 1, h);
        count += merge(arr, l, h);
    }
    return count;
}
long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}
//////////////////// Search in a 2d Matrix
bool searchMatrix(vector<vector<int> > &matrix, int target)
{
    int l = 0;
    int h = matrix.size() * matrix[0].size() - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        int row = mid / matrix[0].size();
        int col = mid % matrix[0].size();

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] > target)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}
/////////////////// Pow(x, n)
double myPow(double x, int n)
{

    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    double ans = myPow(ans, abs(n / 2));
    ans *= ans;

    if (n % 2 != 0)
    {
        ans *= x;
    }
    if (n < 0)
    {
        return 1 / ans;
    }
    else
    {
        return ans;
    }
}
//////////////////////// Majority Element (>N/2 times)
int majorityElement(vector<int> &nums)
{

    int elt = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        if (count == 0)
            elt = nums[i];
        if (elt == nums[i])
            count++;
        else
            count--;
    }
    return elt;
}
//////////////////////// Majority Element (>N/3 times)
vector<int> majorityElement2(vector<int> &nums)
{

    int n = nums.size();
    int e1 = 0;
    int e2 = 0;
    int c1 = 0;
    int c2 = 0;

    for (int i = 0; i < n; i++)
    {

        if (e1 == nums[i])
            c1++;
        else if (e2 == nums[i])
            c2++;
        else if (c1 == 0)
        {
            e1 = nums[i];
            c1 = 1;
        }
        else if (c2 == 0)
        {
            e2 = nums[i];
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    c1 = c2 = 0;

    for (int i = 0; i < n; i++)
    {

        if (nums[i] == e1)
            c1++;
        else if (nums[i] == e2)
            c2++;
    }

    vector<int> ans;

    if (c1 > n / 3)
        ans.push_back(e1);
    if (c2 > n / 3)
        ans.push_back(e2);

    return ans;
}
///////////////////////// Grid Unique Paths
int uniquePaths(int m, int n)
{

    //         int ans=0 ;
    //         int lookup[m+1][n+1] ={-1} ;

    //         if(n==1 || m==1)
    //             return 1 ;
    //         else {
    //             ans += uniquePaths(m-1,n)+uniquePaths(m,n-1) ;
    //         }
    //         return ans ;

    int arr[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == 0 || j == 0)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    return arr[m - 1][n - 1];
}
//////////////////////// Reverse Pairs (Leetcode)
#define ll long long

int merge(vector<int> &arr, int l, int mid, int h)
{

    int i = l;
    int j = mid + 1;
    int count = 0;
    //// counting inversions
    for (; i <= mid; i++)
    {
        while (j <= h && arr[i] > (ll)2 * arr[j])
            j++;
        count += j - (mid + 1);
    }
    /////
    i = l;
    j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= h)
    {

        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= h)
    {
        temp.push_back(arr[j++]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i + l] = temp[i];
    }
    return count;
}
int mergeSort(vector<int> &arr, int l, int h)
{
    int mid = l + (h - l) / 2;
    int count = 0;
    if (l < h)
    {
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid + 1, h);
        count += merge(arr, l, mid, h);
    }
    return count;
}
int reversePairs(vector<int> &nums)
{
    int count = 0;
    count = mergeSort(nums, 0, nums.size() - 1);
    return count;
}
/////////////////////// 2-Sum-Problem
vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mp;
    vector<int> ans;
    int s = nums.size();
    for (int i = 0; i < s; i++)
    {
        mp[nums[i]] = i;
    }
    for (int i = 0; i < s; i++)
    {
        int tmp = target - nums[i];
        if (mp.count(tmp) && mp[tmp] != i)
        {
            ans.push_back(i);
            ans.push_back(mp[tmp]);
            return ans;
        }
    }
    return ans;
}
//////////////////////// 4-sum-Problem

////////////////////////
int main()
{
    return 0;
}