/*
* 先按左端点排序，再维护一个区间，与后面一个个区间进行三种情况的比较，存储到数组里去。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MergeSeges {
    typedef pair<int, int> pii;
    vector<pii> nums, res;
    int st, ed;
public:
    void init() {
        //ed代表区间结尾，st代表区间开头
        int st = -2e9, ed = -2e9;
    }
    void MergeSege() {

        //以下为区间合并代码
        sort(nums.begin(), nums.end());//按左端点排序

        for (auto num : nums)
        {
            if (ed < num.first) //情况1：两个区间无法合并
            {
                if (ed != -2e9) res.push_back({ st,ed });//区间1放进res数组
                
                st = num.first, ed = num.second;//维护区间2
            }

            //情况2：两个区间可以合并，且区间1不包含区间2，区间2不包含区间1
            else if (ed < num.second) ed = num.second;//区间合并
        }

        //(实际上也有情况3：区间1包含区间2，此时不需要任何操作，可以省略)

        //注：排过序之后，不可能有区间2包含区间1

        if (ed != -2e9) res.push_back({ st,ed }); // ed 和 st 可以互换

        //考虑循环结束时的st,ed变量，此时的st,ed变量不需要继续维护，只需要放进res数组即可。
        //因为这是最后的一个序列，所以不可能继续进行合并

    }

};