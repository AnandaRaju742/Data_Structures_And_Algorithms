/*
	Leetcode:
	https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/submissions/
*/

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> queries_cnt;
        vector<int> word_cnt;
        map<char,int> find_cnt;
        for(string &s:queries)
        {
            for(char c:s)
            {
                find_cnt[c]++;
            }
            auto it=find_cnt.begin();
            //pair p=(*it);
            //queries_cnt[s]=(*it).second;
            queries_cnt.push_back((*it).second);
            find_cnt.clear();
        }
        for(string &s:words)
        {
            for(char c:s)
            {
                find_cnt[c]++;
            }
            auto it=find_cnt.begin();
            //pair p=(*it);
            //word_cnt[s]=(*it).second;
            word_cnt.push_back((*it).second);
            find_cnt.clear();
        }
        //copy(queries_cnt.begin(),queries_cnt.end(),ostream_iterator(cout," "));
        /*for(pair p:queries_cnt)
        {
            cout<<p.first<<" "<<p.second<<endl;
        }
        cout<<endl;
        for(pair p:word_cnt)
        {
            cout<<p.first<<" "<<p.second<<endl;
        }*/
        vector<int> result;
        for(int i=0;i<queries_cnt.size();++i)
        {
            int count=0;
            for(int j=0;j<word_cnt.size();++j)
            {
                if(queries_cnt[i]<word_cnt[j])
                    count++;
                    
            }
            result.push_back(count);
        }
        return result;
    }