#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <cstring>

using namespace std;

//左右指针法
int Partition_Hoare(vector<int> &a, int left, int right){
    int i = left;
    int j = right;
    int key = a[left];

    while(i != j){
        while(i < j && a[j] >= key)      	 //向左找到小于基准值的值的下标
            j--;
        while(i < j && a[i] <= key)      	 //向右找到大于基准值的值的下标
            i++;
        swap(a[i], a[j]);
    }
    /*   i等于j时跳出循环 当前基准值此时在下标为i的位置(合适的位置)   */
    swap(a[left], a[i]);	                 //最左边的元素变为处于当前合适位置的元素,把基准值放在合适位置
    return i;                                  //返回合适位置(i,j都可以)
}

void Quick_Sort(vector<int> &a, int left, int right){
    if( left >= right )
        return;

    int i = Partition_Hoare(a, left, right);
    Quick_Sort(a, left, i - 1);              //递归左边的部分
    Quick_Sort(a, i + 1, right);             //递归右边的部分
}


void show(vector<int> &v){
    for(auto &x : v)
        cout<<x<<" ";
    cout<<endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    Partition_Hoare(arr, 0, n - 1);

    cout<<endl<<endl;
    show(arr);

    return 0;
}

