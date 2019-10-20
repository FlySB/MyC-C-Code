#include <stdio.h>

#define MAXSIZE 1000
int sum = 0;

void MergeAndCountNum(int *a, int start, int mid, int end, int *b){
    int p1 = start; //左边第1位
    int p2 = mid + 1; //右边第1位
    int index = 0;
    while(p1 <= mid && p2 <= end){ //p1<=左边最后位且p2<=右边最后位
        if(a[p1] < a[p2]){
            b[index++] = a[p1++]; //p1右移1位
        } else{
            b[index++] = a[p2++]; //p2右移1位
            sum += mid - p1 + 1;  //左边部分p1右边所有元素包括p1都与p2产生逆序
        }
    }
    while(p1 <= mid) //p1与p2必有一边遍历完，未遍历的部分就是大数值部分，直接赋到b后面
        b[index++] = a[p1++];
    while(p2 <= end) //p1与p2必有一边遍历完，未遍历的部分就是大数值部分，直接赋到b后面
        b[index++] = a[p2++];
    for(int i = 0; i < end-start + 1; i++){ //把b赋给a
        a[start+i] = b[i];
    }
}

void MergeSort(int *a, int start, int end, int *b){ //左右递归
    if(start < end){
        int mid = start + (end - start)/2;
        MergeSort(a, start, mid, b);
        MergeSort(a, mid+1, end, b);
        MergeAndCountNum(a, start, mid, end, b);
    }
}

int main() {
    int a[MAXSIZE], b[MAXSIZE];
    int n;
    printf("请输入歌曲数量：");
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        printf("请输入第%d首歌的评分：", (i+1));
        scanf("%d", &a[i]);
    }
    MergeSort(a, 0, n-1, b);
    printf("逆序数为%d\n", sum);
    return 0;
}