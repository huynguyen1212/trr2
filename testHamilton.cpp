#include <bits/stdc++.h>
#define MAX 100
using namespace std;

class Dothi{
		int 	n;									// so dinh cua do thi
		int 	A[MAX][MAX];						// ma tran ke cua do thi
	public:
		string	myname;								// ten do thi
		bool	chuaxet[MAX];						// mang luu trang thai da xet hay chua xet cua cac dinh do thi
		int		X[MAX];								// mang X[..] luu chu trinh Hamilton
		void	KhoiTao();							// khoi tao gia tri ban dau cho cac bien...
		bool	DocDuLieu(string filename);			// doc ma tran ke tu file: true neu doc OK; false neu khong doc duoc file
		void	Hmt(int k);							// liet ke cac chu trinh Hamilton (neu co) cua do thi cho truoc
		void	Hamilton_Cycle_listing(int v0);		// in cac chu trinh Hamilton (neu co) cua do thi cho truoc
		Dothi();									// Contructor
		void	TraLoi();							// phuong thuc bao ten doi tuong do thi
};

Dothi::Dothi(){
	myname=" \n My graph";							// proper initiation: khoi dung dung cach
}
// doc file du lieu ma tran ke cua do thi
bool Dothi::DocDuLieu(string filename){
	ifstream	filevao(filename.c_str());			// mo filevao chua du lieu ma tran ke
	if(filevao.is_open()){
		cout << "\n File vao: " << filename;
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

// ham khoi tao
void Dothi::KhoiTao(){
	for(int i=1; i<=n; i++){
		chuaxet[i]=true;
	}
}

void	Dothi::Hmt(int k){
	for(int y=1; y<=n; y++){									// XET toan bo tap dinh cua do thi
		if(A[X[k-1]][y]==1){									// y la dinh ke cua dinh X[k-1]
			if((k==n+1)&&(y==X[1])){							// in chu trinh Hamilton
				cout << "\n Chu trinh Hamilton: ";
				for(int i=1; i<=n; i++){
					cout << X[i] << " -> ";
				}
				cout << X[1];
			}
			else{												// thu nhan X[k] va goi de quy Hmt(k+1)
				if(chuaxet[y]==true){
					X[k]=y;										// thu nhan X[k]
					chuaxet[y]=false;							// danh dau y da xet
					Hmt(k+1);
					chuaxet[y]=true;							// Quay lui: tra lai trang thai chuaxet cho y
				}
			}
		}
	}
}
// in cac chu trinh Hamilton (neu co) cua do thi cho truoc
void	Dothi::Hamilton_Cycle_listing(int v0){
	KhoiTao();
	X[1]=v0;
	chuaxet[v0]=false;
	Hmt(2);
}
// bao ten do thi
void Dothi::TraLoi(){
	cout << myname;
}
// ham main
int main(){
	int u, v;
	Dothi	G;									// G: graph object
	G.TraLoi();
	if(G.DocDuLieu("4_2_Hamilton1.in")){

		cout << "\n Liet ke cac chu trinh Hamilton (neu co): ";
		G.Hamilton_Cycle_listing(1);					// Liet ke cac chu trinh Hamilton (neu co)
	}
	else{
		cout << "\n Loi file";
	}
	return 0;
}

