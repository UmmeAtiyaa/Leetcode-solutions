
class Solution {
public:
    
    int countSeniors(vector<string>& details) {
        int count=0;

        for(const auto& detail : details){
            string age= "";

            age+= detail[11] ;
            age+= detail[12]; 

            int a = stoi(age);
            if ( a > 60 ){
                count++;
            }
        }

        return count;
    }
};
