#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>
using namespace std;
namespace fs = std::filesystem;
void pre(string m, int *n);
void byos(string *b, string *d, fs::directory_entry p);
int main()
{
    while (1)
    {
        int c;
        string target;
        string change;
        string temp;
        string temp1;
        int delposit;
        char choose;
        cout << "다음중 선택세요\n(1.파일명 일괄 변경/2.n번째 자리 지우기)\n  3.특정 문자열 추가/4.특정 문자열 제거:";
        cin >> choose;
        if (choose == '1')
        {
            cout << "모든파일에 적용하시겠습니까?특정 문자열이 들어가 있을 경우 적용하시겠습니까?(1/2):";
            cin >> choose;
            if (choose == '2')
            {
                cout << "바꾸려는 파일들에 공통적으로 들어 있는것은?";
                cin >> target;
            }
            cout << "바꿀 이름은?";
            cin >> change;
            int count = 0;
            target.shrink_to_fit();
            change.shrink_to_fit();
            for (auto &p : fs::recursive_directory_iterator("./"))
            {
                byos(&temp1, &temp, p);
                if (temp.find(target) != -1 || target.empty())
                {
                    if (temp.find("a.out") != -1 || temp.find("gibumfile.cpp") != -1 || fs::is_directory(p) || (temp1.find(target) != -1 && choose == '2'))
                    {
                        continue;
                    }
                    pre(temp, &c);
                    temp.replace(c, temp.find(".", 1) - c, change + "0" + to_string(count));
                    count++;
                    rename(p, temp.c_str());
                }
            }
        }
        else if (choose == '2')
        {
            int first;
            cout << "어느 번째 짜리부터 지우실지 입력해주세요:";
            cin >> first;
            first--;
            cout << "앞에서부터 몇자리까지 지우실지를 입력해주세요:";
            cin >> delposit;
            cout << "모든파일에 적용하시겠습니까?특정 문자열이 들어가 있을 경우 적용하시겠습니까?(1/2):";
            cin >> choose;
            if (choose == '2')
            {
                cout << "특정 문자열을 입력하여 주십시요:";
                cin >> change;
            }
            change.shrink_to_fit();
            for (auto &p : fs::recursive_directory_iterator("./"))
            {

                if (change.empty() || temp.find(change) != -1)
                {
                    if (temp.find(target) != -1 || target.empty())
                    {
                        if (temp.find("a.out") != -1 || temp.find("gibumfile.cpp") != -1 || fs::is_directory(p) || (temp1.find(change) != -1 && choose == '2'))
                        {
                            continue;
                        }
                        pre(temp, &c);
                        temp.erase(c + first, delposit);
                        rename(p, temp.c_str());
                    }
                }
            }
        }
        else if (choose == '3')
        {
            delposit = -1;
            cout << "문자열을 넣을 위치를 골라주십시오(1.맨앞/2.맨뒤/3.특정 문자열 앞):";
            cin >> choose;
            if (choose == '3')
            {
                cout << "특정 문자열을 입력해주십시요:";
                cin >> target;
            }
            cout << "삽입할 문자열을 입력해주십시오:";
            cin >> change;
            target.shrink_to_fit();
            change.shrink_to_fit();
            for (auto &p : fs::recursive_directory_iterator("./"))
            {
                byos(&temp1, &temp, p);
                temp.shrink_to_fit();
                if (temp.find("a.out") != -1 || temp.find("gibumfile.cpp") != -1 || fs::is_directory(p) || (temp1.find(target) != -1 && choose == '3'))
                {
                    continue;
                }
                if (choose == '1')
                {
                    pre(temp, &delposit);
                }
                else if (choose == '2')
                {
                    delposit = temp.find(".", 1) - 1;
                }
                else if (choose == '3')
                {
                    delposit = temp.find(target);
                }
                if (delposit == -1)
                {
                    continue;
                }
                temp1 = temp.substr(0, delposit);
                temp1 += change + temp.substr(delposit, temp.length());
                rename(p, temp1.c_str());
            }
        }
        else if (choose == '4')
        {
            cout << "지우실 문자열을 입력해주세요";
            cin >> target;
            for (auto &p : fs::recursive_directory_iterator("./"))
            {
                byos(&temp1, &temp, p);
                temp.shrink_to_fit();
                if (temp.find("a.out") != -1 || temp.find("gibumfile.cpp") != -1 || fs::is_directory(p))
                {
                    continue;
                }
                pre(temp, &c);
                int delposit = temp.find(target, c);
                if (delposit == -1)
                {
                    continue;
                }
                temp.erase(delposit, target.length());
                rename(p, temp.c_str());
            }
        }
        cout << "초기 화면으로 돌아가시겠습니까?(yes(5)/no(6)):";
        cin >> c;
        if (c == 6)
        {
            break;
        }
    }
}
void pre(string &m, int &n)
{
    reverse(m.begin(), m.end());
    n = m.find("/");
    n = m.length() - n;
    reverse(m.begin(), m.end());
}
void byos(string *b, string *d, fs::directory_entry p)
{
#ifdef __linux__
    *b = p.path().parent_path();
    *d = p.path();
#endif
#ifdef _WIN32
    wstring forwin;
    forwin = p.path().parent_path();
    b->assign(forwin.begin(), forwin.end());
    forwin = p.path();
    d->assign(forwin.begin(), forwin.end());
#endif
}