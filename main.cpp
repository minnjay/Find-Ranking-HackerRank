#include "stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'numPlayers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY scores
 */

//737

int numPlayers(int k, vector<int> scores) 
{

    bool swapped;
    int rnum = 1;
    int num = k;
    vector<int> rank;
    for(int i = 0; i < scores.size()-1; i++)
    {
        swapped = false;
        for(int a = scores.size()-1; a >= 1+i ; a--)
        {
            if(scores[a-1] < scores[a])
            {
                int temp = scores[a-1];
                scores[a-1] = scores[a];
                scores[a] = temp;
                swapped = true;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
      
    for(int a = 0; a<scores.size(); a++)
    {
        rank.push_back(rnum);
        rnum ++;
        if( a != scores.size()-1)
        {
             if(scores[a] == scores[a+1])
             {
                 rnum --;
             }
        }
    }

    for(int a = k; a<rank.size(); a++)
    {
        if(rank[a-1] == rank[a])
        {
            num++;
        }
        else
        {
            break;
        }
    }

    return num;

}

int main()
{
    ifstream in("input004.txt");

    string k_temp;
    getline(in, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string scores_count_temp;
    getline(in, scores_count_temp);

    int scores_count = stoi(ltrim(rtrim(scores_count_temp)));

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        string scores_item_temp;
        getline(in, scores_item_temp);

        int scores_item = stoi(ltrim(rtrim(scores_item_temp)));

        scores[i] = scores_item;
    }

    int result = numPlayers(k, scores);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
