#include "default.h"
#include "BinarySearchTree.h"

char * trim(char * line);

int main() {


	BinarySearchTree * bstTree = new BinarySearchTree() ;
	
	string file_name, map_name; 
	getline(cin,file_name);
	getline(cin,map_name);
	ifstream infile(file_name.c_str());
	ifstream inmap(map_name.c_str());

	if(!infile || !inmap){
		cout << "input correct file name " <<endl;
		return -1;
	}

	string map_line;
	while(getline(inmap,map_line)){
		size_t indexOfColon = map_line.find(":");
		string key = map_line.substr(0,indexOfColon);
		string value = map_line.substr(indexOfColon+1);
		
		char temp1[key.length()] ;
		char temp2[value.length()] ;

		strcpy(temp1,key.c_str());
		strcpy(temp2,value.c_str());

		key = trim(temp1);
		value = trim(temp2);

		bstTree->insert(key,value);


	}

	string file_line;
	while(!infile.eof()){

		char temp = '\0';
		infile >> file_line;
		
		string file_line2 = file_line;
			
		temp = file_line.at(file_line.size()-1);
		bool flag = false;
		
		if (temp==','|| temp=='!' || temp=='?'|| temp=='.' || temp==';'){
		    flag = true;
		    file_line = file_line.substr(0,file_line.size()-1);
		}
		    
		string target = bstTree->getData(file_line);
		string target2 = bstTree->getData(file_line2);
		
		
		if (!target.empty()) file_line= target ;
        if (!target2.empty()){
            flag = false ;
            file_line = target2;
        }
        
        if (flag==true) cout << file_line << temp ;
        else cout << file_line ;
        
        if(infile.peek()==' '){
            cout << " " ;
        
        }
		if(infile.get() == '\n'){
			cout << endl;
		}
		
	}
	
	infile.close();
	inmap.close();
	delete bstTree ;
	
	return 0;

}

char * trim(char * s){

	int len = strlen(s) ;
	int i= 0;
	int j= len-1 ;

	char newChar[len] ;

	while(s[i]==' '){
		i++ ;
	}

	while(s[j]==' '){
		j-- ;
	}

	if(i>0 || j<len-1){
		
		int k ;
		for(k=0; k<= j-i ; k++){
			newChar[k] = s[k+i];
		}
		
		newChar[k] = 0x0;
		strcpy(s,newChar);
	}

	return s ;

}



