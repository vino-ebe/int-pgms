#include<iostream>
#include<string>

using namespace std;

int main()
{
    //string dict[10] = {"vino","julie","sam","leet","magic","rush","code",
      //                  "fb","juniper"};

    string dict[10] = {"cat", "cats", "and", "sand", "dog"};

    string s = "catsanddog";

    string final;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            if(dict[i].size() < s.size())
            {
                if(s.substr(j,dict[i].size()) == dict[i])
                {
                    if(final.empty())
                    {
                        final = dict[i];
                    }
                    else
                    {
                        final += " ";
                        final += dict[i];
                    }
                }
            }
        }
    }

    cout<<"Final:"<<final<<endl;
}


