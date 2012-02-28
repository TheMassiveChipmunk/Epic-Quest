#include <iostream>
#include <string>
using namespace std;

void decrypt(string & str);

int main()
{
    string spoiler("_l~~lol}+t~+lwtp9"
		   "+Vp}}trly+mpnzxp~+s€xly+lrlty9");

    decrypt(spoiler);
    cout << spoiler << endl;

    cin.get();
    return 0;
}

void decrypt(string & str)
{
    for (unsigned i=0; i<str.length(); i++)
        str[i]-=11;
}
