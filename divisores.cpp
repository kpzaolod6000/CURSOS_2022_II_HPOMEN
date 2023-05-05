#include<iostream>

using namespace std;
int main(int argc, char** argv){
	
	int div = atoi(argv[1]);
	for (int i=1;i<=div;i++){
	 	if(div%i == 0){
			cout<<i<<" ";
		}
		
	}
	return 0;
}
