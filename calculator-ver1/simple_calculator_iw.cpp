#include <iostream>
#include <string>

using namespace std;

int a = 0;
int b = 0;
char c = 0;
int d = 0;

string str_a;
string str_b;
string str_c;
string str_d;

void screen_out(string a, string b, string c, string d)
	{
		cout<<"------------------------------------------------------------"<<endl;
		cout<<"[                                                          ]"<<endl;
	
		cout<<"[       ";
		cout.width(20); // 폭을 10으로 지정
		cout.fill(' '); // 채움 문자는 ' '
		cout << a;
		cout<<"                               ]"<<endl;//
	
		cout<<"[                                                          ]"<<endl;
		cout<<"[       ";
		cout.width(20); // 폭을 10으로 지정
		cout.fill(' '); // 채움 문자는 ' '
		cout << b;
		cout<<"                               ]"<<endl;//
		cout<<"[                                                          ]"<<endl;
		cout<<"[       ";
		cout.width(20); // 폭을 10으로 지정
		cout.fill(' '); // 채움 문자는 ' '
		cout << c;
		cout<<"                               ]"<<endl;//
		cout<<"[                                                          ]"<<endl;
		cout<<"[                                                          ]"<<endl;
		cout<<"[       ";
		cout.width(20); // 폭을 10으로 지정
		cout.fill(' '); // 채움 문자는 ' '
		cout << d;
		cout<<"                               ]"<<endl;//
		cout<<"[                                                          ]"<<endl;
		cout<<"------------------------------------------------------------"<<endl;
	}
	
int main()
{
	screen_out("정수 입력1", "정수 입력2", "+-*/ 연산자 입력", "출력");
	while(1)
	{
	
	screen_out("______", "정수 입력2", "+-*/ 연산자 입력", "출력");
	cin>>str_a;
	
	
	screen_out(str_a, "______", "+-*/ 연산자 입력", "출력");
	cin>>str_b;
	
	
	screen_out(str_a, str_b, "______", "출력");
	cin>>c;
	
	str_c = c;
	screen_out(str_a, str_b, str_c, "출력");
	
	
	char* Char_str = str_c.c_str();; 
	
	int i       = atoi(str_c);
	int i = 0;
	switch(c)
	{
		case '+':
			d = a+b;
			break;
		case '-':
			d = a-b;
			break;
		case '*':
			d = a*b;
			break;
		case '/':
			d = a/b;
			break;
		default:
			screen_out(str_a, str_b, str_c, "wrong operator try again");
			i = 1;
			break;
		
	}
	str_d = d;
	screen_out(str_a, str_b, str_c, str_d);
	if(i == 1)
	{
		i = 0;
		break;
	}
	
	
}
	
}