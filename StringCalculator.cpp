// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class StringCalculator{
    public:
    
    int add(string numbers);
};
int StringCalculator :: add(string input){
    int n = input.size();
    
    if(n == 0) return 0;
    
    // if only a single character ...
    if(n == 1){
        if(input[0] < 'a'){
            int x = stoi(input);
            return x;
        }
        
        else{ 
            int x = input[0] - 'a';
            return x+1;
        }
    }
    
    
    // // only a negative number ... 
    // if(n == 2 && input[0] == '-'){
    //     throw invalid_argument("Negatives not allowed " + input);
    // }
    
    string x = "", negatives = "";
    int sum = 0;
    
    // for(int i=0; i<n; i++){
    //     cout<<input[i];
    // }
    
    // condition no. 2 of including as many numbers is handled here...
    for(int i=0; i<n; i++){
        if(input[i] == ','){
            
            
            
            // a negative number ...
            if(x[0] == '-'){
                negatives += x;
                negatives += " ";
                x = "";
                
            }
            
            else if(x[0]<'a'){
                int temp = stoi(x);
                
                // checking condition no. 6
                // number > 1000 to be excluded ...
                if(temp>1000) sum+=0;
                
                else{
                    sum+=temp;
                }
                
                x = "";
            }
            
            else{
                // its alphabet...  condition no. 3
                int z = x[0]-'a';
                z+=1;
                sum += z;
                x = "";
            }
            
            
        }
        else{
            x+=input[i];
        }
    }
    
    // end number remains...
    
    // a negative number ...
    if(x[0] == '-'){
        negatives += x;
        negatives += " ";
        x = "";
                
    }
    
    // a number...
    else if(x[0]<'a'){
        int temp = stoi(x);
                
        if(temp>1000) sum+=0;
                
        else{
            sum+=temp;
        }
                
        x = "";
    }
    
    
    else{
        // its alphabet...  condition no. 3
        int z = x[0]-'a';
        z+=1;
        sum += z;
        x = "";
    }
    
    
    // condition 4 and 5 checked here...
    if(negatives.size() != 0){
        throw invalid_argument("Negatives not allowed " + negatives);
    }
    
    return sum;
}

int main() {
    // Write C++ code here
    
    string input;
    getline(cin, input);
    StringCalculator sc;
    cout<<sc.add(input)<<endl;
    return 0;
}
