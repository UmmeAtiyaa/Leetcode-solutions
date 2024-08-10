class Solution {
public:
    int minimumPushes(string word) {

        if(word.size()<=8)
        return word.size();

        vector <int> f(26);

        for(char ch: word)
        {
            char ch1 = ch - 'a';
            f[ch1]++; 
        }        

        sort(f.rbegin(), f.rend());

        int c1 = 1;
        int cn = 2;
        int c = 0;
        
        for(int i=0; i<f.size(); i++){
            
            if(cn==10)
            {
                c1++;
                cn = 2;
            }

            c += (c1*f[i]);
            cn++;
        }
        return c;
    }
};
