#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
char id[20];
string yy = "", mm = "", dd = "";
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		scanf("%s", id);
		int x = (id[0] - '0')*10 + id[1] - '0';
		string province;
		switch(x){
			case 11:province = "Beijing";break;
            case 31:province = "Shanghai";break;
            case 21:province = "Liaoning";break;
            case 33:province = "Zhejiang";break;
            case 54:province = "Tibet";break;
            case 71:province = "Taiwan";break;
            case 81:province = "Hong Kong";break;
            case 82:province = "Macao";break;
            default :break;
		}
		yy = "", mm = "", dd = "";
		int idx1 = 6;
		while(idx1 <= 9){
			yy += id[idx1++];
		}
		while(idx1 <= 11){
			mm += id[idx1++];
		}
		while(idx1 <= 13){
			dd += id[idx1++];
		}
		cout <<"He/She is from "<<province<<",and his/her birthday is on "<<mm<<","<<dd<<","<<yy<<" based on the table."<<endl;
	}
	return 0;
}