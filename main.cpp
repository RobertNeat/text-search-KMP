#include <iostream>
#include <string>

using namespace std;

void menu(){
cout<<endl<<"Menu:"<<endl<<"1) read input"<<endl<<"2) naive algorithm"<<endl<<"3) KMP algorithm (Knuth-Morris-Pratt)"<<endl<<"Choosing:";
}

void naiwny(string text, string searched){
int textLength=text.size();
int searchedLength=searched.size();

cout<<"First indexes found in searched text (indexes from 0):";

    int a=0,b=0;
    while(a<=(textLength-searchedLength)){
        b=0;
        while(b<searchedLength && searched[b]==text[a+b]){
            b+=1;
        }
        if(b==searchedLength){
            cout<<a<<",";
        }
        a+=1;
    }
cout<<endl;
}

/////////////////////////
void kmp(string text, string searched)
{
    int l_text = text.length();
    int l_searched = searched.length();

    //offset table
    int* P = new int[l_searched + 1];
    int t = 0;
    for (int i = 0;i <= l_searched;i++)
    {
        P[i] = 0;
    }
    for (int i = 2; i <= l_searched; i++)
    {
        while ((t > 0) && (searched[t] != searched[i - 1]))
        {
            t = P[t];
        }
        if (searched[t] == searched[i - 1])
        {
            t++;
        }
        P[i] = t;
    }


    int i = 0, j = 0;
    cout << "searched " << searched << " begins at indexes: ";
    while (i < l_text - l_searched + 1)
    {
        while (searched[j] == text[i + j] && j < l_searched)
        {
            j++;
        }

        if (j == l_searched)
        {
            cout << i << ", ";
        }

        i = i + max(1, (j - P[j]));
        j = P[j];
    }
    cout << endl <<endl;
}
/////////////////////////////



int main()
{
    int a=1;
    menu();
    cin>>a;
    string searched="",text="";

    while(a!=0){
        if(a==1){ //data input
                cin.ignore();
                cout<<"Write searched text:";
                getline(cin,searched);
                cout<<"Write text in which we will search:";
                getline(cin,text);

                menu();
                cin>>a;
        }

        if(a==2){ //naive algorithm
                naiwny(text,searched);
                menu();
                cin>>a;
        }
        if(a==3){ //KMP algorithm
                kmp(text,searched);
                menu();
                cin>>a;

        }
    }
    return 0;
}
