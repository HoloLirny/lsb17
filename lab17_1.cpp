#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *d,int n,int m){
	cout << fixed << setprecision(2);
	for(int i=0;i<n*m;i++){
		cout<<d[i];
		if(i%m==m-1){cout<<endl;}
		else cout<<" ";
	}
}

void randData(double *d,int n,int m){
	for(int i=0;i<n*m;i++){
		d[i]=rand()%101;
		d[i]/=100;
	}
}

	void findRowSum(const double *d,double *s1,int n,int m){
		for(int i=0;i<n;i++){
			double l=0;
			for(int j=0;j<m;j++){
				l+=*((d+j)+(m*i));
			}
			s1[i]=l;
		}
	}

void findColSum(const double *d,double *s2,int n,int m){
	int x,y=0;
	s2[y]=0;
	for(int i=0;i<m;i++){
		x=i;
		for(int j=0;j<n;j++){
			s2[y]+=d[x];
			x+=m;
		}
		y++;
		s2[y]=0;
	}
}