#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

string toReadableText(vector<int>decoded) { //converts number into character
    string ans = "";
    for(int i = 0; i<decoded.size(); i++) {
        int temp = static_cast<int>(decoded.at(i));
        temp-=3;
        if(temp%31<=25) {
            char c = 65 + temp%31;
            ans+=c;
        }
        else {
            if(temp%31==26) {
                ans+=" ";
            }
            if(temp%31==27) {
                ans+="\"";
            }
            if(temp%31==28) {
                ans+=".";
            }
            if(temp%31==29) {
                ans+=",";
            }
            if(temp%31==30) {
                ans+="'";
            }
        }
    }
    return ans;
}

int decrypt(int c, int d, int n){//exponentiation by squaring
    vector<int>leftovers;
    while(d>1){
        if(d%2 == 1){
            leftovers.push_back(c);
            --d;
        }
        d /= 2;
        c = (c*c)%n;
        //cout << c << " " << d << endl;
    
        
    }
    //cout << c << " " << d << endl;
    for(auto x: leftovers){
        c = (c*x)%n;
        //cout << c << endl;
    }
    return c;
}

int main()
{
    
    //delcare variables for input
    int e, n, c_len;
    vector<int>c;
    
    //take in input
    
    cin >> e;
    cin >> n;
    
    cin >> c_len;
    
    for(int i = 0; i<c_len; ++i) {
        int temp;
        cin >> temp;
        c.push_back(temp);
    }
    
    //we need to bruteforce p and q (we assume n is small here).
    //start right below sqrt(n)
    
    int p = -1;
    int q = -1;
    
    long start =  static_cast <long>(floor(sqrt(n)));
    if(start%2==0) { //checks to see if even
        start-=1;
    }
    while(start>0) {
        if(n%start==0) {
            p = static_cast<int>(start);
            q = n/p;
            start = 0;
        }
        start-=2; //skips even integers
    }
    
    //Now that we have p and q, let's grab phi
    
    int phi = (p-1)*(q-1);
    

    //we need to check if phi and e are coprime
    if(__gcd(phi, e)!=1) {
        cout << "Public key not valid!";
        return 0;
    }
    
    //We now have all the numbers, lets do some validity checks:
    
    //first, if we didnt get any valid values of p and q, thn uhh that is bad
    //lets assume that means they gave us a bad n values
    
    if(p==-1 || q==-1) {
        cout << "Public key not valid!";
        return 0;
    }
    
    //next, p and q cannot be equal
    
    if(p==q) {
        cout << "Public key not valid!";
        return 0;
    }
    
    //we need to check if p and q are coprime
    if(__gcd(p, q)!=1) {
        cout << "Public key not valid!";
        return 0;
    }
    //we can calculate d as well
    //bruteforcey way rn 
    // 3k%phi =1, we need to find some value k 
    
    int d = 1;
    while(e*d%phi!=1){
        ++d;
    }
    
    

    
    //now lets start the decryption
    // plaintext = ciphertext^d % mod n
    
    vector<int>decrypted;
    
    for(int i = 0; i<c_len; ++i) {
        decrypted.push_back(decrypt(c.at(i),d,n)); //decrypts all inputs
    }
    
    
    if(p>q){
        int temp = q;
        q = p;
        p = temp;
    }
    
    cout << p << " " << q << " " << phi << " " << d << endl;
    
    for(int i = 0; i<c.size(); i++) { 
        cout << decrypted.at(i);
        if(i!=c.size()-1) {
            cout << " ";
        }
    }
    
    cout << endl << toReadableText(decrypted) << endl;
    
    return 0;
}