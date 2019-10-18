#include <iostream>
using namespace std;
long long sum = 0;//逆序数的个数
void MergeSort(int * arr,int s,int e,int *temp);//归并排序
void MergeAndCountNum(int * arr,int s,int mid,int e,int *temp); //归并有序序列并计算逆序数的个数
int main(){
	int a[100001],b[100001],n;
	cout << "请输入歌曲数量：";
	cin >> n;
	for(int i=0;i<n;++i){
	    cout << "请输入第" << (i+1) <<"首歌评分：";
		cin >> a[i];}
	MergeSort(a,0,n-1,b);
	cout << sum ;
	return 0;
}

void MergeSort(int * arr,int s,int e,int * temp){//归并排序
	if(s < e){
		int mid = s + (e - s)/2;
		MergeSort(arr,s,mid,temp);
		MergeSort(arr,mid+1,e,temp);
		MergeAndCountNum(arr,s,mid,e,temp);
	}
}
void MergeAndCountNum(int * arr,int s,int mid,int e,int * temp){//归并有序序列并计算逆序数的个数
	int p1 = s, p2 = mid +1,index = 0;
	while(p1 <= mid && p2 <= e){
		if(arr[p1] < arr[p2])
			temp[index++] = arr[p1++];
		else{
			temp[index++] = arr[p2++];
			sum += mid - p1 +1;
		}
	}
	while(p1 <= mid)
		temp[index++] = arr[p1++];
	while(p2 <= e)
		temp[index++] = arr[p2++];
	for(int i = 0;i<e - s +1;++i)
		arr[s+i] = temp[i];
}