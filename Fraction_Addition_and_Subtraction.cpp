//LeetCode 592
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        int i=0,numerator=0,denominator=1;
        bool isnegative;
        
        if(expression[i]>='0' && expression[i]<='9'){  //checking if the first fraction is not a negative fraction
            int tempNumerator=0,tempDenominator=0;
            while(i<expression.length() && expression[i]>='0' && expression[i]<='9'){
                tempNumerator=tempNumerator*10+(expression[i]-'0');
                i++;
            }

            i++;
            while(i<expression.length() && expression[i]>='0' && expression[i]<='9'){
                tempDenominator=tempDenominator*10+(expression[i]-'0');
                i++;
            }

            numerator=tempNumerator;
            denominator=tempDenominator;
        }

        while(i<expression.length()){  //loop to  find the numerator and the denominator
            
            int tempNumerator=0,tempDenominator=0;

            if(expression[i]=='-')
                isnegative=true;
        
            else
                isnegative=false;
            
            i++;
            
            while(expression[i]>='0' && expression[i]<='9'){
                tempNumerator=tempNumerator*10+(expression[i]-'0');
                i++;
            }

            i++;

            while(i<expression.length() && expression[i]>='0' && expression[i]<='9'){
                tempDenominator=tempDenominator*10+(expression[i]-'0');
                i++;
            }

            if(isnegative)
                tempNumerator*=-1;

            numerator=numerator*tempDenominator + tempNumerator*denominator;

            denominator=denominator*tempDenominator;
        }

        int gcd=abs(__gcd(numerator,denominator));

        numerator/=gcd;
        denominator/=gcd;

        string result="";

        result=to_string(numerator)+'/'+to_string(denominator);

        return result;
    }
};

int main(){
    Solution Obj;

    cout<<Obj.fractionAddition("-1/2+1/2");  //"-1/2+1/2"

    cout<<endl;
    
    cout<<Obj.fractionAddition("-1/2+1/2+1/3");  //"-1/2+1/2+1/3"

    cout<<endl;
    
    cout<<Obj.fractionAddition("1/3-1/2");  //1/3-1/2
}