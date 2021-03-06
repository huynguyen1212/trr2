#include <bits/stdc++.h>
#define MAX 100
using namespace std;

class Dothi{
		int 	n;									// so dinh cua do thi
		int 	A[MAX][MAX];						// ma tran ke cua do thi
	public:
		string	myname;								// ten do thi
		bool	DocDuLieu(string filename);			// doc ma tran ke tu file: true neu doc OK; false neu khong doc duoc file
		int		IsEuler(int &u, int &v);			// kiem tra xem do thi co phai la do thi Euler khong? tra lai true neu dung, false neu sai
		void	EulerCycle(int u);					// liet ke chu trinh Euler tu dinh u tren do thi Euler
		Dothi();									// Contructor
		void	TraLoi();							// phuong thuc bao ten doi tuong do thi
};
Dothi::Dothi(){
	myname=" \n My graph";							// proper initiation: khoi dung dung cach
}

bool Dothi::DocDuLieu(string filename){
	ifstream	filevao(filename.c_str());			// mo filevao chua du lieu ma tran ke
	if(filevao.is_open()){
		filevao >> n;
		//filevao >> n >> s >> t;
		cout << "\n So dinh cua do thi: " << n;
		//cout << "\n Dinh bat dau duong di: " << s << "; dinh cuoi duong di: " << t;
		cout << "\n Ma tran ke:";
		for(int i=1; i<=n; i++){
			cout << "\n";
			for(int j=1; j<=n; j++){
				filevao >> A[i][j];	cout << " " << A[i][j];
			}
		}
		return true;
	}
	return false;
}

int	Dothi::IsEuler(int &u, int &v){
	int dem=0;													// dem so dinh bac le
	for(int i=1; i<=n; i++){									// kiem tra tat ca cac hang cua ma tran ke == tap dinh cua do thi
		int sum=0;
		for(int j=1; j<=n; j++){								// lay tong cac phan tu tren hang
			sum+=A[i][j];
		}
		if(sum%2==1){											// dem so dinh bac le trong do thi
			dem++;
			if(dem==1) u=i;										// lay dinh bac le thu nhat
			if(dem==2) v=i;										// lay dinh bac le thu hai
		}
	}
	if(dem==0)	return 1;										// 1: do thi Euler, tat ca cac dinh deu bac chan;
	if(dem==2)	return 2;										// 2: do thi nua Euler;
	return 0;													// khong co 0 hoac 2 dinh bac le => do thi ko phai la nua Euler
}

// liet ke chu trinh Euler tu dinh u tren do thi Euler
void	Dothi::EulerCycle(int u){
	stack<int>	nganxep;
	stack<int>	CE;												// CE: luu chu trinh Euler
	nganxep.push(u);
	while(!nganxep.empty()){									// ngan xep chua rong
		int s=nganxep.top();									// lay 1 dinh tu dinh ngan xep
		int t;
		for(t=1; t<=n; t++){									// tim dinh ke dau tien cua s
			if(A[s][t]==1){										// dinh t ke voi dinh s
				nganxep.push(t);								// day t vao dinh ngan xep
				A[s][t]=0;	A[t][s]=0;							// xoa bo canh (s,t)
				break;
			}
		}
		if(t>n){												// Ke(s) = rong
			int s=nganxep.top();								// lay dinh ngan xep
			nganxep.pop();										// loai bo dinh ngan xep
			CE.push(s);											// dua s vao CE
		}
	}
	// In chu trinh Euler
	while(!CE.empty()){											// lay tu dinh CE, moi lan 1 phan tu
		if(CE.size()>1){
			cout << CE.top() << " -> ";
			CE.pop();
		}
		else{
			cout << CE.top();
			CE.pop();
		}
	}
}

void Dothi::TraLoi(){
	cout << myname;
}

int main() {
	int u, v;
	Dothi	G;									// G: graph object
	G.TraLoi();
	if(G.DocDuLieu("4_1_EulerPath.in")){
		cout << "\n Kiem tra do thi co phai do thi Euler?";
		int result=G.IsEuler(u, v);
		if((result==1)||(result==2)){
			if(result==1){
				cout << "\n Do thi Euler";
				cout << "\n Chu trinh Euler:\n";
				G.EulerCycle(6);						// in chu trinh Euler tu dinh 1
			}
			else{
				cout << "\n Do thi nua Euler";
				cout << "\n Duong di Euler:\n";
				G.EulerCycle(v);						// in chu trinh Euler tu dinh 1
			}
		}
		else{
			cout << "\n Khong phai do thi Euler";
		}
	}
	else {
		cout << "\n Loi file";
	}
	return 0;
}
