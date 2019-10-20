#include <stdio.h>

#define MAXSIZE 1000
int sum = 0;

void MergeAndCountNum(int *a, int start, int mid, int end, int *b){
    int p1 = start; //��ߵ�1λ
    int p2 = mid + 1; //�ұߵ�1λ
    int index = 0;
    while(p1 <= mid && p2 <= end){ //p1<=������λ��p2<=�ұ����λ
        if(a[p1] < a[p2]){
            b[index++] = a[p1++]; //p1����1λ
        } else{
            b[index++] = a[p2++]; //p2����1λ
            sum += mid - p1 + 1;  //��߲���p1�ұ�����Ԫ�ذ���p1����p2��������
        }
    }
    while(p1 <= mid) //p1��p2����һ�߱����꣬δ�����Ĳ��־��Ǵ���ֵ���֣�ֱ�Ӹ���b����
        b[index++] = a[p1++];
    while(p2 <= end) //p1��p2����һ�߱����꣬δ�����Ĳ��־��Ǵ���ֵ���֣�ֱ�Ӹ���b����
        b[index++] = a[p2++];
    for(int i = 0; i < end-start + 1; i++){ //��b����a
        a[start+i] = b[i];
    }
}

void MergeSort(int *a, int start, int end, int *b){ //���ҵݹ�
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
    printf("���������������");
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        printf("�������%d�׸�����֣�", (i+1));
        scanf("%d", &a[i]);
    }
    MergeSort(a, 0, n-1, b);
    printf("������Ϊ%d\n", sum);
    return 0;
}