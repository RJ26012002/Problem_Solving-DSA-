class Solution {
public:
    string intToRoman(int num) {
                        //     0    1   2   3   4  5  6  7  8  9 10 11 12
       vector<int> intcode = {1000,900,500,400,100,90,50,40,10,9, 5, 4, 1};
       vector<string> symbol={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string output = "";
        for(int i=0;i<intcode.size();i++){
            while(num>=intcode[i]){
                output+=symbol[i];
                num-=intcode[i];
            }
        }
        return output;

        
    }
};