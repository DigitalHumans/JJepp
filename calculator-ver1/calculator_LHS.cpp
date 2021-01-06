/*file name: calculator_LHS.cpp
 *Created: Thu, Dec, 31st
 *auther: Lahesol
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

float ans, x, y, chk = 0;
vector <string> expr;
vector <float> operand;
string name, cname;
int coll = 0, collst = 0, i = 0, colltmp = 0;
/*
void checkinner(void)
{

    colltmp = 1;

    coll = expr.back().find("=", collst);

    if(expr.back().find("+", collst)!=string::npos)
    {
        
        if(name.find("+",collst) < coll)
            coll = name.find("+",collst);
    }
    if(expr.back().find("-", collst)!=string::npos)
    {
        if(name.find("-",collst) < coll)
            coll = name.find("-",collst);
    }
    if(expr.back().find("*", collst)!=string::npos)
    {
        if(name.find("*",collst) < coll)
            coll = name.find("*",collst);
    }
    if(expr.back().find("/", collst)!=string::npos)
    {
        if(name.find("/",collst) < coll)
            coll = name.find("/",collst);
    }
    if(expr.back().find("=", collst)!=string::npos)
    {
        if(name.find("=",collst) == coll)
            coll = name.find("=",collst);

        colltmp = 0;
    }
    expr.pop_back();

    expr.push_back(name.substr(collst,coll-collst));
    expr.push_back(name.substr(coll,1));
            

    collst = coll + 1;

    


}

void checkoper(void)
{

    /*if(expr.back().find("+", collst)!=string::npos)
        {
            colltmp = 1;

            expr.pop_back();

            expr.push_back(name.substr(collst,coll-collst));
            expr.push_back(name.substr(coll,1));
            


        }
    if(expr.back().find("-", collst)!=string::npos)
        {
            colltmp = 1;
            expr.pop_back();
            
            expr.push_back(name.substr(collst,coll-collst));
            expr.push_back(name.substr(coll,1));
            

            

        }
    if(expr.back().find("*", collst)!=string::npos)
        {
            colltmp = 1;
            expr.pop_back();

            expr.push_back(name.substr(collst,coll-collst));
            expr.push_back(name.substr(coll,1));
            

            collst = coll + 1;

        }
    if(expr.back().find("/", collst)!=string::npos)
        {
            colltmp = 1;
            expr.pop_back();

            expr.push_back(name.substr(collst,coll-collst));
            expr.push_back(name.substr(coll,1));
            

            collst = coll + 1;

        }
    if(expr.back().find("=", collst)!=string::npos)
    {
        if(expr.back() == "=")
        {
            collst = coll + 1;

            colltmp = 0;
        
        }


    }
    else
    {
        colltmp = 0;
    }
    

        
}

void calc(void)
{
    for(int j = 0; j<=expr.size(); j++)
     {
         if(j%2 == 0)
         operand.push_back(stof(expr.at(j)));

     }





}
*/ //다항연산고려

void simplecheck(void)
{
    if(name.find("=", collst)!=string::npos)
    {
    if(name.find("+", collst)!=string::npos)
    {
        coll = name.find("+");
        x = stof(name.substr(collst,coll-collst));
        y = stof(name.substr(coll+1,name.length()-1));

        ans = x + y;
        
    }
    else if(name.find("-", collst)!=string::npos)
    {
        coll = name.find("-");
        x = stof(name.substr(collst,coll-collst));
        y = stof(name.substr(coll+1,name.length()-1));

        ans = x - y;
        
    }
    else if(name.find("*", collst)!=string::npos)
    {
        coll = name.find("*");
        x = stof(name.substr(collst,coll-collst));
        y = stof(name.substr(coll+1,name.length()-1));

        ans = x * y;
        
    }
    else if(name.find("/", collst)!=string::npos)
    {
        coll = name.find("/");
        x = stof(name.substr(collst,coll-collst));
        y = stof(name.substr(coll+1,name.length()-1));

        if(y != 0)
            ans = x / y;
        else
        {
            cout << " error " << endl;
        }
        
    }
    }
    else
    {
        if(name.find("+", collst)!=string::npos)
    {
        coll = name.find("+");
        x = stof(name.substr(collst,coll-collst));
        y = stof(name.substr(coll+1,name.length()));

        ans = x + y;
        
    }
    else if(name.find("-", collst)!=string::npos)
    {
        coll = name.find("-");
        x = stof(name.substr(collst,coll-collst));
        y = stof(name.substr(coll+1,name.length()));

        ans = x - y;
        
    }
    else if(name.find("*", collst)!=string::npos)
    {
        coll = name.find("*");
        x = stof(name.substr(collst,coll-collst));
        y = stof(name.substr(coll+1,name.length()));

        ans = x * y;
        
    }
    else if(name.find("/", collst)!=string::npos)
    {
        coll = name.find("/");
        x = stof(name.substr(collst,coll-collst));
        y = stof(name.substr(coll+1,name.length()));

        if(y != 0)
            ans = x / y;
        else
        {
            cout << " error " << endl;
            chk = -1;
        }
        
    }
    }
    

}

int main()
{

    
    cout << " 가능한 연산 종류: +, -, *, / "<< endl;

    cout << "하고자 하는 연산을 알려주세요" << " " << "예: x*y= 또는 x*y" << endl;
    cout << "종료하려면 -1 입력하기" << endl;
    while(1)
    {

    getline(cin, name);

        
        /*do
        {
            if(name.find(" ", collst)!=string::npos)
            {
                coll = name.find(" ",collst);
                if(coll == collst)
                {
                    collst += 1;
                    if(name.find(" ", collst)!=string::npos)
                    {
                        coll = name.find(" ",collst);
                        expr.push_back(name.substr(collst,coll-collst));

                        collst = coll + 1;
                        
                    }
                    else
                    {
                        expr.push_back(name.substr(collst,name.length()-collst));
                        
                    }
            
                }
                else
                {
                    expr.push_back(name.substr(collst,coll-collst));

                    

                }
            }
            else
            {
                expr.push_back(name.substr(collst,name.length()-collst));
            }
        
        expr.push_back(name.substr(collst,name.length()-collst));

        //checkinner();

        }while(colltmp == 1);
        

        

    
     
     for(int j = 0; j<=expr.size(); j++)
     {
         cout << expr.at(j) /*<< " " << coll << endl;
     } */ // 띄어쓰기 고려

     if(name == "-1")
        break;

     simplecheck();

     if(chk == 0)
        cout << ans << endl;

    

    }


    return 0;


}