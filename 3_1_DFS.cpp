// Chuong trinh C++ duyet do thi su dung phuong phap DFS de quy
#include <iostream>
#include <string>
#include <fstream>
#define MAX 100
using namespace std;
// khai bao lop do thi de tao doi tuong do thi
class Dothi{
		int 	n;									// so dinh cua do thi
		int 	A[MAX][MAX];						// ma tran ke cua do thi
	public:
		string	myname=" \n My graph";				// ten do thi
		bool	chuaxet[MAX];						// mang luu trang thai da xet hay chua xet cua cac dinh do thi
		int		s;									// dinh khoi dau (duyet, duong di v.v.)
		void	KhoiTao();							// khoi tao gia tri ban dau cho cac bien...
		void	Nhap1Dinh();						// nhap 1 dinh tu ban phim
		bool	DocDuLieu(string filename);			// doc ma tran ke tu file: true neu doc OK; false neu khong doc duoc file
		void	DFS_dequy(int u);					// duyet do thi su dung phuong phap duyet theo chieu sau DFS de quy
		void	TraLoi();							// phuong thuc bao ten doi tuong do thi
};
// doc file du lieu ma tran ke cua do thi
bool Dothi::DocDuLieu(string filename){
	ifstream	filevao(filename.c_str());			// mo filevao chua du lieu ma tran ke
	if(filevao.is_open()){
		filevao >> n;
		cout << "\n So dinh cua do thi: " << n;
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
	for(int i=1; i<=n; i++)
		chuaxet[i]=true;
}
// nhap 1 dinh vao bien s
void Dothi::Nhap1Dinh(){
	cout << "\n Nhap dinh s = "; cin >> s;
}
// duyet do thi su dung pp. duyet theo chieu sau: DFS de quy
void Dothi::DFS_dequy(int u){
	cout << " " << u;
	chuaxet[u]=false;
	for(int v=1; v<=n; v++){
		if((A[u][v]==1)&&(chuaxet[v]==true)){
			DFS_dequy(v);
		}
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
	if(G.DocDuLieu("3_1_DFS.in")){
		//cout << "\n Doc file OK";
		G.KhoiTao();							// chuaxet[1..n]=true;
		G.Nhap1Dinh();							// nhap dinh s
		cout << "\n Duyet DFS de quy tu dinh " << G.s << ": ";
		G.DFS_dequy(G.s);						// duyet de quy tu dinh s
	}
	else{
		cout << "\n Loi file";
	}
	return 0;
}
