/*�鲢���� 
*/
#include<iostream>
using namespace std;

void zaifen(int *,int,int);
void bijiao(int *,int,int);
int main()
{
	int a[]={5,6,7,11,25,45,14,2,65,9,44};
	int a_length=sizeof(a)/sizeof(a[0]);
	int p=0;                          //ǰ������鳤�� 
	int q=0;                          //�������鳤�� 
	p=a_length/2;
	q=a_length-p;
	zaifen(a,p,q);
	bijiao(a,p,q);
	for(int i=0;i<a_length;i++)cout<<a[i]<<endl;
	return 0;
 } 
 
 void zaifen(int c[],int p,int q)
 {
 	int p1=0,p2=0;
 	int q1=0,q2=0;
 	if(p>3)                          //�ݹ��ٷ�����Ϊ�����ٷ����� 
	 {
 		p1=p/2;
 		q1=p-p1;
 		zaifen(c,p1,q1);
 		bijiao(c,p1,q1);
 	} else
 	{
 		int key=0;
 		for(int i=0;i<p;i++)
		{
		 	for(int j=i+1;j<p;j++)
		 	{
		 		key=c[i];
		     	if(c[j]>c[i])
		 		{
		 			c[i]=c[j];
		 			c[j]=key;
				 }
			 }
		 }
	 }
 	if(q>3)
	 { 
 		p2=q/2;
 		q2=q-p2;
 		zaifen(&c[p],p2,q2);
 		bijiao(&c[p],p2,q2);
	 } else                             //�Բ����ٷ��������� 
	 {
	 	int key=0;
		for(int i=0;i<q;i++)
		{
		 	for(int j=i+1;j<q;j++)
		 	{
		 		key=c[p+i];
		 		if(c[p+j]>c[p+i])
		 		{
		 			c[p+i]=c[p+j];
		 			c[p+j]=key;
				 }
			 }
		 }
	 }
}
void bijiao(int c[],int p,int q)
{
	int num=p+q;                     //����������ܳ���
	int j=0,k=0;
	int *cf=new int[p];             //ǰ�������ĸ��� 
//	int cf_i=0;
//	int n=0;                        //�ж��Ƿ���Ҫ������������븱�� 
	for(int i=0;i<num;i++)
	{
		if(i<p)cf[i]=c[i]; 
		if(j==p)
		{
			c[i]=c[p+k];
			k++;
			continue;
		}
		if(k==q||cf[j]>c[p+k])
		{
		    c[i]=cf[j];
			j++;
			continue;		
		}
		else
		{
		    c[i]=c[p+k];
			k++;
		}	
	}
	delete []cf;
 }
