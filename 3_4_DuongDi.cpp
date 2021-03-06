// Chuong trinh C++ duyet do thi su dung phuong phap DFS de quy
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#define MAX 100
using namespace std;
// khai bao lop do thi de tao doi tuong do thi
class Dothi{
		int 	n;									// so dinh cua do thi
		int 	A[MAX][MAX];						// ma tran ke cua do thi
	public:
		string	myname;								// ten do thi
		bool	chuaxet[MAX];						// mang luu trang thai da xet hay chua xet cua cac dinh do thi
		int		s, t;								// dinh khoi dau (duyet, duong di v.v.)
		int		soTPLT;								// luu so thanh phan lien thong cua do thi
		int		truoc[MAX];							// mang luu duong di
		void	KhoiTao();							// khoi tao gia tri ban dau cho cac bien...
		void	Reset();							// dat lai gia tri ban dau cho cac bien
		void	Nhap1Dinh();						// nhap 1 dinh tu ban phim
		bool	DocDuLieu(string filename);			// doc ma tran ke tu file: true neu doc OK; false neu khong doc duoc file
		void	DFS_dequy(int u);					// duyet do thi su dung phuong phap duyet theo chieu sau DFS de quy
		void	DFS_nganxep(int u);					// duyet do thi su dung phuong phap duyet theo chieu sau DFS dung ngan xep
		void	BFS_hangdoi(int u);					// duyet do thi su dung phuong phap duyet theo be rong BFS su dung hang doi
		void	Duyet_TPLT();						// duyet, dem cac thanh phan lien thong cua do thi
		void	DuongDi(int s, int t);				// in duong di tu s den t
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
		filevao >> n >> s >> t;
		cout << "\n So dinh cua do thi: " << n;
		cout << "\n Dinh bat dau duong di: " << s << "; dinh cuoi duong di: " << t;
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
		truoc[i]=0;
	}
	soTPLT=0;
}
// ham dat lai gia tri cho cac bien
void Dothi::Reset(){
	for(int i=1; i<=n; i++){
		chuaxet[i]=true;
		truoc[i]=0;
	}
	soTPLT=0;
}
// nhap 1 dinh vao bien s
void Dothi::Nhap1Dinh(){
	cout << "\n Nhap dinh s = "; cin >> s;
}
// duyet do thi su dung pp. duyet theo chieu sau: DFS de quy
void Dothi::DFS_dequy(int u){
	cout << " " << u;							// duyet dinh u
	chuaxet[u]=false;							
	for(int v=1; v<=n; v++){
		if((A[u][v]==1)&&(chuaxet[v]==true)){	// A[u][v]=1 thi v la ke voi u; v chua xet
			DFS_dequy(v);
		}
	}
}
// duyet do thi su dung pp. duyet theo chieu sau: DFS ngan xep
void Dothi::DFS_nganxep(int u){
	stack<int>	nganxep;
	nganxep.push(u);							// day u vao ngan xep
	cout << " " << u;							// duyet dinh u
	chuaxet[u]=false;
	while(!nganxep.empty()){					// ngan xep chua rong
		u=nganxep.top();						// lay mot phan tu o dinh ngan xep
		nganxep.pop();							// loai 1 phan tu dinh ngan xep
		for(int t=1; t<=n; t++){
			if((A[u][t]==1)&&(chuaxet[t]==true)){// t la k cua u; t chua xet
				nganxep.push(u);				// dua dinh u vao ngan xep
				nganxep.push(t);				// dua dinh t vao ngan xep
				cout << " " << t;				// tham dinh t
				chuaxet[t]=false;				// da xet dinh t
				truoc[t]=u;						// luu dinh truoc cua dinh t tren duong di
				break;
			}
		}
	}
}
// duyet do thi theo phuong phap duyet theo be rong BFS su dung hang doi
void Dothi::BFS_hangdoi(int u){
	queue<int>	hangdoi;
	int	s;
	hangdoi.push(u);
	chuaxet[u]=false;
	while(!hangdoi.empty()){
		s=hangdoi.front();						// lay dinh dau tien cua hang doi
		hangdoi.pop();							// loai dinh dau tien
		cout << " " << s;
		for(int t=1; t<=n; t++){
			if((A[s][t]==1)&&(chuaxet[t]==true)){//t la ke voi s; t chua xet
				hangdoi.push(t);				// dua t vao hang doi
				chuaxet[t]=false;
				truoc[t]=s;						// luu dinh truoc cua dinh t tren duong di
			}
		}
	}
}
// ham duyet, dem cac thanh phan lien thong cua do thi
void Dothi::Duyet_TPLT(){
	soTPLT=0;
	for(int u=1; u<=n; u++){					// xet toan bo tap dinh cua do thi
		if(chuaxet[u]==true){
			soTPLT++;							// ghi nhan so thanh phan lien thong (tang 1)
			cout << "\n Duyet TPLT tu dinh " << u << " : ";
			DFS_dequy(u);						// duyet do thi bat dau tu dinh u == doi gia tri cua mang chua xet doi voi cac dinh lien thong voi u
		}
	}
	cout << "\n So thanh phan lien thong: " << soTPLT;
}
// ham in duong di tu s den t
void Dothi::DuongDi(int s, int t){
	if(truoc[t]==0){
		cout << "\n Khong co duong di tu " << s << " den " << t;
	}
	else{
		cout << "\n Duong di tu " << s << " den " << t << " : " << t;
		int u = truoc[t];
		while(u!=s){
			cout << " -> " << u;
			u=truoc[u];
		}
		cout << " -> " << s;
	}
}
// bao ten do thi
void Dothi::TraLoi(){
	cout << myname;
}
// ham main
int main(){
	Dothi	G;									// G: graph object
	G.TraLoi();
	//if(G.DocDuLieu("3_1_DFS.in")){
	//if(G.DocDuLieu("3_2_BFS.in")){
	//if(G.DocDuLieu("3_3_TPLT.in")){
	if(G.DocDuLieu("3_4_Path_DFS_BFS.in")){
		//cout << "\n Doc file OK";
		G.KhoiTao();							// chuaxet[1..n]=true;
		//G.Nhap1Dinh();							// nhap dinh s
		cout << "\n Duyet DFS de quy tu dinh " << G.s << ": ";
		G.DFS_dequy(G.s);						// duyet de quy tu dinh s
		G.Reset();								// chuaxet[1..n]=true;
		cout << "\n Duyet DFS ngan xep tu dinh " << G.s << ": ";
		G.DFS_nganxep(G.s);						// duyet DFS ngan xep tu dinh s
		G.Reset();								// chuaxet[1..n]=true;
		cout << "\n Duyet BFS ngan xep tu dinh " << G.s << ": ";
		G.BFS_hangdoi(G.s);						// duyet BFS hang doi tu dinh s
		G.Reset();								// chuaxet[1..n]=true;
		cout << "\n Duyet, dem cac thanh phan lien thong:";
		G.Duyet_TPLT();							// duyet, dem cac thanh phan lien thong
		cout << "\n Duyet DFS:";
		G.Reset();								// chuaxet[1..n]=true;
		G.DFS_nganxep(G.s);
		G.DuongDi(G.s, G.t);					// duyet duong di
		cout << "\n Duyet BFS:";
		G.Reset();								// chuaxet[1..n]=true;
		G.BFS_hangdoi(G.s);
		G.DuongDi(G.s, G.t);					// duyet duong di
	}
	else{
		cout << "\n Loi file";
	}
	return 0;
}
