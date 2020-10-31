#include <bits/stdc++.h>
#define MAX 100
using namespace std;

struct	dinh{
		int	num, id;								// vertex number, identification
};

struct	canh{
		dinh	u, v;								// dinh dau, dinh cuoi
													// quy uoc: u.num < v.num
		int		c;									// trong so cua canh
};

class Dothi{
		int 	n;									// so dinh cua do thi
		int 	A[MAX][MAX];						// ma tran ke cua do thi
		int		ne, neT;							// so canh cua do thi va cua cay
		canh	E[MAX], ET[MAX];					// tap canh cua do thi va cua cay
	public:
		string	myname;								// ten do thi
		bool	chuaxet[MAX];						// mang luu trang thai da xet hay chua xet cua cac dinh do thi
		void	KhoiTao();							// khoi tao gia tri ban dau cho cac bien...
		bool	DocDuLieu(string filename);			// doc ma tran ke tu file: true neu doc OK; false neu khong doc duoc file
		void	Tree_DFS_dequy(int u);				// ham xay dung cay khung cua do thi (theo DFS de quy)
		void	Tree_Graph(int root);				// goi cac ham xay dung cay bao trum
		Dothi();									// Contructor
		void	TraLoi();							// phuong thuc bao ten doi tuong do thi
};

Dothi::Dothi(){
	myname=" \n My graph";							// proper initiation: khoi dung dung cach
	ne=0;	neT=0;									// khoi tao so canh do thi ne = 0; so canh cay khung neT=0
}
// Member functions
// doc file du lieu ma tran ke cua do thi
bool Dothi::DocDuLieu(string filename){
	ifstream	filevao(filename.c_str());			// mo filevao chua du lieu ma tran ke
	if(filevao.is_open()){
		cout << "\n File vao: " << filename;
		filevao >> n;
		cout << "\n So dinh cua do thi: " << n;
		cout << "\n Ma tran ke:";
		for(int i=1; i<=n; i++){
			cout << "\n";
			for(int j=1; j<=n; j++){
				filevao >> A[i][j];	
				cout << " " << A[i][j];
				// voi do thi vo huong
				if((A[i][j]!=0)&&(j>i)){			// (i,j) la canh, chi dem j>i
					ne++;							// tang so canh cua do thi
					E[ne].u.num=i;	E[ne].v.num=j;	// gan dinh dau, cuoi cua canh
					//cout << "\n Canh " << ne << ": " << E[ne].u.num << ", " << E[ne].v.num;
				}
			}
		}
		//for(int i=1; i<=ne; i++){
		//	cout << "\n Canh " << i << ": " << E[i].u.num << ", " << E[i].v.num;
		//}
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

void Dothi::Tree_DFS_dequy(int u){
	//cout << " " << u;							// duyet dinh u
	chuaxet[u]=false;							
	for(int v=1; v<=n; v++){
		if((A[u][v]==1)&&(chuaxet[v]==true)){	// A[u][v]=1 thi v la ke voi u; v chua xet
			neT++;								// tang so canh cay khung len 1
			if(v>u){
				ET[neT].u.num=u;	ET[neT].v.num=v;				
			}
			else{
				ET[neT].u.num=v;	ET[neT].v.num=u;
			}
			Tree_DFS_dequy(v);
		}
	}
}
// goi cac ham xay dung cay bao trum
void Dothi::Tree_Graph(int root){
	Tree_DFS_dequy(root);
	//cout << "\n neT = " << neT;
	if(neT<n-1){
		cout << "\n Do thi khong lien thong.";
	}
	else{										// neT=n-1
		cout << "\n Tap canh cua cay bao trum:";
		for(int i=1; i<=neT; i++){
			cout << "\n Canh " << i << ": " << ET[i].u.num << ", " << ET[i].v.num;
		}
	}
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
	if(G.DocDuLieu("5_1_SpanningTree.in")){
		G.KhoiTao();
		G.Tree_Graph(13);								// XD va liet ke cay bao trum tu dinh 1
	}
	else{
		cout << "\n Loi file";
	}
	return 0;
}

